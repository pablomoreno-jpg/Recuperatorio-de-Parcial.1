#include "Servicio.h"

int InitSericio(eServicio *servicio, int sizeServicio) {

	int rtn = -1;

	if (sizeServicio > 0) {

		for (int i = 0; i < sizeServicio; i++) {

			servicio[i].estado = LIBRE;
			rtn = 0;
		}
	}

	return rtn;
}

int BuscarUnLibre(eServicio *servicio, int sizeServicio) {

	int rtn = -1;

	if (servicio != NULL && sizeServicio >= 0) {

		for (int i = 0; i < sizeServicio; i++) {

			if (servicio[i].estado == LIBRE) {

				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int DarDeBaja(eServicio* servicio, int sizeServicio){

	int rtn = -1;
	int id;
	int i;

	if(servicio != NULL && sizeServicio >= 0){

		if(getEntero(&id, "ingrese el id que quiera dar de baja: ", "error", 3) == 0){

			 i = BuscarIdServicio(servicio, sizeServicio, id);

			 if( i != -1){

				 servicio[i].estado = LIBRE;
				 rtn = 0;
			 }
			 else{

				 printf("\nno se esncontro el id.\n\n");
			 }
		}
	}

	return rtn;
}

void MostrarUnServicio(eServicio servicio,eDiagnostico *diagnostico,int tamDiagnostico){

	char precioNulo[4];

	strcpy(precioNulo," - ");

	if(servicio.estado == OCUPADO){

		printf("|%4d|%20s|%2d/%d/%d",servicio.idCliente,servicio.nombreCliente,
		servicio.fecha.dia,servicio.fecha.mes,servicio.fecha.anio);

		for(int i = 0; i < tamDiagnostico; i++){

			if(diagnostico[i].idDiagnostico == servicio.diagnostico){

				printf("|%20s|",diagnostico[i].descricpion);

				if(i == 0){
					printf("%14d|",servicio.idMecanico);
					printf("%15s|\n",precioNulo);
					break;
				}
				else{
					printf("%14d|",servicio.idMecanico);
					printf("%14.2f$|\n",servicio.cotizacion);
					break;
				}

			}

		}

	}

}

int listadoDeServicios(eServicio* servicio, int sizeServicio,eDiagnostico *diagnostico, int tamdiagnostico){

	int rtn = -1;

	if(servicio != NULL && diagnostico != NULL && sizeServicio >= 0 && tamdiagnostico >= 0){

		printf("+----+--------------------+---------+--------------------+--------------+---------------+\n");
		printf("|  id|              Nombre|  Fecha  |         Diagnostico|   id mecanico|         Precio|\n");
		printf("+----+--------------------+---------+--------------------+--------------+---------------+\n");

		for(int i = 0; i < sizeServicio; i ++){

			MostrarUnServicio(servicio[i], diagnostico, tamdiagnostico);
		}

		printf("+----+--------------------+---------+--------------------+--------------+---------------+\n");
		rtn = 0;
	}


	return rtn;
}

