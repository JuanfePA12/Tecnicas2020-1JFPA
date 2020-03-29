all: programa
programa: Main Virtual
	gcc -o Virtual Main.o Virtual.o
	Virtual.exe
Main: Main.c Virtual.h
	gcc -c Main.c
Virtual: Virtual.c Virtual.h
	gcc -c Virtual.c