/*Las Oficinas del Centro de Atenci�n del Registro Automotor de la Ciudad otorga diariamente turnos online a personas que desean realizar tr�mites durante el mes. 
Los datos que se registran al asignar cada turno para atenci�n son: d�a de visita(correspondientes al mes), 
n�mero de turno asignado, documento y c�digo de atenci�n (1 - Consulta, 2 � Solicitud Libre Deuda, 3 � Baja Automotor). 
Estos datos son almacenados en un archivo mensual con el siguiente dise�o:



El archivo esta ordenado por d�a de visita. En un mismo d�a se registran diferentes tr�mites.
Se solicita:
1. Total general de turnos otorgados.
2. Total de turnos otorgados por d�a.
3. Totales generales de turnos otorgados por Solicitud de Libre Deuda y solicitud de Formulario 08.
4. Total de d�as que se realizaron atenciones.
5. Detalle de los totales de atenciones por d�a, seg�n el siguiente formato:

*/
#include <stdio.h> 
#include <string.h>
typedef char tString[40];
typedef struct {	    
	tString diaVisita;
	int nroTurno;
	float dni;
	int codAtencion;
}tRegistroClient;	 

tRegistroClient regClients;
FILE * archivo;

int diaVisitaAnt;
int cantTurnosTotal, turnosPorDia;
int turnosForm, turnosDeud, bajAutMot, consultas;
int diasDeAtenciones;

void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unClient();
void finCorte();

int main() {		
	inicializacion();	
	procesoCorte();		
	finalizacion();
}

void inicializacion() {
	archivo = fopen("automotor.dat", "rb");			
    fread(&regClients, sizeof(tRegistroClients), 1, archivo);    
	diaVisitaAnt = regClients.diaVisita;	
	cantTurnosTotal = 0;	

	printf("Centro de Atenci�n del Registro Automotor de la Ciudad. \n Detalle de Atenciones realizadas: \n");
}

void procesoCorte() {
	while (!feof(archivo)) {
		principioCorte(); 
	    while(!feof(archivo) && regClients.diaVisita == diaVisitaAnt) {
			unClient();
			fread(&regClients, sizeof(tRegistroClient), 1, archivo);
		}
		finCorte();
	}
}

void principioCorte() {
	cantTurnosTotal=0;		
	turnosPorDia = 0;
	diasDeAtenciones = 0;		
	turnosForm = 0;	
	turnosDeud= 0;
	bajAutMot= 0;
	consultas=0;	
}

void unClient(){
	turnosPorDia = turnosPorDia + 1;
	diasDeAtenciones = diasDeAtenciones + regClients.diaVisita;
	if(regClients.codAtencion == 3){
		turnosForm = turnosPorForm + 1;
	}
	if(regClients.codAtencion == 2){
		turnosDeud=turnosDeud + 1;
	}
	if(regClients.codAtencion == 4){
		bajAutMot=bajAutMot + 1;
	}
	if(regClients.codAtencion == 1){
		consultas=consultas + 1;
	}				
													
}

void finCorte(){      		
	cantTurnosTotal = cantTurnosTotal + turnosPorDia;
	printf("Dia: %d \t\t Consultas: %d\n", diaVisitaAnt, consultas);
	printf("Solicitud libre deuda: %d\n", turnosDeud);
	printf("Formulario: %d\n", turnosForm);
	printf("Baja automotor: %d\n", bajAutMot);
	printf("Total de turnos: \n", cantTurnosTotal);
	printf("-------------------------------------------------------\n");
	
	diaVisitaAnt = regClients.diaVisita;
}

void finalizacion(){
	printf("Total de d�as trabajados de atenci�n en el mes: %d\n", diasDeAtenciones);
	printf("Total de Solicitudes de Libre Deuda: %d\n", turnosDeud);
	printf("Total de solicitudes de Formulario 08: \n", turnosForm);
	
	fclose(archivo);      
}

