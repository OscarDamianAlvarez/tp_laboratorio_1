#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

char validacionDeOpcionChar(char mensaje[], char mensajeError[], char mensajeOpcion1[], char mensajeOpcion2[], char opcion1, char opcion2){
	char respuesta;
	do
	{
	printf("%s\n", mensaje);
	printf("%s\n", mensajeOpcion1);
	printf("%s\n", mensajeOpcion2);
	fflush(stdin);
	scanf("%c", &respuesta);

	}while(respuesta != opcion1 && respuesta != opcion2);

	return respuesta;
}

int validacionInt(int numero, int minimo, int maximo){

	while(numero < minimo || numero > maximo)
	{
	printf("Ingrese opcion valida(1-6):\n");
	scanf("%d", &numero);
	}

	return numero;
}

float validacionFloat(char mensaje[], char mensajeError[]){
	float numero;

	printf("%s\n", mensaje);
	scanf("%f", &numero);

	while(numero <= 0)
	{
		printf("%s\n",mensajeError);
		scanf("%f",&numero);
	}
	return numero;
}


