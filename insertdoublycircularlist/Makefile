all: main

main: main.o doublynode.o
	gcc -o main main.o doublynode.o

main.o: main.c doublynode.h
	gcc -c main.c

doublynode.o: doublynode.c doublynode.h
	gcc -c doublynode.c

clean:
	rm -f *.o main
