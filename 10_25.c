#include <stdio.h>
#include <stdlib.h>
#include <fnctl.h>
#include <errno.h>

void main(){
  int filedesc = open("test.txt", O_CREAT, 0777);
  printf("filedesc: %d\n", filedesc);
  if (filedesc == -1)
    printf("error: %d - %s\n", errno, strerror(errno));  
}
