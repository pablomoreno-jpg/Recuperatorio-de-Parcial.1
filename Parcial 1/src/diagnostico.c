#include "diagnostico.h"

void MostrarUnDiagnostico (eDiagnostico diagnostico){

	printf("|%4d|%22s|\n",diagnostico.idDiagnostico,diagnostico.descricpion);

}

int ListaDeDiagnosticos (eDiagnostico *diagnostico, int cantidadDeDiagnosticos){

	int rtn = -1;

	if(diagnostico != NULL && cantidadDeDiagnosticos >= 0){

		printf("+----+----------------------+\n");
		printf("|  id|           descripcion|\n");
		printf("+----+----------------------+\n");

		for(int i = 0; i < cantidadDeDiagnosticos; i++){

			MostrarUnDiagnostico(diagnostico[i]);

		}
		printf("+----+----------------------+\n");

		rtn = 0;
	}

	return rtn;
}
