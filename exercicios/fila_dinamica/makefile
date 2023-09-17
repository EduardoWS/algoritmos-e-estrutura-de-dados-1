CC = gcc
CFLAGS = -Wall
programa = main

main: main.c fila.c fila.h
	$(CC) $(CFLAGS) -o $(programa) main.c fila.c

clean:
	rm $(programa)

exec:
	$(CC) $(CFLAGS) -o $(programa) main.c fila.c
	./$(programa)