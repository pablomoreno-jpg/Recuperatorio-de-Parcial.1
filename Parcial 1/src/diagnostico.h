#include <stdio.h>
#include <stdlib.h>
#include "input.h"

typedef struct{

	int idDiagnostico;
	char descricpion[25];

}eDiagnostico;

/// @brief mustra los campos de la estructura diagnostico
///
/// @param diagnostico estructura diagnostico que se va mostrar un sola vez
void MostrarUnDiagnostico (eDiagnostico diagnostico);

/// @brief utiliazndo un for y llamando a la funcion de mostrarunsolodiagnostico va mostras la totalidad el array de estrcuras
///
/// @param diagnostico array de estructura diagnostico
/// @param cantidadDeDiagnosticos tamanio de la array de estructura.
/// @return devuelve -1 en caso del que el array este apuntando a NULL o el tamaño del array sea menor a 0, devuelve 0 en caso de exito
int ListaDeDiagnosticos (eDiagnostico *diagnostico, int cantidadDeDiagnosticos);

