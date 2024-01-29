.DEFAULT_GOAL := all
.PHONY: all

all: my_str

my_str: strlen.o strlower.o strupper.o main.o
	gcc -o my_str strlen.o strlower.o strupper.o main.o

main.o: main.c
	gcc -o main.o -c main.c

strlen.o: strlen.c
	gcc -o strlen.o -c strlen.c

strlower.o: strlower.c
	gcc -o strlower.o -c strlower.c

strupper.o: strupper.c
	gcc -o strupper.o -c strupper.c

