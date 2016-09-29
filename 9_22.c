#include <stdio.h>
#include <stdlib.h>

void foo(int *);

int main(){
  int i = 4;
  foo(&i);
  printf("i: %d\n", i);
  return 0;
}

void foo(int *n){
  while (*n){
    printf("foo!\n");
    (*n)--;
  }
  printf("n: %d\n", *n);
}
