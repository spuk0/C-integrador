/*Una empresa desea conocer el grado de satisfacción del cliente. Para ello requiere una aplicación informática que implemente una lista enlazada para procesar los datos de las personas que serán encuestadas.
De cada encuesta se registran los siguientes datos: código de cliente, antigüedad como cliente (01. Menos de 1 año - 02. Entre 1 y 3 años - 03. Entre 3 y 5 años - 04. Mas de 5 años), 
grado de satisfacción en la atención (01. excelente - 02. Muy buena - 03. buena - 04. regular - 05. malo).
Se solicita codificar:
a) Las funciones para insertar un nodo adelante y el nodo k-ésimo de la lista.
b) Una función que permita eliminar el nodo k-ésimo.
c) Una función que retorne la cantidad de clientes encuestados cuya antigüedad no supere los 4 años.
d) Un listado con los datos de los encuestados cuyo grado de satisfacción no sea regular y malo.*/

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



