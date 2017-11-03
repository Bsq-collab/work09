#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include <dirent.h>

int main(){
  DIR * d;
  d = opendir(".");
  struct dirent * entry;
  entry=readdir(d);
  if(d==NULL){
    printf("directory is null...");
    return 0;
  }
  printf("printing list of all files..............\n");
  int size=0;
  while(entry=readdir(d)){
    if(entry->d_type==DT_REG){
      printf("REG FILE: %s\n",entry->d_name);
      struct stat b;
      stat(entry->d_name,&b);
      size+=(int)(b.st_size);
    }
    else if(entry->d_type==DT_DIR){
      printf("DIRECTORY: %s\n",entry->d_name);
    }
  }
  printf("size: %d\n",size);

  closedir(d);
  return 0;
}
