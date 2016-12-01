#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

int main(){
  int *a;
  int sd;

  sd = shmget(24601, 4, 0);
  printf("sd: %d\n", sd);
  a = shmat(sd, 0, 0);

  *a = 9879;
  printf("other: %p\n", a);
  printf("other: %d\n", *a);
  shmdt(a);
  printf("other: %p\n", a);
  
  struct shmid_ds d;
  shmctl(sd, IPC_STAT, &d);
  printf("shmem size: %d\n", d.shm_segsz);
  shmctl(sd, IPC_RMID, 0);
  return 0;
}
