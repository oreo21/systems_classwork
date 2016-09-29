#include <stdio.h>
#include <stdlib.h>

int main(){
  char tars[15];
  tars[0] = 'a';
  tars[1] = 'b';
  tars[2] = 'c';
  tars[3] = 0;
  tars[1]--;
  printf("tars: %s\n", tars);
  printf("sizeof tars: %lu\n", sizeof(tars));

  char s2[] = "hello";
  printf("s2: %s\n", s2);
  printf("sizeof s2: %lu\n", sizeof(s2));
  s2[0] = 'j';
  printf("s2: %s\n", s2);
  return 0;
}
