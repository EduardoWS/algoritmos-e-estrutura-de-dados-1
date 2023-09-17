CC = gcc
CFLAGS = -Wall
programa = main

main: main.c pilha.c pilha.h
	$(CC) $(CFLAGS) -o $(programa) main.c pilha.c

clean:
	rm $(programa)

exec:
	$(CC) $(CFLAGS) -o $(programa) main.c pilha.c
	./$(programa)