CFLAGS = -Wall -g -fms-extensions -std=c99 -lm
INCLUDE = -Isrc
SRC=$(wildcard src/*.c)
HEADERS=$(wildcard src/*.h)
MAIN_SRC = $(SRC) main.c
MENORCAMINHO_SRC = $(SRC) tests/menorcaminho.c

a: $(HEADERS) $(MAIN_SRC) ; gcc $(INCLUDE) -o $@ $^ $(CFLAGS)
menorcaminho: $(HEADERS) $(MENORCAMINHO_SRC) ; gcc $(INCLUDE) -o $@ $^ $(CFLAGS)
