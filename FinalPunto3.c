/*Una empresa que distribuye alimento para mascotas necesita mejorar sus tiempos de distribución y, 
conociendo las distancias entre cada uno de los puntos a los cuales distribuye, decidió utilizar estrategias vinculadas con la teoría de grafos para determinar los caminos óptimos y más cortos.
1. Para colaborar con la empresa se solicita:
a) Definir la estructura de tipo grafo, para almacenar los datos, considerando que se conoce la distancia en kilómetros que unen los puntos de distribución(vértices).
b) Codificar una función que permita insertar un arco
c) Codificar la función que permita visualizar la matriz de peso.
2. Si la empresa cuenta con 5 puntos de distribución (locales del 1 al 5) y las distancias que unen los puntos son las siguientes:
• Entre local 1 y local 2: 7.5 kilómetros
• Entre local 1 al local 4: 9 kilómetros
• Entre local 2 al local 3: 3.4 kilómetros
• Entre local 2 al local 5: 17.7 kilómetros
• Entre local 3 al local 4: 8 kilómetros
• Entre local 4 al local 5: 3 kilómetros
• Entre local 5 al local 1: 15 kilómetros
Graficar el grafo (no dirigido) correspondiente a los datos de locales y distancias ya descritos.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define n 5

typedef float tPeso;
typedef int tVertice;

typedef struct {	 
	tVertice origen;
	tVertice destino;		
	tPeso peso;	
}tArco;
 	
typedef bool conjuntoVertices [n];
typedef tPeso conjuntoArcos [n][n];

typedef struct {	 		
	conjuntoVertices vertices;
	conjuntoArcos arcos;			
}tGrafoPonderado;

tGrafoPonderado * grafo;	
tArco arco;	

void agregaVertice(tGrafoPonderado *);
void agregaArcoP(tGrafoPonderado * );
void visualizarMatrizPesos(tGrafoPonderado *);

int main (){
	grafo = (tGrafoPonderado *) malloc(sizeof(tGrafoPonderado));
	incializarGrafo(grafo);
	
	agregaVertice(grafo, 1);
	agregaVertice(grafo, 2);
	agregaVertice(grafo, 3);
	agregaVertice(grafo, 4);
	agregaVertice(grafo, 5);
	
	arco.origen = 1;
	arco.destino = 2;
	arco.peso = 7.5;
	
	/*Asi con los demas destinos que no hago porq no me alcanza el tiempo*/
	
	return 0;
}

void agregaArcoP(tGrafoPonderado *, tArco){
		if(( pGrafo->vertices[arc.origen] == 1) && (pGrafo->vertices[arc.destino] == 1)) {
		pGrafo->arcos[arc.origen][arc.destino] = arc.peso;	
		printf("Se agrego el arco [%d, %d]\n", arc.origen, arc.destino);
	}		
}

void visualizarMatrizPesos(tGrafoPonderado * pGrafo){
		int i, j, maxVer;
	printf("\nMATRIZ DE PESOS\n\n");
	maxVer = maxVertice(pGrafo);
	for (i = 1; i<= maxVer; i++) {
		for (j = 1; j<= maxVer; j++) {
			printf("%d ", pGrafo->arcos[i][j]);			
		}	
		printf("\n");
	}
}


