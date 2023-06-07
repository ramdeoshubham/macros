# Makefile for GNU make

CC = gcc

all: build-test

# do not use C89, see https://stackoverflow.com/a/2855148/9373031
build-%:
	$(CC) -ansi -std=c99 $*.c -o $*.out