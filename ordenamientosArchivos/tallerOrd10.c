#include "funciones.c"
#define MAX 10

int main(){
	printf( "\n" );
	int lista[MAX] = {0};
	char path[] = "10elementos.txt";
	char path1[] = "10elementosOrdenados.txt";
	crearArchivo( path , lista , 0 , MAX );
	leerArchivo( path , lista );
	quickSort( lista , 0 , MAX-1 );
	crearArchivo( path1 , lista , 1 , MAX );
	return 0;
}