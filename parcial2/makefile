all: programa
programa: Main Funciones
	gcc -o centroComercial Main.o FuncionesCC.o
	centroComercial.exe
Main: Main.c FuncionesCC.h
	gcc -c Main.c
Funciones: FuncionesCC.c FuncionesCC.h
	gcc -c FuncionesCC.c