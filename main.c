#include "headers.h"
#include "function.h"

int takeinput(char* str)
{
	fgets(str, 1023, stdin);
	int len = strlen(str);
	str[len - 1] = NULL;
	if(strlen(str) != 0)
		return 0;
	else
		return 1;		
	
}

int main()
{
	char input[1023];
    while(1)
    {
        prompt();
		  current_dir();
        if(takeinput(input))
		  	continue;
		else{	
			history_Setup();
			 history_save(input);
			if(processstring(input))
				break;		
		}
    }
	return 0;
}