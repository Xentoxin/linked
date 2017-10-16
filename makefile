all: linky.c
	gcc linky.c -o linky

run: all
	./linky