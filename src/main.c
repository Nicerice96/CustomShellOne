#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 64

// Parse input line into arguments
int parseInput(char *line, char **args) {
    int i = 0;
    char *token = strtok(line, " \t\n");
    
    while(token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;  // NULL-terminate the array
    return i;
}

void shellLoop(char **line, size_t *len) {
    while(1) {
        printf("mysh> ");
        fflush(stdout);
        
        if(getline(line, len, stdin) == -1) {
            printf("\n");
            break;
        }
        
        // Remove newline
        (*line)[strcspn(*line, "\n")] = '\0';
        
        // Skip empty input
        if(strlen(*line) == 0) {
            continue;
        }
        
        // Parse the input into arguments
        char *args[MAX_ARGS];
        int arg_count = parseInput(*line, args);
        
        if(arg_count == 0) {
            continue;
        }
        
        // Handle built-in commands (run in parent, not child)
        if(strcmp(args[0], "exit") == 0) {
            break;
        }
        else if(strcmp(args[0], "cd") == 0) {
            // cd must run in parent process to change shell's directory
            if(arg_count < 2) {
                fprintf(stderr, "cd: missing argument\n");
            } else {
                if(chdir(args[1]) != 0) {
                    perror("cd");
                }
            }
            continue;  // Don't fork for built-ins
        }
        
        // Fork for external commands
        pid_t pid = fork();
        
        if(pid == -1) {
            perror("fork");
            continue;
        }
        else if(pid == 0) {
            // CHILD PROCESS: Execute external command
            if(execvp(args[0], args) == -1) {
                perror(args[0]);
            }
            exit(EXIT_FAILURE);  // Exit if exec fails
        }
        else {
            // PARENT PROCESS: Wait for child
            int status;
            waitpid(pid, &status, 0);
        }
    }
}

int main() {
    char *line = NULL;
    size_t len = 0;
    
    shellLoop(&line, &len);
    
    // Cleanup
    free(line);
    
    return 0;
}