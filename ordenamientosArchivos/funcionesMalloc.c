#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE* abrirArchivo( char path[], char modo[] ){
	if ( path != NULL ) {
		FILE* pFile = fopen( path, modo );
		return pFile;
	} else
		printf("No se pudo abrir correctamente el archivo");
	return NULL;	
}

void burbuja( int arreglo[] , int tam ){
	int i=0,j=0,cantI=0,cantC=0;
	while( j<=tam ){
		for( i=0;i<(tam-1);i++ ){
			cantC++;
			if( arreglo[i]>arreglo[i+1] ){
				cantI++;
				int y = arreglo[i];
				arreglo[i] = arreglo[i+1];
				arreglo[i+1] = y;
			}
		} j++;
	} printf( "%d Intercambios y %d Comparaciones.\n" , cantI , cantC );
}

void insercion( int lista[], int tam ){
	int i, j, temporal, cantI=0, cantC=0;
	for( i=0;i<tam;i++ ){
		j = i;
		temporal = lista[i];
		while( j>0 && temporal<lista[j-1] ){
			cantC++; cantI++;
			lista[j] = lista[j-1];
			j--;
		} cantC++; lista[j] = temporal;
	} printf( "%d Intercambios y %d Comparaciones.\n" , cantI , cantC );
}

void quickSort( int lista[], int limiteIzq, int limiteDer ){
	int izq , der , temporal , pivote, cantI=0, cantC=0;
	izq = limiteIzq; der = limiteDer;
	pivote = lista[(izq+der)/2];
	do{
		while( lista[izq]<pivote && izq<limiteDer ){
			izq++; cantC++;
		} while( pivote<lista[der] && der>limiteIzq ){
			der--; cantC++;
		} if( izq <= der ){
			temporal = lista[izq];
			lista[izq] = lista[der];
			lista[der] = temporal;
			izq++; der--; cantI++;
		}
	} while( izq <= der );
	if( limiteIzq < der ) quickSort( lista, limiteIzq, der );
	if( limiteDer > izq ) quickSort( lista, izq, limiteDer );
	char modo[] = "a", path[] = "listado.txt";
	FILE* pFile = abrirArchivo( path , modo );
	if( pFile!=NULL ){
		fprintf( pFile , "%d\n" , cantC );
		fclose( pFile );
	}
}

int rellenar( int numero ){
	if( numero<=1 )
		return 1;
	else
		return 1 + rellenar( numero-1 );
}

void crearArchivoFPrint( FILE* pFile , int lista[] , int prueba, int tam ){
	int cont = 0, numero=tam, ingresar;
	if ( prueba == 0 ){
		while ( cont<tam ) {
			ingresar = rellenar( numero );
			fprintf( pFile , "%d\n" , ingresar );
			numero--; cont++;
		}
	} if( prueba == 1 ){
		while ( cont<(tam*25) ) {
			numero = lista[cont];
			fprintf( pFile , "%d\n" , numero );
			cont++;
		}
	}
}

void crearArchivo( char path[] , int lista[] , int prueba, int tam ){
	if( prueba == 0 ){
		int i=0;
		char modo[] = "w";
		FILE* pFile = abrirArchivo( path , modo );
		if( pFile!=NULL ){
			crearArchivoFPrint( pFile , lista , prueba , tam );
			printf( "Creando archivo.\n" );
			fclose( pFile );
		} while( i<24 ){
			char modo[] = "a";
			FILE* pFile = abrirArchivo( path , modo );
			if( pFile!=NULL ){
				crearArchivoFPrint( pFile , lista , prueba , tam );
				printf( "Creando archivo.\n" );
				fclose( pFile );
			} i++;
		}
	} if( prueba == 1 ){
		int i=0;
		char modo[] = "w";
		FILE* pFile = abrirArchivo( path , modo );
		if( pFile!=NULL ){
			crearArchivoFPrint( pFile , lista , prueba , tam );
			printf( "Creando archivo.\n" );
			fclose( pFile );
		}
	}
}

void leerArchivoFScanf( FILE* pFile, int lista[] ){
	int i=0;
	rewind( pFile );
	while ( !feof( pFile ) ){
		fscanf( pFile, "%d\n", &lista[i]);
		i++;
	}
}

void leerArchivo( char path[] , int lista[] ){
	FILE* pFile = abrirArchivo( path, "r" );
	if( pFile!=NULL ){
		leerArchivoFScanf( pFile , lista );
		printf( "Leyendo archivo.\n" );
		fclose( pFile );
	}
}