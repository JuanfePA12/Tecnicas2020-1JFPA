#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insercion( int lista[], int tam ){
	int i, j, temporal;
	for( i=0;i<tam;i++ ){
		j = i;
		temporal = lista[i];
		while( j>0 && temporal<lista[j-1] ){
			lista[j] = lista[j-1];
			j--;
		} lista[j] = temporal;
	}
}

int main(){
	int lista[] = {2,5,3,1,4}, i;
	int tam = sizeof(lista)/sizeof(int);
	printf( "\nLista desordenada\n" );
	for( i=0;i<tam;i++)
		printf( "%d " , lista[i] );
	printf( "\n" );
	insercion( lista, tam );
	printf( "Lista ordenada\n" );
	for( i=0;i<tam;i++)
		printf( "%d " , lista[i] );
	printf( "\n" );
	return 0;
}