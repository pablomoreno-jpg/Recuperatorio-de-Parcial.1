#include "listados.h"

int ListarMecanicosSinTrabajo (eServicio *servicio,int tamServicio, eMecanico *mecanicos, int tamMecanicos, eEspecilidad *especialidades, int tamEspecialidades){

	int rtn= -1;

	if(servicio != NULL && mecanicos != NULL && tamServicio >= 0 && tamMecanicos >= 0){

		printf("mecanicos sin servicos: \n");
		for(int i = 0; i < tamMecanicos; i++){

			for(int j = 0; j < tamServicio; j++){

				if(mecanicos[i].estado == LIBRE && mecanicos[j].idMecanico != servicio[i].idMecanico ){

					MostrarUnMecanico(mecanicos[i], especialidades, tamEspecialidades);
					rtn = 0;
					break;
				}
			}
		}
	}

	return rtn;
}

void OrdenarPorFecha(eServicio *servicio,int tamServicio){

	eServicio auxiliar;

	if(servicio != NULL && tamServicio){

		for(int i = 0; i < tamServicio-1; i++){

			for(int j = i+1; j < tamServicio; j++){

				if(servicio[i].fecha.anio <= servicio[j].fecha.anio){

					auxiliar = servicio[i];
					servicio[i] = servicio[j];
					servicio[j] = auxiliar;

				}
				else{

					if(servicio[i].fecha.mes <= servicio[j].fecha.mes){

						auxiliar = servicio[i];
						servicio[i] = servicio[j];
						servicio[j] = auxiliar;

					}
					else{

						if(servicio[i].fecha.mes < servicio[j].fecha.mes){

							auxiliar = servicio[i];
							servicio[i] = servicio[j];
							servicio[j] = auxiliar;

						}
					}

				}
			}
		}
	}

}

void OrdenarPorId(eServicio *servicio,int tamServicio){

	eServicio auxiliar;

	if(servicio != NULL && tamServicio >= 0){

		for(int i = 0; i < tamServicio-1; i++){

			for(int j = i +1; j < tamServicio; j++){

				if(servicio[i].idCliente > servicio[j].idCliente){

					auxiliar = servicio[i];
					servicio[i] = servicio[j];
					servicio[j] = auxiliar;

				}
			}
		}
	}
}

void SumatoriaPorFecha(eServicio *servicio,int tamServicio){

	int anio;
	int mes;
	int dia;
	int flag = -1;
	float sumatoria;

	if(servicio != NULL && tamServicio >= 0){

		if(ingresarFecha("ingrese una fecha: ",&dia, &mes, &anio) == 0){

			for(int i = 0; i < tamServicio; i++){

				if(anio == servicio[i].fecha.anio && mes == servicio[i].fecha.mes && dia == servicio[i].fecha.dia && servicio[i].diagnostico == 1){

					sumatoria += servicio[i].cotizacion;
					flag = 0;

				}

			}

			if(flag == 0){

				printf("\npara la fecha %d/%d/%d la cotizacion total es de %.2f$.\n\n",dia,mes,anio,sumatoria);

			}
			else{

				printf("\nno se encontro ningun diagnostico del tipo 'cambio de aceite'.\n\n");

			}

		}
	}

}

int CotizacionDeMecanicos(eServicio *servicio,int tamServicio,eMecanico *mecanicos,int tamMecanicos){

	int rtn = -1;
	int j;
	float promedio[tamMecanicos];
	int Acontador[tamMecanicos];
	float sumatoria[tamMecanicos];


	for(int i = 0; i < tamMecanicos; i++){

		Acontador[i] = 0;
	}


	if(servicio != NULL && mecanicos != NULL && tamServicio >= 0 && tamMecanicos >= 0){

		for(int i = 0; i < tamServicio; i++){

			if(servicio[i].estado == OCUPADO){

				j = compararIdServicioMecanico(servicio, tamServicio, mecanicos, tamMecanicos, i);


				if(mecanicos[j].estado == OCUPADO && servicio[i].cotizacion > 0){


					Acontador[j] = Acontador[j]+1;
					sumatoria[j] += servicio[i].cotizacion;

					promedio[j] = sumatoria[j] / Acontador[j];

					rtn = 0;

				}

			}

		}

		if(rtn == 0){

			printf("+------------+--------------------+---------------+-----------------------+\n");
			printf("| ID Mecamico|              Nombre|   can.Clientes|    cotizacion Promedio|\n");
			printf("+------------+--------------------+---------------+-----------------------+\n");

			for(int i = 0; i < tamMecanicos; i++){

				if(mecanicos[i].estado == OCUPADO && Acontador[i] > 0){

					printf("|%12d|%20s|%15d|%21.2f$|\n",mecanicos[i].idMecanico,mecanicos[i].nombreMecanico,Acontador[i],promedio[i]);

				}
			}

			printf("+------------+--------------------+---------------+-----------------------+\n");


		}

	}

	return rtn;
}

int MecanicoConMasServicos(eServicio *servicio,int tamServicio,eMecanico *mecanicos,int tamMecanicos){


	int j;
	int contado[tamMecanicos];
	int flag2 = 1;
	int flag1 = 1;
	eMecanico MecanicoConMasClientes;
	int rtn;

	for(int i = 0; i < tamMecanicos;i++){

		contado[i] = 0;

	}

	if(servicio != NULL && mecanicos != NULL && tamServicio >= 0 && tamMecanicos >= 0){

		for(int i = 0; i < tamServicio; i++){

			j = compararIdServicioMecanico(servicio, tamServicio, mecanicos, tamMecanicos, i);

			if(mecanicos[j].estado == OCUPADO){

				if(flag1 == 1){

					contado[j]++;
					MecanicoConMasClientes = mecanicos[j];
					flag2 = 0;

				}
				else{

					if(flag1 == 0 && contado[j-1] < contado[j]){

						contado[j]++;
						MecanicoConMasClientes = mecanicos[j];
						flag2 = 0;
					}
				}
			}
		}



		if(flag2 == 0){

			printf("el mecanico con mas servicios es: %d %s",MecanicoConMasClientes.idMecanico,MecanicoConMasClientes.nombreMecanico);

		}



	}

	return rtn;
}

