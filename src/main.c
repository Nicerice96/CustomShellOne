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


        //Forking part which I don't understand yet...
    }

}

int main(){

    char *line = NULL;
    size_t len = 0;

    shellLoop(&line, &len);


    
}