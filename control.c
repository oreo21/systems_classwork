#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>

union semun {
  int val; 
  struct semid_ds *buf; 
  unsigned short *array;
  struct seminfo *__buf;
};

struct sembuf { //you don't need to declare this
  short sem_op;
  short sem_num;
  short sem_flag;
}

 int main(int argc, char* argv[]){
  int semid;
  int key = ftok("control.c", 22);
  int sc;

  if (strncmp(argv[1], "-c", strlen(argv[1])) == 0){
    semid = semget(key, 1, IPC_CREAT | 0644);
    printf("semaphore created: %d\n", semid);

    union semun su; //8 bytes, for val only looks at upper/lower 4
    su.val = 1;
    sc = semctl(semid, 0, SETVAL, su);
    printf("value set: %d\n", sc);
  }

  else if (strncmp(argv[1], "-v", strlen(argv[1])) == 0){
    semid = semget(key, 1, 0);
    sc = semctl(semid, 0, GETVAL);
    printf("semaphore value: %d\n", sc);
  }

  else if (strncmp(argv[1], "-r", strlen(argv[1])) == 0){
    semid = semget(key, 1, 0);
    sc = semctl(semid, 0, IPC_RMID);
    printf("semaphore removed: %d\n", sc);
  }
  
  return 0;
}
