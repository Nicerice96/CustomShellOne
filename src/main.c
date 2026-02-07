#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//Shell loop
//Input Parsing

void shellLoop(char **line, size_t *len){

    while(1){
        printf("mysh>");
        fflush(stdout);

        if(getline(line, len, stdin) == -1){
            break;
        }

        pid_t pid = fork();

        if(pid == 0){
            //CHILD PROCESS : Safe to execute here
            //This process will be replaced by the command

            line[strcspn(line, "\n")] = '\0';

            if(strcmp(line, "cd") == 0){
                //handle cd logic
            }
            else if(strcmp(line, "ls") == 0){
                //handle ls logic
            }
            else if(strcmp(line, "exit") == 0){
                break;
            }
            else{
                printf("ERR: Unknown command!");
            }
        }
        else{
            //PARENT PROCESS

            wait(NULL);
        }
    }

}

int main(){

    char *line = NULL;
    size_t len = 0;

    shellLoop(&line, &len);


    
}