LIB=./lib/tga/tga.c
MAIN=main.c
CC=gcc
FLAGS=-Wall

build:
	$(CC) $(FLAGS) $(MAIN) $(LIB) -o main
