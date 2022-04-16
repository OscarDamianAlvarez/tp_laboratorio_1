#include "calculos.h"
#include <stdio.h>
#include <stdlib.h>

float calculosDePorcentajes(float precio,int porcentaje, int auxiliar)
{
	float resultado;
	float precioConPorcentaje;

	precioConPorcentaje = precio * porcentaje / 100;

	if(auxiliar == 1)
	{
		resultado = precio + precioConPorcentaje;
	}
	else
	{
		resultado = precio - precioConPorcentaje;
	}

	return resultado;
}

float calculosDeDivisas(float moneda, float tipoDeCambio)
{
	float resultado;

	resultado = moneda / tipoDeCambio;

	return resultado;
}

float calculoPrecioUnitario(float precio, int kilometros)
{
	float resultado;
	resultado = (float)precio / kilometros;
	return resultado;
}

float calcularDiferencia(float precio1, float precio2)
{
	float diferencia;

	if(precio1 > precio2)
	{
		diferencia = precio1 - precio2;
	}
	else
	{
		diferencia = precio2 - precio1;
	}
	return diferencia;
}






