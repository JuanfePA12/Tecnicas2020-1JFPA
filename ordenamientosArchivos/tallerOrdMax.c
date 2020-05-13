#include "funcionesMalloc.c"
#define MAX 40000

int main(){
	printf( "\n" );
	int *pLista; pLista = malloc( (MAX*25) * sizeof( int ) );
	char path[] = "maxElementos.txt";
	char path1[] = "maxElementosOrdenados.txt";
	crearArchivo( path , pLista , 0 , MAX );
	leerArchivo( path , pLista );
	quickSort( pLista , 0 , (MAX*25)-1 );
	crearArchivo( path1 , pLista , 1 , MAX );
	return 0;
}