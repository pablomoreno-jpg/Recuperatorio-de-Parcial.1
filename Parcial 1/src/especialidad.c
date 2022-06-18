#include "especialidad.h"



void MostrarUnaEpecialidad (eEspecilidad especialidad){

	printf("%10s", especialidad.descripcion);

}

int listaDeEspecialidaddes(eEspecilidad *especialidad,int cantidadadDeEspecialidades){

	int rtn = -1;

	if(especialidad != NULL && cantidadadDeEspecialidades >= 0){

		for(int i = 0; i < cantidadadDeEspecialidades; i ++){

			MostrarUnaEpecialidad(especialidad[i]);

		}
		rtn = 0;
	}

	return rtn;
}
