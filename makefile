CFLAGS = -Wall -g -fms-extensions -std=c99 -lm
INCLUDE = -Iheaders
SRC=$(wildcard src/*.c)
HEADERS=$(wildcard headers/*.h)
MAIN_SRC = $(SRC) main.c

a: $(HEADERS) $(MAIN_SRC) ; gcc $(INCLUDE) -o $@ $^ $(CFLAGS)
