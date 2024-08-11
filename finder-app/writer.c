#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include<syslog.h>
#include <unistd.h>
#include <stdlib.h>
/*
int mkdir_recursive(const char *path,mode_t mode){    
    for (int i=0;i<sizeof(path);i++){
        for (int j=i+1;j<sizeof(path);j++){
            if (path[j]=='/' || path[j]=='\0'){
                char *f;
                for(int k=i;k<j;k++){
                    f+=path[i];
                    i=j;
                    j=i+1;
                    printf("%s\t",f);
                }
            }
        }
    }   return 0;
}*/
void printVector(char **argv){
    while (*argv){
        printf("%s\n",*argv);
        argv++;
    }   return;
}
int main(int argc,char **argv){
    //printVector(argv);
    if (argc!=3){
        printf("More or less args are passed");
        return 1;
    }   else {
        char *dir=argv[1];
        char *fileContent=argv[2];
        /*mode_t md=S_IRWXU | S_IRWXG | S_IRWXO;
        int flag=mkdir_recursive(dir,0777);
        int check=mkdir(dir,0777);
        if (!check){
            printf("folder Created");
        }   else {
            perror("Something Went Wrong");
            return 1;
        }*/
       int fd;
       size_t size=strlen(fileContent);
       fd=open(dir,O_WRONLY | O_CREAT | O_TRUNC, 0644);
       if (fd==-1){
       perror("Error :");
        return 1;
       }
         else {
        write(fd, fileContent, size);
        close(fd);
        return 0;
    }
    }

    
}   