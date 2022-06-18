#include "servicosYmecanicos.h"

eServicio AgregarUnServico(eMecanico *mecanicos, int cantidadDeMecanicos, int id, eEspecilidad *especialidad, int tamEspecialidad){

	eServicio servicis;

	servicis.idCliente = id;

	getCadenaDeLtras("\ningrese el nombre: ", "Error", servicis.nombreCliente,
			3);
	AcomodarNombre(servicis.nombreCliente, sizeof(servicis.nombreCliente));

	ingresarFecha("ingrese la fecha:\n", &servicis.fecha.dia,
				&servicis.fecha.mes, &servicis.fecha.anio);

	if (listadoDeMecanico(mecanicos, cantidadDeMecanicos,especialidad,tamEspecialidad) == 0) {

		getRangoDeEnteros(&servicis.idMecanico, "Ingrese el mecanico: ","error", 3, cantidadDeMecanicos,(cantidadDeMecanicos + 1) - cantidadDeMecanicos);

	}

	for(int i = 0; i < cantidadDeMecanicos;i++){

		if(servicis.idMecanico == mecanicos[i].idMecanico){

			mecanicos[i].estado = OCUPADO;
			break;
		}

	}

	return servicis;
}

int CargarServico(eServicio *servicio, int sizeServicio, eMecanico *mecanicos,int cantidadDeMecanicos, eEspecilidad *especialidad, int tamEspecialidad, int idUto) {

	int rtn = -1;
	int i;

	if (servicio != NULL && sizeServicio >= 0) {

		i = BuscarUnLibre(servicio, sizeServicio);

		if (i >= 0) {

			servicio[i] = AgregarUnServico(mecanicos, cantidadDeMecanicos,idUto,especialidad, tamEspecialidad);
			servicio[i].estado = OCUPADO;
			servicio[i].diagnostico = 0;

			rtn = 0;

		}
	}

	return rtn;
}

int ModificarServico(eServicio *servicio, int sizeServicio,eMecanico *mecanicos, int cantidadDeMecanicos, eEspecilidad *especialidad, int tamEspecialidad) {

	int rtn = -1;
	int id;
	int i;
	int opcion;

	if (servicio != NULL && sizeServicio >= 0) {

		if (getEntero(&id, "ingrese el id que quiera modificar: ", "error", 3)== 0) {

			i = BuscarIdServicio(servicio, sizeServicio, id);

			if (i >= -1) {

				printf("1.nombre cliente\n2.fecha del Servico\n3.id mecanico\n0.cancelar\n");

				if (getRangoDeEnteros(&opcion,"ingrese la iopcion que quiera modificar: ","opcion invalda", 3, 3, 0) == 0){

					switch (opcion){
					case 0:
						printf("\ncancelado\n");
						rtn = 0;
						break;
					case 1:
						IngresarCadena("Nombre del cliente: ",servicio[i].nombreCliente);
						AcomodarNombre(servicio[i].nombreCliente,sizeof(servicio->nombreCliente));
						rtn = 0;
						break;
					case 2:
						ingresarFecha("ingrese la nueva fecha:\n",&servicio[i].fecha.dia, &servicio[i].fecha.mes,&servicio[i].fecha.anio);
						rtn = 0;
						break;
					case 3:
						if (listadoDeMecanico(mecanicos, cantidadDeMecanicos, especialidad, tamEspecialidad)== 0) {

							getRangoDeEnteros(&servicio[i].idMecanico,"ingrese el id de mecanico ", "error", 3, cantidadDeMecanicos,(cantidadDeMecanicos +1) - cantidadDeMecanicos );

							rtn = 0;
						}
						break;
					}

				}
			}
		}
	}


	return rtn;
}

int diagnosticar(eServicio *servicio, int sizeServicio, eMecanico *mecanicos,int cantidadDeMecanicos, eDiagnostico *diagnostico, int tamDiagnostico) {

	int rtn = -1;
	int flag = 1;
	int id;
	int ids;
	int i;
	int j;

	if (servicio != NULL && mecanicos != NULL && sizeServicio >= 0 && cantidadDeMecanicos  >= 0) {

		if(getRangoDeEnteros(&id, "ingrese el id del mecanico: ","Error" , 3, cantidadDeMecanicos, (cantidadDeMecanicos +1) - cantidadDeMecanicos) == 0){



			i = buscarIdMecanico(mecanicos, cantidadDeMecanicos, id);

			if(i > -1){

				printf("\n");


				for(int j = 0; j < sizeServicio; j++){

					if(mecanicos[i].idMecanico == servicio[j].idMecanico && servicio[j].diagnostico == 0){

						MostrarUnServicio(servicio[j], diagnostico, tamDiagnostico);

						flag = 0;
					}
				}


				if( flag == 0){
					if(getEntero(&ids, "\ningrese el id del cliente que quiera diagnosticar: ", "error", 3) == 0 && flag == 0){

						j = BuscarIdServicio(servicio, sizeServicio, ids);

						if(j > -1 && mecanicos[i].idMecanico == servicio[j].idMecanico){

							ListaDeDiagnosticos(diagnostico, tamDiagnostico);

							if(getRangoDeEnteros(&servicio[j].diagnostico, "ingrese el id del diagnostico: ", "error", 3,tamDiagnostico -1, (tamDiagnostico +1) - tamDiagnostico) == 0){

								if(getRangoDeFlotante(&servicio[j].cotizacion, "ingrese el presupuesto del serivicio: ", "erro", 3, 99999, 100) == 0){

									rtn = 0;
								}
							}
						}
					}
					else{

						printf("\nError. no se contro el servicio.\n");

					}
				}
				else{

						printf("Error. no se encontro ningun servicio.\n");

				}
			}
		}
	}

	return rtn;
}
