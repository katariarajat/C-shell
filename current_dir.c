#include "headers.h"
#include "function.h"

void current_dir()
{
    char* buff;
    buff = (char*)malloc(1023*sizeof(char));
    getcwd(buff,1023);
    char* homedir = getenv("HOME");
    int len = strlen(homedir),lena = strlen(buff);
    int f = 1;
    for (size_t i = 0; i < len; i++)
    {
        if(buff[i]!=homedir[i])
        {
            f = 0;
            break;
        }
    }
    if(f == 1)
    {
        printf("~");
        for(int i = len;i<lena;i++)
            printf("%c",buff[i]);
    }
    else
        printf("%s",buff);
    printf(">");
    
    free(buff);
    // free(homedir);
}