#include "headers.h"
#include "function.h"

void pwd_c()
{
    char* buff;
    buff = (char*)malloc(1023*sizeof(char));
    getcwd(buff, 1023);
    printf("%s\n",buff);
    free(buff);
}