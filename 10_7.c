#include <stdio.h>
#include <stdlib.h>

int main(){
	int *p;
	p = (int *)malloc(5 * sizeof(int)); //calloc(5, sizeof(int))
	p[0] = 97426;
	printf("p[0]: %d\n", p[0]);

	int *np = p;
	p++;
	free(np);

	struct foo {int x; char a;};
	struct foo *s;
	s = (struct foo*)malloc(sizeof(struct foo));
	printf("size of s: %lu\n", sizeof(s));

	(*s).x = 12345;
	printf("s->x: %d\n", s->x);
	return 0;
}
