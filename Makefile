CC = gcc
CFLAGS = -lraylib -lwinmm -lGdi32
LIB = lib
INCLUDE = include
OUTPUT = bin/out

out: main.o text.o checkbox.o general.o
	$(CC) main.o text.o checkbox.o general.o -L$(LIB) $(CFLAGS) -o $(OUTPUT)

main.o: src/main.c
	$(CC) src/main.c -I$(INCLUDE) -c

text.o: src/text.c
	$(CC) src/text.c -I$(INCLUDE) -c

checkbox.o: src/checkbox.c
	$(CC) src/checkbox.c -I$(INCLUDE) -c

general.o: src/general.c
	$(CC) src/general.c -I$(INCLUDE) -c

clean:
	rm *.o