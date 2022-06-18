#include <stdio.h>
#include <stdlib.h>
#include "input.h"

typedef struct{

	int idEspecialidad;
	char descripcion[25];

}eEspecilidad;

/// @brief mustra los campos de la estructura especialidades
///
/// @param especialidad estructura que se va a mostrar
void MostrarUnaEpecialidad (eEspecilidad especialidad);

/// @brief utiliazndo un for y llamando a la funcion de mostrarunasolaespecialidad va mostras la totalidad el array de estrcuras
///
/// @param especialidad array de estructuras
/// @param cantidadadDeEspecialidades tamaño del array
/// @return devuelve -1 en caso del que el array este apuntando a NULL o el tamaño del array sea menor a 0, devuelve 0 en caso de exito
int listaDeEspecialidaddes(eEspecilidad *especialidad,int cantidadadDeEspecialidades);
