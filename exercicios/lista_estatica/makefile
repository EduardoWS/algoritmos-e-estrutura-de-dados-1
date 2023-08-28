CC = gcc
CFLAGS = -Wall
programa = main

main: main.c lista.c lista.h
	$(CC) $(CFLAGS) -o $(programa) main.c lista.c

clean:
	rm $(programa)

exec:
	$(CC) $(CFLAGS) -o $(programa) main.c lista.c
	./$(programa)