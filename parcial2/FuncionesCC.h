#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 20

typedef enum clase{
	Otros=0 , Moda=1 , Mascotas=2 , Comida=3 , Tecnologia=4 , Hogar=5
} clase;

typedef struct local{
	char nombre[MAX];
	int visitas;
	int clase;
} local;

//Muestra el menu de inicio del programa.
void mostrarMenu();

//Muestra un menu desplegable donde se muestran las clases de locales los cuales el centro comercial admite.
void mostrarClasesDeLocales();

//Me retorna un apuntador a la cantidad de pisos con los cuales cuenta mi centro comercial.
int* crearPisos();

//Me retorna un apuntador a la cantidad de locales que el centro comercial acepta en cada piso.
int* crearLocalesPorPiso();

//Reservo un espacio de memoria para los registros del centro comercial.
local** crearCentroComercial( int *pPiso , int *pLocalesPorPiso );

//Reservo un espacio de memoria para los registros de disponibilidad del centro comercial.
int** crearEstadoCentroComercial( int *pPiso , int *pLocalesPorPiso );

//Registra un nuevo local en la base de datos del centro comercial.
void guardarNuevoLocal( local **pMatriz , local *plocal , int i , int j );

//Genera una variable temporal de tipo "struct" que se utiliza para almacenar momentaneamente el nuevo local que se agregara al centro comercial.
void crearNuevoLocal( local **pMatriz , int **pEstado , int *pPiso , int *pLocalesPorPiso );

//Muestra los datos almacenados acerca de un local en especifico.
void mostrarInformacionLocal( local **pMatriz , int *pPiso , int *pLocalesPorPiso , int **pEstado );

//Me permite utilizar el "enum" que he difinido para las clases de locales que el centro comercial admite.
void codificarClase( int tipo );

//Elimina los registros de un local pre-existente. Esto significa que no lo puedes encontrar en el sistema.
void eliminarLocal( local **pMatriz , int *pPiso , int *pLocalesPorPiso , int **pEstado );

//Esta funcion me permite agregar visitar a un local en especifico.
void agregarVisitas( local **pMatriz , int *pPiso , int *pLocalesPorPiso , int **pEstado );

//Incrementa en 1 el numero de visitas que un local posee. Se usa recursion para esta funcion.
void sumarVisitas( local **pMatriz , int i , int j );

//Muestra al usuario locales que pueden ser de su interes dependiendo de un parametro que este elige con antelacion.
void recomendarLocales( local **pMatriz , int *pPiso , int *pLocalesPorPiso , int **pEstado );

//Modifica la informacion que posee un local ya existente, reemplazandola por nuevos datos que el usuario ingresa al sistema.
void modificarLocal( local **pMatriz , int *pPiso , int *pLocalesPorPiso , int **pEstado );