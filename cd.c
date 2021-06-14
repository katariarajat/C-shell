#include "headers.h"
#include "function.h"
 
void cd_c(char* input,char** par,int i)
{
    char* homedir = getenv("HOME");
    int r;
    char* a;
    a = (char*)malloc(1023*sizeof(char));
    if(par[1] == NULL || !strcmp(par[1], "~"))
        r = chdir(homedir);
    else
    {
        for(int i=1;par[i]!=NULL;i++)
        {
            int len = strlen(par[i]);
            if(par[i][len-1] == 92)
            {
                par[i][len-1] = NULL;
                strcat(a, par[i]);
                strcat(a, " ");
            }
            
            else
            {
                strcat(a, par[i]);
            }
        }
        r = chdir(a);
    }
    if(r<0)
        perror("chdir()");
    free(a);
}