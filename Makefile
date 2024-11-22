CC = gcc

ifeq ($(OS),Windows_NT)
	CFLAGS = -lraylib -lwinmm -lGdi32
else
	CFLAGS = -lrayliblinux -lm
endif

LIB = lib
INCLUDE = include
OUTPUT = bin/out

out: main.o text.o checkbox.o general.o do.o
	$(CC) main.o text.o checkbox.o general.o do.o -L$(LIB) $(CFLAGS) -o $(OUTPUT)

main.o: src/main.c
	$(CC) src/main.c -I$(INCLUDE) -c

text.o: src/graphics/objects/text.c
	$(CC) src/graphics/objects/text.c -I$(INCLUDE) -c

checkbox.o: src/graphics/objects/checkbox.c
	$(CC) src/graphics/objects/checkbox.c -I$(INCLUDE) -c

general.o: src/graphics/general.c
	$(CC) src/graphics/general.c -I$(INCLUDE) -c

do.o: src/graphics/objects/do.c
	$(CC) src/graphics/objects/do.c -I$(INCLUDE) -c

clean:
	rm *.o
