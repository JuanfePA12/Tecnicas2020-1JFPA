#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void qS( int lista[], int limiteIzq, int limiteDer ){
	int izq , der , temporal , pivote;
	izq = limiteIzq; der = limiteDer;
	pivote = lista[(izq+der)/2];
	do{
		while( lista[izq]<pivote && izq<limiteDer ) izq++;
		while( pivote<lista[der] && der>limiteIzq ) der--;
		if( izq <= der ){
			temporal = lista[izq];
			lista[izq] = lista[der];
			lista[der] = temporal;
			izq++; der--;
		}
	} while( izq <= der );
	if( limiteIzq < der ) qS( lista, limiteIzq, der );
	if( limiteDer > izq ) qS( lista, izq, limiteDer );
}

void quickSort( int lista[], int n ){
	qS( lista, 0, n-1 );
}

int main(){
	int lista[] = {4,5,7,0,1,2,6,3}, i;
	int tam = sizeof( lista )/sizeof( int );
	printf( "\nLista desordenada\n" );
	for( i=0;i<tam;i++ )
		printf( "%d " , lista[i] );
	printf( "\n" );
	quickSort( lista, tam );
	printf( "Lista ordenada\n" );
	for( i=0;i<tam;i++ )
		printf( "%d " , lista[i] );
	printf( "\n" );
	return 0;
}