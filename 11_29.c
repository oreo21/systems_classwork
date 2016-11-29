#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

int main(){
	int *a;
	int status;
	int sd;

	sd = shmget(24601, sizeof(int), IPC_CREAT | 0644);
	printf("sd: %d\n", sd);

	int f = fork();
	if (f == 0){
		a = shmat(sd, 0, 0);
		*a = 54;
		printf("child says: %p\n", a);
		printf("child says: %d\n", *a);
	}
	else {
		wait(&status);
		a = shmat(sd, 0, 0);
		printf("parent says: %p\n", a);
		printf("parent says: %d\n", *a);
	}
	return 0;
}