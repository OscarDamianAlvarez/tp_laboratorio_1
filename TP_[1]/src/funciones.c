#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "calculos.h"
#define BTC 4606954.55

void cargaForzada()
{
	float kilometros = 7090;
	float precioDeVueloAerolineas = 162965;
	float precioDeVueloLatam = 159339;
	float precioLatamConTDeDebito;
	float precioAerolineasConTDeDebito;
	float precioLatamConTDeCredito;
	float precioAerolineasConTDeCredito;
	float precioUnitarioLatam = 0;
	float precioUnitarioAerolineas = 0;
	float diferenciaDePrecio = 0;
	double precioEnBTCLatam = 0;
	double precioEnBTCAerolineas = 0;

	precioLatamConTDeDebito = calculosDePorcentajes(precioDeVueloLatam,10,0);
	precioAerolineasConTDeDebito = calculosDePorcentajes(precioDeVueloAerolineas,10,0);

	precioLatamConTDeCredito = calculosDePorcentajes(precioDeVueloLatam,25,1);
	precioAerolineasConTDeCredito = calculosDePorcentajes(precioDeVueloAerolineas,25,1);

	precioEnBTCLatam = calculosDeDivisas(precioDeVueloLatam, BTC);
	precioEnBTCAerolineas = calculosDeDivisas(precioDeVueloAerolineas, BTC);


	precioUnitarioLatam = calculoPrecioUnitario(precioDeVueloLatam,kilometros);
	precioUnitarioAerolineas = calculoPrecioUnitario(precioDeVueloAerolineas,kilometros);

	diferenciaDePrecio = calcularDiferencia(precioDeVueloLatam,precioDeVueloAerolineas);

	printf("KMs Ingresados: %.f Km\n", kilometros);
	printf("\n");
	printf("Precio Aerolineas: $ %.2f\n", precioDeVueloAerolineas);
	printf("a) Precio con tarjeta de débito: $ %.2f\n", precioAerolineasConTDeDebito);
	printf("b) Precio con tarjeta de crédito: $ %.2f\n", precioAerolineasConTDeCredito);
	printf("c) Precio pagando con bitcoin: %.8f BTC \n", precioEnBTCAerolineas);
    printf("d) Precio unitario: $ %.2f\n", precioUnitarioAerolineas);
	printf("\n");
	printf("Precio Latam: $ %.2f\n", precioDeVueloLatam);
	printf("a) Precio con tarjeta de débito: $ %.2f\n", precioLatamConTDeDebito);
	printf("b) Precio con tarjeta de crédito: $ %.2f\n", precioLatamConTDeCredito);
	printf("c) Precio pagando con bitcoin: %.8f BTC \n", precioEnBTCLatam);
	printf("d) Precio unitario: $ %.2f \n", precioUnitarioLatam);
	printf("\n");
	printf("La diferencia de precio es: $ %.2f \n", diferenciaDePrecio);
	printf("__________________________________________\n");
	printf("\n");

	return;
}
// Esta es otra manera pero no estaba seguro si ponerla o no
//void cargaForzada()
//{
//	float kilometros;
//	float precioAerolineas;
//	float precioLATAM;
//	double BTC;
//
//	kilometros = 7090;
//	precioAerolineas = 162965.00;
//	precioLATAM = 159339.00;
//	BTC = 4606954.55;
//
//	printf("KMs Ingresados: %.2f Km\n", kilometros);
//	printf("\n");
//	printf("Precio Aerolineas: $ %.2f\n", precioAerolineas);
//	printf("a) Precio con tarjeta de débito: $ %.2f\n", calculosDePorcentajes (precioAerolineas, 10, 0));
//	printf("b) Precio con tarjeta de crédito: $ %.2f\n", calculosDePorcentajes (precioAerolineas, 25, 1));
//	printf("c) Precio pagando con bitcoin: %.8f BTC \n", calculosDeDivisas (precioAerolineas, BTC, 0));
//	printf("d) Precio unitario: $ %.2f\n", calculoPrecioUnitario (precioAerolineas, kilometros));
//	printf("\n");
//	printf("Precio Latam: $ %.2f\n", precioLATAM);
//	printf("a) Precio con tarjeta de débito: $ %.2f\n", calculosDePorcentajes (precioLATAM, 10, 0));
//	printf("b) Precio con tarjeta de crédito: $ %.2f\n", calculosDePorcentajes (precioLATAM, 25, 1));
//	printf("c) Precio pagando con bitcoin: %.8f BTC \n", calculosDeDivisas (precioLATAM, BTC, 0));
//	printf("d) Precio unitario: $ %.2f \n", calculoPrecioUnitario (precioLATAM, kilometros));
//	printf("\n");
//	printf("La diferencia de precio es: $ %.2f \n", calcularDiferencia (precioAerolineas, BTC));
//	printf("__________________________________________\n");
//	printf("\n");

