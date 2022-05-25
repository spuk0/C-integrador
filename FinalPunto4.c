/*Escriba en lenguaje c, la declaraci�n del tipo de dato tArbol que corresponde al nodo dado. Considerar que el �rbol se balancea seg�n el c�digo de producto.
b) Diagrame un �rbol de b�squeda binaria si sus elementos son insertados de la siguiente manera:
45 - 9 - 789 - 4 - 12 - 67 - 69 - 52 - 7
c) Codifique una funci�n recursiva que retorne la cantidad de productos almacenados en el �rbol correspondientes cuyo stock no supere un valor indicado recibido como par�metro.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int tElem;

typedef struct nodoArbol {
	tElem contenido;			
    struct nodoArbol * hijoIzdo;    
    struct nodoArbol * hijoDcho;    
}tArbol;

tArbol * arbol;

void CrearArbolVacio(tArbol *);
void Insertar(tArbol **, tElem);


int main (){

	return 0;
}

void CrearArbolVacio(tArbol * pArbol){
	pArbol = NULL;		
}

Insertar(tArbol **, tElem){

}


