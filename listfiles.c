#include "headers.h"
#include "function.h"

void listfiles(char* input,char** par,int l)
{

    char* buff[50];
    // for(int i = 0;i<50;i++)
    // {
    //     buff[i] = (char*)malloc(1023*sizeof(char));
    //     getcwd(buff[i], 1023);
    //     printf("%s\n   %d ",buff[i],i);
    // }

    char* homedir = getenv("HOME");
    
    char* path;
    path = (char*)malloc(1023*sizeof(char));
     getcwd(path,1023);
    
    int f = 0;
    
    char p[100],ori[100];
    
    int e = 0;

    int len = strlen(path);

    for(int i = len-1;path[i]!= 47;i--)
    {
        p[e++] = path[i];
    }

    p[e]=NULL;
    int i;
    for(i = 0;i<e;i++)
    {
        ori[i] = p[e-1-i];
    }
    ori[i] = NULL;

    char* listcmp[10];
    listcmp[0] = NULL;
    listcmp[1] = "~";
    listcmp[2] = "..";
    listcmp[3] = "-l";
    listcmp[4] = "-a";
    listcmp[5] = "-al";
    listcmp[6] = "-la";
    listcmp[7] = ".";
    
    int s = 0,h = 1;
    int u = 0 ,v = 0,w = 0;
    int lena = strlen(homedir);
    for(int j = 1;j<l;j++)
    {
        f = 0;h = 1;
        for(int i = 1;i<=7;i++)
        {
            if( strcmp(par[j],listcmp[i]) == 0)
            {
                switch (i+1)
                {
                case 1:{
                    buff[s] = (char*)malloc((lena+100)*sizeof(char));
                    strcpy(buff[s++], homedir);
                    break;
                }
                case 2:{
                    buff[s] = (char*)malloc((lena+100)*sizeof(char));
                     strcpy(buff[s++], homedir);
                     break;
                }
                case 3:{
                    buff[s] = (char*)malloc((104 + len)*sizeof(char));
                    strcpy(buff[s], path);
                    
                    strcat(buff[s++], "/..");
                    break;
                }
                case 4:{
                    v = 1;
                    break;
                }
                case 5:{
                    u = 1;
                    break;
                }
                case 6:{
                    v = 1;u = 1;break;
                }
                case 7:{
                    v = 1;u = 1;break;
                }
                case 8:{
                    buff[s] = (char*)malloc((105 + strlen(ori) + len)*sizeof(char));
                    strcpy(buff[s], path);
                    strcat(buff[s],"/../");
                    strcat(buff[s], ori);
                    s++;
                }
                }
                f = 1;
            }
        }
        if( f == 0)
        {
            printf("%d\n",getpid());

            buff[s] = (char*)malloc((len + 102 + strlen(par[j]))*sizeof(char));
            strcpy(buff[s], path);
            strcat(buff[s], "/");
            strcat(buff[s], par[j]);
            s++;
        }
    }
    
    if(s == 0)
    {
        buff[s] = (char*)malloc(((strlen(ori) + 105 + len))*sizeof(char));
        strcpy(buff[s], path);
        strcat(buff[s],"/../");
        strcat(buff[s], ori);
        s++;
    }

    // for(int i = 0;i<s;i++)
    // {
    //     printf("%s\n",buff[i]);
    // }

    for(int i = 0;i<s;i++)
    {
        struct dirent *dp;
        DIR *dir = opendir(buff[i]);
        // Unable to open directory stream
  //      if(s>0)
//        printf("%s :\n",buff[i]);
        
        if (!dir) 
        {   
            perror("opendir()");
            return; 
        }
        if(v == 0)
        {
              char g[1023];

            while ((dp = readdir(dir)) != NULL)
            {
                strcpy(g, dp->d_name);
                if(u == 1) 
                    printf("%s\n", dp->d_name);
                else
                {
                    if(g[0] != 46) 
                        printf("%s\n", dp->d_name);
                }
            }
        }
        else
        {
            char g[1023];

            while ((dp = readdir(dir)) != NULL)
            {
                strcpy(g, dp->d_name);
                struct stat fileStat;
                char* parr;
                parr = (char*)malloc((strlen(buff[i])+ 3 + strlen(g))*sizeof(char));
                strcpy(parr, buff[i]);

                strcat(parr, "/");
                strcat(parr, g);
                if(stat(parr, &fileStat) < 0){}                

                if(u == 1)
                {
                    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
                    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
                    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
                    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
                    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
                    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
                    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
                    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
                    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
                    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
                    printf(" ");
                    printf("%d ",fileStat.st_nlink);

                    struct passwd *pw = getpwuid(fileStat.st_uid);
                    struct group  *gr = getgrgid(fileStat.st_gid);
                    
                    if(pw != 0)
                        printf("%s ",pw->pw_name);
                    if(gr != 0)
                        printf("%s ",gr->gr_name);

                    printf("%d ",fileStat.st_size);
                    // printf("%s ",ctime(&fileStat.st_mtime));
         
                    char time[50];
                    strftime(time, 50, "%Y-%m-%d %H:%M:%S", localtime(&fileStat.st_mtime));
                    printf("%s ",time);    

                    printf("%s\n", dp->d_name); 
                } 
                else
                {
                    if(g[0] != 46) {
                        printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
                    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
                    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
                    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
                    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
                    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
                    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
                    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
                    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
                    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
                    printf(" ");
                    printf("%d ",fileStat.st_nlink);

                    struct passwd *pwd;
                    pwd = getpwuid(fileStat.st_uid);
                    struct group  *grp;
                    grp =  getgrgid(fileStat.st_gid);
                    
                    if(pwd != 0)
                        printf("%s ",pwd->pw_name);
                    if(grp != 0)
                        printf("%s ",grp->gr_name);

                    printf("%d ",fileStat.st_size);
                    // printf("%s ",ctime(&fileStat.st_mtime));
         
                    char time[50];
                    strftime(time, 50, "%Y-%m-%d %H:%M:%S", localtime(&fileStat.st_mtime));
                    printf("%s ",time);    

                    printf("%s\n", dp->d_name); 
                    }
                }
                free(parr);

            }
        }
        
    // Close directory stream
        if(i!=s-1)
            printf("\n\n");

        free(buff[i]);
        closedir(dir);
    }
    
    // printf("%d\n",getpid());
}
