#include<iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include<string>
#include<string>
#include<cstring>
#include<string.h>
#include<vector>
using namespace std;
vector<pair<vector<string>,string> retunrDir(string s,mode_t mode){
    vector<string>ans;
    int i=0;    int j=i+1;
    while (i<j && (j<s.size())){
        if (s[j]=='/' || s[j]=='\0' || j==s.size()-1){
            string flag;
            if (j==s.size()-1){
                flag=s.substr(0,j+1);
            } else {
            flag=s.substr(0,j);}
            //cout<<flag<<i<<j<<'\t';
            
            i=j+1;
            j=i+1;
            ans.push_back(flag);
            /*const char *filePath=flag.c_str();
            int check=mkdir(filePath,mode);
        if (!check){
            printf("folder Created");
        }   else {
            perror("Something Went Wrong");
            
        }   */         
        }   else {
            j++;
        }
    }   
    for (auto x:ans){
        cout<<x<<'\t';
    }   cout<<'\n';
    
    return;
}
int main(int argc,char** argv){
    struct stat sb;
    if (argc!=3){
        perror("Expects 2 arguments File Path,File Name\n");
        return 1;
    } else {
        string s=string(argv[1]);
        if (stat(s.c_str(),&sb)==-1){
            perror("Error in checking : ");
        }        
        retunrDir(s,0777);
        char* fileContent=argv[2];
    }   return 0;
}