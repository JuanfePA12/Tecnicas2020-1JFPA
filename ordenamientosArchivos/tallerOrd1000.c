#include "funciones.c"
#define MAX 1000

int main(){
	printf( "\n" );
	int lista[MAX] = {0};
	char path[] = "1000elementos.txt";
	char path1[] = "1000elementosOrdenados.txt";
	crearArchivo( path , lista , 0 , MAX );
	leerArchivo( path , lista );
	insercion( lista , MAX );
	crearArchivo( path1 , lista , 1 , MAX );
}