/*Una empresa desea conocer el grado de satisfacci�n del cliente. Para ello requiere una aplicaci�n inform�tica que implemente una lista enlazada para procesar los datos de las personas que ser�n encuestadas.
De cada encuesta se registran los siguientes datos: c�digo de cliente, antig�edad como cliente (01. Menos de 1 a�o - 02. Entre 1 y 3 a�os - 03. Entre 3 y 5 a�os - 04. Mas de 5 a�os), 
grado de satisfacci�n en la atenci�n (01. excelente - 02. Muy buena - 03. buena - 04. regular - 05. malo).
Se solicita codificar:
a) Las funciones para insertar un nodo adelante y el nodo k-�simo de la lista.
b) Una funci�n que permita eliminar el nodo k-�simo.
c) Una funci�n que retorne la cantidad de clientes encuestados cuya antig�edad no supere los 4 a�os.
d) Un listado con los datos de los encuestados cuyo grado de satisfacci�n no sea regular y malo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/* Tipos de datos personalizados */

typedef struct {
	int codClient;
	int antClient;
	int satisfaccion; 		
} tDatos;


typedef struct nodo {
	tDatos encuestado;
	struct nodo * siguienteEncuestado;
} tListaEncuestados;

tListaEncuestados * encuestados;
/*Punto a*/
void inicializarListaEncuestados();
bool listaVacia( tListaEncuestados * );
void insertarEncuestado( tDatos );
void insertarK( int k, tDatos );

/*Punto b*/
void eliminarK (int K);

/*Punto c*/
int clientNuevos(tListaEncuestados *);

/*Punto d*/
void clientSatisfechos(tListaEncuestados *);

int main (){
	
	return 0;
}

void inicializarListaEncuestados() {
	encuestados = NULL;
	printf("Lista de casos creada!\n");
}

bool listaVacia (tListaEncuestados * pEncuestados){
	/*Supongo q no es necesario desarrollar*/	
}

void insertarEncuestado( tDatos pEncuestado ) {
	tListaEncuestados * nuevoEncuestado;
	
	nuevoEncuestado = ( tListaEncuestados * ) malloc( sizeof( tListaEncuestados ) );
	
	nuevoEncuestado->encuestado = pEncuestado;
	
	if ( listaVacia( encuestados ) ) {
		 nuevoEncuestado->siguienteEncuestado = NULL;
	} else {
		nuevoEncuestado->siguienteEncuestado = encuestados;
	}
	
	encuestados = nuevoEncuestado;
	
	printf("Encuestado insertado!\n");	
}

void insertarK( int k, tDatos pEncuestado ) {	
	tListaEncuestados * aux;
	tListaEncuestados * nuevoNodo;
	int i;
	
	if( k==1 ) {
		/* Es como insertar adelante asi q se usa la funcion de arriba */
		insertarEncuestado( pEncuestado );
	}else{
		/* aca es el k-esimo */
		aux = encuestados;
		
		for ( i=1; i < k-1; i++) {
			aux = aux->siguienteEncuestado;
		}
			
		nuevoNodo = ( tListaEncuestados * ) malloc( sizeof ( tListaEncuestados ) );
	
		nuevoNodo->encuestado = pEncuestado;
		
		/*Se actualizan los punteros: */ 
		nuevoNodo->siguienteEncuestado = aux->siguienteEncuestado;
		aux->siguienteEncuestado = nuevoNodo;
		
		printf( "\nEncuestado insertado!\n");	
	}			
}

void eliminarK( int k ) {	
	tListaEncuestados * aux;
	tListaEncuestados * nodoSuprimir;
	int i;
	
	if ( k==1 ){
		
	nodoSuprimir = encuestados;
	
	encuestados = encuestados->siguienteEncuestado;
	
	free( encuestadoSuprimir );
	nodoSuprimir = NULL;
		
	}else{
		
		aux = encuestados;
		
		for ( i=1; i < k-1; i++) {
			aux = aux->siguienteEncuestado;
		}
		
		nodoSuprimir = aux->siguienteEncuestado;
	
		aux->siguienteEncuestado = nodoSuprimir->siguienteEncuestado;	
	
		free( nodoSuprimir );	
		nodoSuprimir = NULL;	
	}
	
}

int clientNuevos(tListaEncuestados * pEncuestados ){
	
	tListaEncuestados * auxEncuestados;
	auxEncuestados = pEncuestados;
	
	int cantAntClient;
	
	if( !listaVacia( auxEncuestados ) ) {				
		while ( auxEncuestados != NULL) {
			if (auxEncuestados->encuestado.antClient < 03){
				cantAntClient++;
			}					
			auxEncuestados = auxEncuestados->siguienteEncuestado;
		}
	}
	return cantAntClient;
}

void clientSatisfechos(tListaEncuestados * pEncuestados){
	tListaEncuestados * auxEncuestados;
	auxEncuestados = pEncuestados;
	
	if( !listaVacia( auxEncuestados ) ) {				
		while ( auxEncuestados != NULL) {
			if (auxEncuestados->encuestado.satisfaccion < 04){
				cantAntClient++;
				printf("\n\tEncuestado satisfecho: Codigo\t Antiguedad\t grado de satisfaccion \n");
				printf("%d\t%d\t%d\t", auxEncuestados->encuestado.codClient, auxEncuestados->encuestado.antClient, auxEncuestados->encuestado.satisfaccion);
			}					
			auxEncuestados = auxEncuestados->siguienteEncuestado;
		}
	}
}



