CC = gcc
LIB = lib
INCLUDE = include
BUILDPATH = bin
CFLAGS := -I$(INCLUDE) -L$(LIB)

ifeq ($(OS),Windows_NT)
	CFLAGS += -lraylib -lwinmm -lGdi32
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
        CFLAGS += -lrayliblinux -lm
    endif
    ifeq ($(UNAME_S),Darwin)
        CFLAGS += -lraylibmacos -lm
    endif
endif

out: src/main.c src/graphics/objects/text.c \
	src/graphics/objects/checkbox.c src/graphics/general.c\
	src/graphics/objects/do.c
	$(CC) $^ $(CFLAGS) -o $(BUILDPATH)/$@

.PHONY: clean
clean:
	rm -rf *.o

# TODO: refactor code gen. [.o folder??]