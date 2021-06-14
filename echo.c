#include "headers.h"
#include "function.h"

void echo_c(char* input,int l)
{
    char* pare[100];
    for(int i=0;i<100;i++)
    {
        pare[i] = (char*)malloc(1023*sizeof(char));
    }
    int i = 0;
    char path[1023];
    int k = 0;
    int len = strlen(input);
    while(input[i] == ' ')
    {
        i++;
    }
    i+=5;
    // printf("%d\n",i);
    while(i<len)
    {
        path[k++] = input[i++];
        // printf("%s\n",path);
    }
    path[k] = '\0';
    // printf("%s\n",path);
    if(path[0] == '"' && path[k-1]!='"' )
    {
        printf("wrong command to print\n");
        return;
    }
        
    i = 0;
    // printf("%d",getpid());

    pare[i] = strtok(path, "\"");

    while(pare[i]!=NULL)
    {
        i++;
        pare[i] = strtok(NULL, "\"");
    }

    // printf("%d",getpid());
    char* ans;
    ans = (char*)malloc(1023*sizeof(char));
    int qa = 0;

    for(int j = 0;j<i;j++)
    {
        int lena = strlen(pare[j]);
        if(pare[j][lena-1] == 92)
        {
            for(int x=0;x<lena-1;x++)
            {
               ans[qa++] = pare[j][x];
            }
            ans[qa++] = '"';
        }
        else
        {
            strcat(ans, pare[j]);
        }
    }
    printf("%s\n",ans);
    free(ans);
    // for(int i = 0;i<100;i++)
    //     free(pare[i]);
    
    return;
}