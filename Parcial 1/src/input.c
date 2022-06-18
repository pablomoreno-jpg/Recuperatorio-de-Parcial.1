#include "input.h"

static int EsNumero(char cadena[], int longitu);
static int EsFlotante(char cadena[],int longitud);
static int EsSoloLetras(char cadena[],int lonigtud);
static int EnterosSeguro(int *preResultado);
static int FlotanteSeguro(float *preResultado);
static int getCadena(char cadena[], int longitud);

int IngresarEntero(char *mensaje) {

	int entero;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &entero);

	return entero;
}

float IngresarFlotante(char *mensaje) {

	float flotante;

	printf("%s", mensaje);
	scanf("%f", &flotante);

	return flotante;
}

char IngreseUnCaracter(char *mensaje) {

	char caracter;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &caracter);

	return caracter;
}

void IngresarVector(char *mensaje, int vector[], int size) {

	for (int i = 0; i < size; i++) {

		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &vector[i]);
	}

}

int IngresarCadena(char mensaje[], char cadena[]) {

	int rtn = -1;
	if (cadena != NULL) {

		printf("%s", mensaje);
		fflush(stdin);
		gets(cadena);
		rtn = 0;
	}

	return rtn;
}

static int getCadena(char cadena[], int longitud) {

	int rtn = -1;
	char buffer[4069];

	if (cadena != NULL && longitud > 0) {
		fflush(stdin);
		if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
			if (buffer[strnlen(buffer, sizeof(buffer)) - 1] == '\n') {
				buffer[strnlen(buffer, sizeof(buffer)) - 1] = '\0';
			}
			if (strnlen(buffer, sizeof(buffer)) <= longitud) {
				strncpy(cadena, buffer, longitud);
				rtn = 0;
			}
		}
	}

	return rtn;
}

static int EsNumero(char cadena[],int longitud) {

	int rtn = -1;

	if (cadena != NULL) {

		for(int i = 0; i < longitud && cadena[i] != '\0';i++){

			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-')){

				continue;

			}
			if (cadena[i] > '9' || cadena[i] < '0') {

				rtn = 0;
				break;

			}
		}
	}

	return rtn;
}

static int EsFlotante(char cadena[], int longitud) {

	int rtn = -1;
	int contador = 0;

	if (cadena != NULL) {

		for(int i = 0;i< longitud && cadena[i] != '\0';i++){


			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-')){

				continue;

			}
			if (cadena[i] > '9' || cadena[i] < '0') {

				if (cadena[i] == '.') {

					contador++;

				}

			}
			if (contador <= 1) {

				rtn = 0;
				break;
			}

		}

	}

	return rtn;
}

static int EnterosSeguro(int *preResultado) {

	int rtn = -1;
	char auxiliar[10];

	if(preResultado != NULL &&
		getCadena(auxiliar, sizeof(auxiliar)) == 0
		&& EsNumero(auxiliar,sizeof(auxiliar))){

		rtn = 0;
		*preResultado = atoi(auxiliar);

	}

	return rtn;
}

int getEntero(int *preResultado, char *mensaje, char *mensajeError,int intentos) {

	int rtn = -1;
	int buffer;

	do{

		printf("%s",mensaje);
		if (preResultado != NULL &&
			EnterosSeguro(&buffer) == 0) {

			rtn = 0;
			*preResultado = buffer;
			break;
		}

		printf("%s\n",mensajeError);
		intentos--;

	}while(intentos >= 0);

	return rtn;
}

int getRangoDeEnteros(int* preResultado,char*mensaje,char*mensajeError,int intentos,int maximo,int minimo){

	int rtn = -1;

	int buffer;

	do{

		printf("%s",mensaje);
		if (preResultado != NULL &&
			EnterosSeguro(&buffer) == 0
			&& buffer >= minimo
			&& buffer <= maximo) {

			rtn = 0;
			*preResultado = buffer;
			break;
		}

		printf("%s\n",mensajeError);
		intentos--;

	}while(intentos >= 0);

	return rtn;
}

static int FlotanteSeguro(float *preResultado){

	int rtn = -1;
	char auxiliar[50];

	if(preResultado != NULL &&
		getCadena(auxiliar, sizeof(auxiliar)) == 0
		&& EsFlotante(auxiliar, sizeof(auxiliar)) == 0){

		rtn = 0;
		*preResultado = atof(auxiliar);

	}

	return rtn;
}

int getFlotante(float* preResultado,char*mensaje,char*mensajeError,int intentos){

	int rtn = -1;
	float buffer;

	do{
		printf("%s",mensaje);
		if(FlotanteSeguro(&buffer) == 0){

			rtn = 0;
			*preResultado = buffer;
			break;

		}
		printf("%s\n",mensajeError);
		intentos--;

	}while(intentos >= 0);

	return rtn;
}

int getRangoDeFlotante(float* preResultado,char*mensaje,char*mensajeError,int intentos,float maximo,float minimo){

	int rtn = -1;
	float buffer;

	do{
		printf("%s",mensaje);
		if(FlotanteSeguro(&buffer) == 0
			&& buffer >= minimo
			&& buffer <= maximo){

			rtn = 0;
			*preResultado = buffer;
			break;

		}
		printf("%s\n",mensajeError);
		intentos--;

	}while(intentos >= 0);

	return rtn;
}

static int EsSoloLetras(char cadena[],int lonigtud){

	int rtn = -1;

	if(cadena != NULL){

		for(int i = 0; i < lonigtud && cadena[i] != '\0';i++){

			if((cadena[i] != ' ') && (cadena[i] >= 'a' || cadena[i] <= 'z') && (cadena[i] >= 'A' || cadena[i] <= 'Z')){

				rtn = 0;
				break;
			}
		}
	}


	return rtn;
}

int getCadenaDeLtras(char mensaje[],char mesajeError[],char cadena[],int intentos){

	int rtn = -1;
	char auxliar[500];

	IngresarCadena(mensaje, auxliar);

	do{
		if(cadena != NULL &&
				EsSoloLetras(auxliar, sizeof(auxliar)) == 0){

				strcpy(cadena,auxliar);
				rtn = 0;
		}

		intentos--;
	}while(intentos >= 0);



	return rtn;
}

void AcomodarNombre(char cadena[], int sizeCadena) {

	for (int i = 0; i < sizeCadena; i++) {

		if (i == 0) {

			cadena[i] = toupper(cadena[i]);
		} else {

			cadena[i] = tolower(cadena[i]);
		}
	}

}


