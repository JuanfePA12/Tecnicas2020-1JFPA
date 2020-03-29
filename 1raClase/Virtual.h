#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct persona{
	char nombre[20];
	int dia;
	int mes;
	int anio;
} persona;

typedef enum suerte{
    ENERO=1 , FEBRERO=2 , MARZO=3 , ABRIL=4 , MAYO=5 , JUNIO=6 , JULIO=7 , AGOSTO=8 , SEPTIEMBRE=9 , OCTUBRE=10 , NOVIEMBRE=11 , DICIEMBRE=12
} suerte;

void agregarDia( persona lista[][MAX], int mes, int dispo[] );

void agregarAnio( persona lista[][MAX], int mes, int dispo[] );

void agregarUsuario( persona lista[12][MAX], int dispo[] );

void numeroSuerte( persona lista[12][MAX] );

void mostrarCumpleanios( persona lista[12][MAX], int dispo[] );

int sumaEdades( persona lista[12][MAX], int dispo[], int perAct, int mes );

void promedioEdades( persona lista[12][MAX], int dispo[] );

void mostrarMenu();