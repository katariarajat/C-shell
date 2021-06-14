#include "function.h"
#include "headers.h"

void prompt()
{
    char* username;
    username = (char*)malloc(1000*sizeof(char));
    username = getenv("USER");
    char* hostname;
    hostname = (char*)malloc(1024*sizeof(char));
    gethostname(hostname,1023);
    printf("%s@", username);
    printf("%s:",hostname);
   	    
}
