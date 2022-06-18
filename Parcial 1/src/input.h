#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int IngresarEntero(char* mensaje);
float IngresarFlotante(char* mensaje);
char IngreseUnCaracter (char* mensaje);
void IngresarVector(char* mensaje, int vector[], int size );
int IngresarCadena(char mensaje[], char cadena[]);
int getEntero(int* preResultado,char*mensaje,char*mensajeError,int intentos);
int getRangoDeEnteros(int* preResultado,char*mensaje,char*mensajeError,int intentos,int maximo,int minimo);
int getFlotante(float* preResultado,char*mensaje,char*mensajeError,int intentos);
int getRangoDeFlotante(float* preResultado,char*mensaje,char*mensajeError,int intentos,float maximo,float minimo);
int getCadenaDeLtras(char mensaje[],char mesajeError[],char cadena[],int intentos);
void AcomodarNombre (char [],int);
