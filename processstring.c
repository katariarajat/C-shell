#include "headers.h"
#include "function.h"

int processstring(char input[])
{
    char* par[1023];
    char* token;
    char oristring[1023];
    strcpy(oristring, input);
    
    int i = 0;
    par[i] = strtok(input, " ");
    
    while(par[i]!=NULL)
    {
        i++;
        par[i] = strtok(NULL, " ");
    }

    int k = 0;
    char* listofcommands[7];
    
    listofcommands[0] = "exit";
    listofcommands[1] = "echo";
    listofcommands[2] = "ls";
    listofcommands[3] = "pwd";
    listofcommands[4] = "cd";
    listofcommands[5] = "history";
    listofcommands[6] = "pinfo";

    for (size_t j = 0; j < 6; j++)
    {
        if(strcmp(par[0], listofcommands[j]) == 0){
           k = j + 1; 
           break;
        }
    }
    switch (k)
    {
        case 1:
            return 1;
        case 2:{
            echo_c(oristring,i);
            break;
        }
            
        case 3:{
            listfiles(oristring, par,i);
            return 0;
        }
        case 4:{
            pwd_c();
            return 0;
        }
        case 5:{
            cd_c(oristring,par,i);
            return 0;
        }
        case 6:{
            history_display(par[1]);
            return 0;
        }
        // case 7;{
        //     pinfo(par);
        //     return 0;
        // }

        default:{
            execvp_c(par,i);
            return 0;
        }
    } 



    
}
