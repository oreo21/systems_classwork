#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(){
	char text[100] = "i won't feed you";
	int f = fork();
	if (f == 0){
		strcpy(text, "feed me!");
		printf("child says: %s\n", text);
	}
	else {
		wait(&f);
		printf("parent says: %s\n", text);
	}
	return 0;
}