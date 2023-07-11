CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: programa

programa: regDatosOpciones.o metodos.o estructuras.o
	$(CC) $(CFLAGS) -o programa regDatosOpciones.o metodos.o estructuras.o

regDatosOpciones.o: regDatosOpciones.c metodos.h estructuras.h
	$(CC) $(CFLAGS) -c regDatosOpciones.c

metodos.o: metodos.c metodos.h estructuras.h
	$(CC) $(CFLAGS) -c metodos.c

estructuras.o: estructuras.c estructuras.h
	$(CC) $(CFLAGS) -c estructuras.c

clean:
	rm -f programa *.o
