#include "headers.h"
#include "function.h"
#define maxi 20
#define f(start,end,i) for(int i = start;i<=end;i++)
char* fileName;

char* stored_command[maxi];

int powa(int a,int b)
{
    int result = 1;
    for(int i =0 ;i<b;i++)
    {
        result = result*a;
    }
    return result;
}

void write_history();
int stored = 0;

void retrieve_Stored() {
    
    int fd = open(fileName, O_CREAT | O_RDONLY, S_IRWXU);
    // nevar use square brackets
    char* buf;
    buf = (char*)calloc(1000, 1);
    read(fd, buf, 1000);

    if (!(fd >= 0)) {
        perror("open_history() ");
        return;
    }

    stored = 0;

    char* ptr;
    ptr = strtok(buf, "\n");
    while (ptr) {
        
        if (!(strlen(ptr) == 0)) {
            stored_command[stored] = ptr;
            stored = stored + 1;
        }
        ptr = strtok(NULL, "\n");
    }

    close(fd);
}


void history_save(char* cmd) {
    if (stored > 0)
    {
        if(strcmp(stored_command[stored - 1], cmd) == 0) 
        return;
    }

    if (!(stored >= maxi)) {
        stored_command[stored] = cmd;
        stored = stored + 1;
    } else {
        f(0,maxi - 1,i)
         {
            stored_command[i] = stored_command[i + 1];
        }

        stored_command[maxi - 1] = cmd;
    }
    write_history();
}

void write_history() {

    int fd = open(fileName, O_TRUNC | O_WRONLY, S_IRWXU);

    if (!(fd >= 0)) {
        perror("Couldn't open history file while writing");
        return;
    }
    f(0,stored-1,i)
    {
        int len = strlen(stored_command[i]);
        int y = 1;
        write(fd, stored_command[i], len);
        write(fd, "\n", y);
    }
    close(fd);
}


void history_display(char* input) {

    int n = 0;
    if(input == NULL )
    {
        n = 10;
    }    
    else
    {
        for(int i=0;i<strlen(input);i++)
        {
            n+= (input[i]-48)*powa(10,strlen(input) - 1 - i);
        }
    }
    printf("%d\n",n);
    if(n>20)
    {
        n = 20;
    }    
    
    if(stored - n > 0)
    {
        f(stored - n,stored - 1,i){
            printf("%s\n", stored_command[i]);
        }
    }
    else
    {
        f(0,stored - 1,i) {
            printf("%s\n", stored_command[i]);
        }
    }
}

void history_Setup() {
 
    fileName = (char*)calloc(1000, 1);
    char* homedir = getenv("HOME");

    strcpy(fileName, homedir);
    strcat(fileName, "/history.txt");
    retrieve_Stored();
}
