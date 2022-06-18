#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <ctype.h>
#include "diagnostico.h"

#define OCUPADO	1
#define LIBRE 0

typedef struct{

	int dia;
	int mes;
	int anio;

}eFecha;

typedef struct {

	int idCliente;
	char nombreCliente[50];
	int diagnostico;
	eFecha fecha;
	float cotizacion;
	int estado;
	int idMecanico;

} eServicio;

/// @brief incializa en 0 el campo estado del array de esctructura
///
/// @param servicio array de estructa que se va a incializar el campo estado
/// @param sizeServicio tamaño del array de la esctuctura servicio
/// @return devuelve -1 en caso de erro, devuelve 0 en caso de exito
int InitSericio (eServicio* servicio, int sizeServicio);

/// @brief busca en el array de esctructa el primer 0 del campo 'estado' que ecuntre
///
/// @param servicio array de estructura que va a buscar el valor de su campo 'estado'
/// @param sizeServicio tamaño del array de la esctura servico
/// @return devuelve -1 en caso de no encotrar ningun 0 en el campo estado del array de estructra, devuelve el indice del primer 0 que encuntre en el campo
int BuscarUnLibre(eServicio* servicio, int sizeServicio);

/// @brief pide el ingreso de un id y carga con un 0 el campo 'estado' del array de estructra servicio
///
/// @param servicio array de estructura que va a buscar y va a cambiar el estado
/// @param sizeServicio
/// @return devuele un -1 en caso de no encotrar el indice que se que se ingres por consola, devuelve 0 en caso de exito
int DarDeBaja(eServicio* servicio, int sizeServicio);

/// @brief mustra la mayoria de los campos del array de estructra principal y un solo campo del segun array de estructura que se pasa por parametro
///
/// @param servicio array de esctura que va a mostrar la mayoria de sus campos
/// @param diagnostico array de esctura que se va comprar y se va  mostar solamente uno de sus campos
/// @param tamDiagnostico tamaño del array de la esctructra diagnostico
void MostrarUnServicio(eServicio servicio,eDiagnostico*diagnostico,int tamDiagnostico);

/// @brief  utilizando un for y llamando a la funcion mostrarunservicio va a mostra una lista de todos los servicios
///
/// @param servicio array de estrcuta que va mostar la mayoria de sus campos
/// @param sizeServicio tamaño del array de la estructura servicio
/// @param diagnostico array de estrucutras que va a mostra solo uno de sus campos
/// @param tamdiagnostico tamaño del array de la estructura de la estructura diagnostico
/// @return devuelve -1 en caso de erro, devuelve 0 en caso de exito
int listadoDeServicios(eServicio* servicio, int sizeServicio,eDiagnostico *diagnostico, int tamdiagnostico);
