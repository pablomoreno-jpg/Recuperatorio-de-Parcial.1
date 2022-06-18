#include "mecanicos.h"

void MostrarUnMecanico(eMecanico mecanicos,eEspecilidad *especialidad, int tamEspecialidad){


	printf("|%4d|%20s|",mecanicos.idMecanico,mecanicos.nombreMecanico);

	for(int i = 0; i < tamEspecialidad; i++){

		if(especialidad[i].idEspecialidad == mecanicos.especialidad){

			printf("%25s|\n",especialidad[i].descripcion);
			break;
		}

	}

}

int listadoDeMecanico (eMecanico *mecanicos, int cantidadDeMecanicos, eEspecilidad *especialidad, int tamEspecialidad){

	int rtn = -1;
	char id[10];
	char nombre[20];
	char Charespecialidad[20];

	strcpy(id,"id");
	strcpy(nombre,"Nombre");
	strcpy(Charespecialidad,"Especialidad");

	if(mecanicos != NULL && cantidadDeMecanicos >= 0){
		printf("+----+--------------------+-------------------------+\n");
		printf("|%4s|%20s|%25s|\n",id,nombre,Charespecialidad);
		printf("+----+--------------------+-------------------------+\n");

		for(int i = 0; i < cantidadDeMecanicos; i++){

			MostrarUnMecanico(mecanicos[i],especialidad,tamEspecialidad);
		}

		printf("+----+--------------------+-------------------------+\n");
		rtn = 0;
	}

	return rtn;
}
