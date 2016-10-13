GCC = gcc -g

all: list.o main.o
	$(GCC) list.o main.o -o ltest

list.o: list.c main.h
	$(GCC) -c list.c

main.o: main.c list.h
	$(GCC) -c main.c

clean:
	rm *.o
	rm *~
