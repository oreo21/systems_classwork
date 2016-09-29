#include <stdio.h>
#include <stdlib.h>

int main(){
  int s = 5;
  double darr[5];
  short *sp = &s;
  darr[0] = 3.7;
  darr[1]= 3.14;
  darr[2] = 20.4;
  double *dp = darr;
  //short *sp; //designed to story a memory address, not a short
  //sp = s would make sp 5
  //sp = &s; 
  printf("size of darr: %lu\n", sizeof(s));
  printf("value of darr: %p\n", darr);
  printf("address of darr: %p\n", &darr);

  /* printf("size of sp: %lu\n", sizeof(sp));
  printf("value of sp: %lu\n", sp);
  printf("address of sp: %lu\n", &sp);
  */
}
