#include "FuncionesCC.h"

void mostrarClasesDeLocales(){
	printf( "\nLos locales que usted puede encontrar son:\n" );
	printf( "1. Moda\n" );
	printf( "2. Mascotas\n" );
	printf( "3. Comida\n" );
	printf( "4. Tecnologia\n" );
	printf( "5. Hogar\n" );
	printf( "0. Otros\n" );
}

int* crearPisos(){
	int *piso;
	piso = malloc( sizeof( int ) );
	printf( "\nIndique la cantidad de pisos: " );
	fflush( stdin );
	scanf( "%d" , piso );
	return piso;
}

int* crearLocalesPorPiso(){
	int *localesPorPiso;
	localesPorPiso = malloc( sizeof( int ) );
	printf( "Indique la cantidad de locales por piso: " );
	fflush( stdin );
	scanf( "%d" , localesPorPiso );
	return localesPorPiso;
}

local** crearCentroComercial( int *pPiso , int *pLocalesPorPiso ) {
	int i=0;
	local **pMatriz;
	pMatriz = malloc( *pPiso * sizeof( local * ) );
	if( pMatriz != NULL ){
		for( i=0;i<*pPiso;i++ ){
			pMatriz[i] = malloc( *pLocalesPorPiso * sizeof( local ) );
			if( pMatriz[i] == NULL ){
				printf( "Error reservando memoria." );
				break;
			}
		}
	} else
		printf( "Error reservando memoria." );
	return pMatriz;
}

int** crearEstadoCentroComercial( int *pPiso , int *pLocalesPorPiso ){
	int i=0;
	int **pEstado = malloc( *pPiso * sizeof( int * ) );
	if( pEstado != NULL ){
		for( i=0;i<*pPiso;i++ ){
			pEstado[i] = malloc( *pLocalesPorPiso * sizeof( int ) );
			if( pEstado[i] == NULL ){
				printf( "Error reservando memoria." );
				break;
			}
		}
	} else
		printf( "Error reservando memoria." );
	return pEstado;
}

void guardarNuevoLocal( local **pMatriz , local *pLocal , int i , int j ){
	pMatriz[i][j] = *pLocal;
}

void crearNuevoLocal( local **pMatriz , int **pEstado , int *pPiso , int *pLocalesPorPiso ){
	int aprov = 0;
	do{
		int i, j;
		printf( "\nIndique el piso donde desea que se ubique el local: " );
		fflush( stdin );
		scanf( "%d" , &i );
		if( i<0 || i>=*pPiso ){
			printf( "\nEl piso ingresado no existe.\n" );
			break;
		} printf( "\nIndique el lugar en el piso para el local: " );
		fflush( stdin );
		scanf( "%d" , &j );
		if( i<0 || i>=*pLocalesPorPiso ){
			printf( "\nEl local ingresado no existe.\n" );
			break;
		} if( pEstado[i][j]==0 ){
			local tmpLocal;
			printf( "\nIngrese el nombre del local: " );
			fflush( stdin );
			scanf( "%20s" , &tmpLocal.nombre );
			mostrarClasesDeLocales();
			printf( "\nIngrese la clase del local (numero): " );
			fflush( stdin );
			scanf( "%d" , &tmpLocal.clase );
			tmpLocal.visitas = 0;
			guardarNuevoLocal( pMatriz , &tmpLocal , i , j );
			pEstado[i][j]++; aprov++;
		} else
			printf( "\nEl local seleccionado ya se encuentra ocupado. Intente nuevamente.\n" );
	} while( aprov == 0 );
}

void codificarClase( int tipo ){
	clase num; num = tipo;
	switch( num ){
		case Otros:
			printf( "\nClase: Otros" );
			break;
		case Moda:
			printf( "\nClase: Moda" );
			break;
		case Mascotas:
			printf( "\nClase: Mascotas" );
			break;
		case Comida:
			printf( "\nClase: Comida" );
			break;
		case Tecnologia:
			printf( "\nClase: Tecnologia" );
			break;
		case Hogar:
			printf( "\nClase: Hogar" );
			break;
		default:
			printf( "\nLa clase de local no se encuentra registrada." );
	}
}

void mostrarInformacionLocal( local **pMatriz , int *pPiso , int *pLocalesPorPiso , int **pEstado ){
	int i, j, aprov = 0;
	char buscarNombre[MAX];
	printf( "\nIngrese el nombre del local: " );
	fflush( stdin );
	scanf( "%20s" , &buscarNombre );
	for( i=0;i<*pPiso;i++ ){
		for( j=0;j<*pLocalesPorPiso;j++ ){
			if( strcmp( buscarNombre, pMatriz[i][j].nombre )==0 && pEstado[i][j]==1){
				printf( "\nNombre: %s" , pMatriz[i][j].nombre );
				printf( "\nCantidad de visitas: %d" , pMatriz[i][j].visitas );
				int clase = pMatriz[i][j].clase;
				codificarClase( clase );
				printf( "\n" );
				aprov++;
			}
		}
	} if( aprov == 0 )
		printf( "\nEl local no existe.\n" );
}

void eliminarLocal( local **pMatriz , int *pPiso , int *pLocalesPorPiso , int **pEstado ){
	int i, j, aprov = 0;
	char buscarNombre[MAX];
	printf( "\nIngrese el nombre del local: " );
	fflush( stdin );
	scanf( "%20s" , &buscarNombre );
	for( i=0;i<*pPiso;i++ ){
		for( j=0;j<*pLocalesPorPiso;j++ ){
			if( strcmp( buscarNombre, pMatriz[i][j].nombre )==0 && pEstado[i][j]==1){
				pEstado[i][j] = 0;
				printf( "\nEl local %s se encuentra extinto ahora.\n" , buscarNombre );
				aprov++;
			}
		}
	} if( aprov == 0 )
		printf( "\nEl local no existe.\n" );
}

void sumarVisitas( local **pMatriz , int i , int j ){
	pMatriz[i][j].visitas++;
	printf( "\nUna visita ha sido agregada.\n" );
	char respuesta[3];
	char si[3] = "si";
	printf( "Desea agregar otra visita (si o no): " );
	fflush( stdin );
	scanf( "%3s" , &respuesta );
	if( strcmp( respuesta , si ) == 0 )
		sumarVisitas( pMatriz , i , j );
}

void agregarVisitas( local **pMatriz , int *pPiso , int *pLocalesPorPiso , int **pEstado ){
	int i, j, aprov = 0;
	char buscarNombre[MAX];
	printf( "\nIngrese el nombre del local: " );
	fflush( stdin );
	scanf( "%20s" , &buscarNombre );
	for( i=0;i<*pPiso;i++ ){
		for( j=0;j<*pLocalesPorPiso;j++ ){
			if( strcmp( buscarNombre, pMatriz[i][j].nombre )==0 && pEstado[i][j]==1){
				sumarVisitas( pMatriz , i , j );
				aprov++;
			}
		}
	} if( aprov == 0 )
		printf( "\nEl local no existe.\n" );
}

void recomendarLocales( local **pMatriz , int *pPiso , int *pLocalesPorPiso , int **pEstado ){
	int tipo, i, j;
	mostrarClasesDeLocales();
	printf( "\nDigita tu opcion para conocer nuestras recomendaciones: " );
	fflush( stdin );
	scanf( "%d" , &tipo );
	printf( "\nTe recomendamos visitar\n" );
	for( i=0;i<*pPiso;i++ ){
		for( j=0;j<*pLocalesPorPiso;j++ ){
			if( pMatriz[i][j].clase==tipo &&  pEstado[i][j]==1 )
				printf( "\n%s" , pMatriz[i][j].nombre );
		}
	} printf( "\n" );
}

void modificarLocal( local **pMatriz , int *pPiso , int *pLocalesPorPiso , int **pEstado ){
	int i, j, aprov = 0;
	char buscarNombre[MAX];
	printf( "\nIngrese el nombre del local: " );
	fflush( stdin );
	scanf( "%20s" , &buscarNombre );
	for( i=0;i<*pPiso;i++ ){
		for( j=0;j<*pLocalesPorPiso;j++ ){
			if( strcmp( buscarNombre, pMatriz[i][j].nombre )==0 && pEstado[i][j]==1){
				printf( "\nNombre actual: %s" , pMatriz[i][j].nombre );
				printf( "\nNuevo nombre: " );
				fflush( stdin );
				scanf( "%20s" , &pMatriz[i][j].nombre );
				mostrarClasesDeLocales();
				printf( "\nClase actual: %d" , pMatriz[i][j].clase );
				printf( "\nNueva clase: " );
				fflush( stdin );
				scanf( "%d" , &pMatriz[i][j].clase );
				printf( "\nLas visitas se han reiniciado a 0.\n" );
				pMatriz[i][j].visitas = 0;
				aprov++;
			}
		}
	} if( aprov == 0 )
		printf( "\nEl local no existe.\n" );
}

void mostrarMenu(){
	int a,b;
	int *pPiso; pPiso = crearPisos();
	int *pLocalesPorPiso; pLocalesPorPiso = crearLocalesPorPiso();
	local **pMatriz; pMatriz = crearCentroComercial( pPiso , pLocalesPorPiso );
	int **pEstado; pEstado = crearEstadoCentroComercial( pPiso , pLocalesPorPiso );
	for( a=0;a<*pPiso;a++ ){
		for( b=0;b<*pLocalesPorPiso;b++ )
			pEstado[a][b] = 0;
	} int opcion = 0;
	do{
		printf( "\nBienvenido al C.C. Aventura Plaza" );
    		printf( "\nMenu de opciones\n\n" );
    		printf( "1. Estabecer un nuevo local\n" );
        	printf( "2. Mostrar la informacion de un local\n" );
        	printf( "3. Modificar la informacion de un local\n" );
        	printf( "4. Agregar visitas a un local\n" );
		printf( "5. Recomendar locales\n" );
		printf( "6. Extinguir un local\n" );
        	printf( "0. Salir\n\n" );
        	printf( "Opcion: " );
		fflush( stdin );
        	scanf( "%d" , &opcion );
        	switch( opcion ){
			case 0:
				break;
            		case 1:
				crearNuevoLocal( pMatriz , pEstado , pPiso , pLocalesPorPiso );
                		break;
            		case 2:
				mostrarInformacionLocal( pMatriz , pPiso , pLocalesPorPiso , pEstado );
                		break;
            		case 3:
				modificarLocal( pMatriz , pPiso , pLocalesPorPiso , pEstado );
                		break;
            		case 4:
				agregarVisitas( pMatriz , pPiso , pLocalesPorPiso , pEstado );
                		break;
			case 5:
				recomendarLocales( pMatriz , pPiso , pLocalesPorPiso , pEstado );
				break;
			case 6:
				eliminarLocal( pMatriz , pPiso , pLocalesPorPiso , pEstado );
				break;
			default:
				printf( "La opcion ingresada no es valida\n" );
		}
  	} while( opcion != 0 );
	for( a=0;a<*pPiso;a++ )
		free( pMatriz[a] );
	free( pMatriz );
	for( a=0;a<*pPiso;a++ )
		free( pEstado );
	free( pEstado );
	free( pPiso ); free( pLocalesPorPiso );
}
