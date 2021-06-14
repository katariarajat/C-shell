#include "headers.h"
#include "function.h"

void execvp_c(char** par,int l){
    char **command = malloc(10*sizeof(char*));
    
    if(command == NULL)
    {
        perror("malloc failed");
        exit(1);
    }

    char* separator = " ";
    int i = 0,stat_loc;
    for(i = 0;i < l;i++)
    {
        command[i] = par[i];
    }
    command[i] = NULL;
    int child_pid = fork();
    if(child_pid < 0)
    {
        perror("Fork failed");
    }
    if(child_pid == 0)
    {
        if(execvp(command[0],command) < 0)
        {
                perror(command[0]);
                exit(1);
        }
    }
    else
    {
        waitpid(child_pid,&stat_loc,WUNTRACED);
    }
    
    free(command);
    return;
}
