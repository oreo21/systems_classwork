#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

void main(){
  int filedesc = open("test.txt", O_CREAT | O_APPEND, 0666);
  printf("filedesc: %d\n", filedesc);
  if (filedesc == -1)
    printf("error: %d - %s\n", errno, strerror(errno));  
}
