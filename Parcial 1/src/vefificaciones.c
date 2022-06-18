#include "verificaciones.h"

int ingresarFecha(char* mensaje,int*dia, int*mes, int*anio){

	int rtn = -1;
	int auxAnio;
	int auxMes;
	int auxDia;

	printf("%s",mensaje);

	if(getRangoDeEnteros(&auxAnio,"ingrese el año: ", "error", 5, 2022, 2010) == 0){

		*anio = auxAnio;

		if(getRangoDeEnteros(&auxMes, "ingrese el mes: ","error", 5, 12, 1) == 0){

			*mes = auxMes;

			switch(auxMes){
			case 2:
				if(getRangoDeEnteros(&auxDia, "ingrese dia: ", "error", 5, 28, 1) == 0){

					*dia = auxDia;
					rtn = 0;

				}
				break;
			case 4:
				if(getRangoDeEnteros(&auxDia, "ingrese dia: ", "error", 5, 30, 1) == 0){

					*dia = auxDia;
					rtn = 0;

				}
				break;
			case 6:
				if(getRangoDeEnteros(&auxDia, "ingrese dia: ", "error", 5, 30, 1) == 0){

					*dia = auxDia;
					rtn = 0;

				}
				break;
			case 9:
				if(getRangoDeEnteros(&auxDia, "ingrese dia: ", "error", 5, 30, 1) == 0){

					*dia = auxDia;
					rtn = 0;

				}
				break;
			case 11:
				if(getRangoDeEnteros(&auxDia, "ingrese dia: ", "error", 5, 30, 1) == 0){

					*dia = auxDia;
					rtn = 0;

				}
				break;
			default:
				if(getRangoDeEnteros(&auxDia, "ingrese dia: ", "error", 5, 31, 1) == 0){

					*dia = auxDia;
					rtn = 0;

				}
				break;
			}

		}

	}

	return rtn;
}


int BuscarOcupado(eServicio * servicio, int sizeServicio){

	int rtn = -1;

	if(servicio != NULL && sizeServicio >= 0){

		for(int i = 0; i < sizeServicio; i++){

			if(servicio[i].estado == OCUPADO){

				rtn = 0;
			}
		}
	}


	return rtn;
}

int BuscarIdServicio(eServicio* servicio, int sizeServicio, int id){

	int rtn = -1;

	if(servicio != NULL && sizeServicio){

		for(int i = 0; i < sizeServicio; i++){

			if(servicio[i].estado == OCUPADO && servicio[i].idCliente == id){

				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int buscarIdMecanico(eMecanico* mecanico, int sizeMecanico, int id){

	int rtn = -1;

	if(mecanico != NULL && sizeMecanico >= 0){

		for(int i = 0; i < sizeMecanico; i++){

			if(mecanico[i].idMecanico == id){

				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int compararIdServicioMecanico(eServicio* servicio, int sizeServicio, eMecanico* mecanico, int sizeMecanico, int id){

	int rtn = -1;

	if(mecanico != NULL && sizeMecanico >= 0 && servicio != NULL && sizeServicio){

		for(int i = 0; i < sizeMecanico; i++){

			for(int j = 0; j < sizeServicio; j++){

				if(servicio[i].idMecanico == mecanico[j].idMecanico && id+1 == servicio[i].idCliente){

					rtn = j;
					break;
				}

			}
		}
	}

	return rtn;
}
