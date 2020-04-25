#include <stdio.h>
#include <string.h>

int factorialR( int numero ){
	if ( numero<=1 )
		return 1;
	else
		return numero * factorialR( numero-1 );
}

int factorialI( int numero ){
	int producto = 1, i;
	for( i=0;i<numero;i++ )
		producto = producto * (i+1);
	return producto;
}

int main(){
	int fac;
	printf( "\nIngrese un numero: " );
	fflush( stdin );
	scanf( "%d" , &fac );
	printf( "\nEl factorial de %d es %d\n" , fac , factorialR( fac ) );
	return 0;
}