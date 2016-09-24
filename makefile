CFLAGS = -Wall -g -fms-extensions -std=c99 -lm
INCLUDE = -Isrc
SRC=$(wildcard src/*.c)
HEADERS=$(wildcard src/*.h)
MAIN_SRC = $(SRC) main.c

a: $(HEADERS) $(MAIN_SRC) ; gcc $(INCLUDE) -o $@ $^ $(CFLAGS)
