/*
 ============================================================================
 Name        : Parcial.c
 Author      : Moreno Pablo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "nexo.h"

#define clientela 10
#define mecanicos 5
#define especialidades 5
#define diagnosticos 4
#define productos 4
#define vendedores 10

int main(void) {

	setbuf(stdout, NULL);
	int opcion;
	int opcionDeListados;
	int retorno;
	int idAuto = 0;
	int flag = 1;
	int flagD = 1;
	eServicio cliente[clientela];
	eMecanico trabajadores[mecanicos] = { { 1, "Jose", 1, 0 },
										{ 2, "Pepe", 3, 0},
										{ 3, "Manuel", 4, 0 },
										{ 4, "Alberto", 5, 0 },
										{ 5, "Mauricio", 2, 0 }};

	eEspecilidad especialidaddes[especialidades] = { {1, "aceite" },
												   { 2,"motores"},
												   { 3, "supencio"},
												   { 4, "aceito y motores"},
												   { 5, "suspencion y motores" } };

	eDiagnostico diagnostico[diagnosticos] = { { 0, "sin diagnostico" },
											 { 1, "cambio de aceite" },
											 { 2, "arreglo de motor" },
											 { 3, "ajuste de suspencion" } };

	eProveedor vendedor[vendedores] = {{1,"MotorLand",0,0,0},
									   {2,"bodegon145",0,0,0},
									   {3,"Renault",0,0,0},
									   {4,"RapiPartes",0,0,0},
									   {5,"Audio",0,0,0},
									   {6,"Sizuki",0,0,0},
									   {7,"Nassin",0,0,0},
									   {8,"AIK",0,0,0},
									   {9,"Rabusa",0,0,0},
									   {10,"el taller de Mauro",0,0,0}};



	eProducto productoProveedor[productos] = {{0, " - "},
											  {1, "aceite de motor"},
											  {2, "piezas para motores"},
											  {3, "resortes de suspencion"}};

	if (InitSericio(cliente, clientela) == 0) {

		do {

			printf("1.agregar un servicio.\n"
				   "2.Modificar servicio.\n"
				   "3.Cancelar servicio.\n"
				   "4.Diagosticar Servicio.\n"
				   "5.Listados.\n"
				   "6.Cerrar programa.\n\n");

			if (getRangoDeEnteros(&opcion, "eliga una opcion: ", "opcion invalida", 3, 6, 1)
					== 0) {

				switch (opcion) {
				case 1:

					idAuto++;
					retorno = CargarServico(cliente, clientela, trabajadores,mecanicos, especialidaddes, especialidades, idAuto);


					if(retorno == 0){

						printf("\nel cliente se cargo de forma correcta.\n\n");
						flag = 0;

					} else {

						printf("\nerror.\n\n");
					}
					break;
				case 2:
					if (flag == 0) {

						if (ModificarServico(cliente, clientela, trabajadores,mecanicos, especialidaddes, especialidades) == 0) {

							printf("\nel cliente ha sido modificado correctamente.\n\n");
						}

					} else {

						printf("\nerror. ingrese al menos un cliente para porseguir sin problemas.\n\n");

					}
					break;
				case 3:
					if (flag == 0) {

						if (DarDeBaja(cliente, clientela) == 0) {

							printf("\nel cliente fue dado de baja de forma correcta.\n\n");
						}

					} else {

						printf("\nerror. ingrese al menos un cliente para porseguir sin problemas.\n\n");
					}
					break;
				case 4:
					if(flag == 0){

						if(diagnosticar(cliente, clientela, trabajadores, mecanicos, diagnostico, diagnosticos) == 0){

							printf("\ndiagnostico cargado.\n\n");
							cargaDeCliente(vendedor, vendedores, cliente, clientela, trabajadores, mecanicos);

							flagD = 0;
						}
						else{

							printf("\ndiagnostico no cargado.\n\n");
						}
					}
					else{

						printf("\nerror. ingrese al menos un cliente para porseguir sin problemas.\n\n");
					}
					break;
				case 5:
					printf("\n1.Mecanicos.\n"
						   "2.Servicios.\n"
						   "3.Mecanicos sin servicios.\n"
						   "4.Ordenar servicios del mas nuevo al mas viejo.\n"
						   "5.Sumatoria de cambios de aceite por fecha especifica.\n"
						   "6.Cotizacion promedio de cada uno de los mecanicos.\n"
						   "7.Mecaicos que diagnosticaron mas servicios.\n"
						   "8.listado de servicios ordenados por especialidad de mecanicos alfabeticamente.\n"
						   "9.Servicios entre Marzo y Mayo del 2022 para una especialidad determinada.\n"
						   "10.Porcentaje de servicio diagnosticados que atiende cada mecánico en función del total de diagnósticos.\n"
						   "11.lista de vendedores con sus clientes.\n"
						   "12.Salir\n\n");

					if (getRangoDeEnteros(&opcionDeListados,"ingrese uno de los listados: ", "opcion invalida", 3, 12, 1) == 0) {

						switch (opcionDeListados) {
						case 1:
							OrdenarPorId(cliente, clientela);
							listadoDeMecanico(trabajadores, mecanicos,especialidaddes,especialidades);
							break;
						case 2:
							if (flag == 0) {

								OrdenarPorId(cliente, clientela);
								listadoDeServicios(cliente, clientela, diagnostico, diagnosticos);


							} else {

								printf("\nerror. ingrese al menos un cliente para porseguir sin problemas.\n\n");

							}
							break;
						case 3:
							if(flag == 0){

								if(ListarMecanicosSinTrabajo(cliente, clientela, trabajadores, mecanicos, especialidaddes, especialidades) == 0){

								}
							}
							else{

								printf("\nerror. ingrese al menos un cliente para porseguir sin problemas.\n\n");

							}
							break;
						case 4:
							if(flag == 0){

								OrdenarPorFecha(cliente, clientela);
								listadoDeServicios(cliente, clientela, diagnostico, diagnosticos);

							}
							else{

								printf("\nerror. ingrese al menos un cliente para porseguir sin problemas.\n\n");
							}
							break;
						case 5:
							if(flag == 0){

								SumatoriaPorFecha(cliente, clientela);

							}
							else{

								printf("\nerror. ingrese al menos un cliente para porseguir sin problemas.\n\n");

							}
							break;
						case 6:
							if(flag == 0 && flagD == 0){

								CotizacionDeMecanicos(cliente, clientela, trabajadores, mecanicos);
							}
							else{

								printf("\nerror. diagnostique al menos un cliente para porseguir sin problemas.\n\n");

							}
							break;
						case 7:
							if(flag == 0){

								MecanicoConMasServicos(cliente, clientela, trabajadores, mecanicos);

							}
							else{

								printf("\nerror. ingrese al menos un cliente para porseguir sin problemas.\n\n");

							}

							break;
						case 11:
							if(ListarProveedores(vendedor, vendedores, productoProveedor, productos)== -1){

								printf("\n.error\n\n");

							}
							break;
						case 12:
							printf("\ncerrando los listados... \n\n");
							break;
						}


					}
					break;
				case 6:
					printf("\ncerrando programa...\n");
					break;
				}

			}

			if (BuscarOcupado(cliente, clientela) == -1){

				flag = 1; //carga la bandera en su estado incial en caso de que se cargue el primer servicio, y luego se de baja en mismo.
			}

		} while (opcion != 6);
	}

	return 0;
}
