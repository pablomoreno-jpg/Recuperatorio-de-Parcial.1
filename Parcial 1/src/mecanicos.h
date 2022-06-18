#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "especialidad.h"

typedef struct {

	int idMecanico;//pk
	char nombreMecanico[50];
	int especialidad;//fk
	int estado;

} eMecanico;

/// @brief muestra los campos de la estrcuta principal y un campo del array de la estructura que va a pasar por un filtro
///
/// @param mecanicos de estrcuta que va mostar la mayoria de sus campos
/// @param especialidad array de estructa que va a mostar uno de sus campos
/// @param tamEspecialidad tamaño del array de la estructura especialidad
void MostrarUnMecanico(eMecanico mecanicos,eEspecilidad *especialidad, int tamEspecialidad);

/// @brief utlizando un for y el llamado de la funcio mostrarunmecanico va a mostar un listado de todos lo mecanicos
///
/// @param mecanicos array de estrcuta que va mostar la mayoria de sus campos
/// @param cantidadDeMecanicos tamaño del array de la estructuras mecanicos
/// @param especialidad array de estrucutras que va a mostra solo uno de sus campos
/// @param tamEspecialidad tamaño de la estructura especialidad
/// @return devuelve -1 en caso de error. devulve 0 en caso de exito
int listadoDeMecanico (eMecanico *mecanicos, int cantidadDeMecanicos, eEspecilidad *especialidad, int tamEspecialidad);
