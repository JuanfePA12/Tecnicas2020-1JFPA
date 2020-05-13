#include "funciones.c"
#define MAX 100

int main(){
	printf( "\n" );
	int lista[MAX] = {0};
	char path[] = "100elementos.txt";
	char path1[] = "100elementosOrdenados.txt";
	crearArchivo( path , lista , 0 , MAX );
	leerArchivo( path , lista );
	insercion( lista , MAX );
	crearArchivo( path1 , lista , 1 , MAX );
	return 0;
}