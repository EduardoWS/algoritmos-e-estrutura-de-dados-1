CC = gcc
CFLAGS = -Wall -O2
programa = main

main: main.c conjuntos.c conjuntos.h
	$(CC) $(CFLAGS) -o $(programa) main.c conjuntos.c

clean:
	rm *.o $(programa)

exec:
	$(CC) $(CFLAGS) -o $(programa) main.c conjuntos.c
	./$(programa)