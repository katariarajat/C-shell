void prompt();

void cmd_handle(char* a);

void current_dir();

int processstring(char* input);

void history_save(char* input);

void history_show();

void cd_c(char* input,char** par,int i);

void pwd_c();

void listfiles(char* input,char** par,int i);

void echo_c(char* input,int l);

void excep_c(char** input,int l);

void retrieve_Stored();

void history_save(char* cmd);

void write_history();

void history_display(char* input);

void history_Setup();

//int pinfo(char** cmd_tokens)
