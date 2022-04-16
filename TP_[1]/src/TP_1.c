/*
ENUNCIADO
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerol�neas Argentinas
para ofrecerlos a sus clientes.
Se deber� ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicaci�n es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciar� y contar� con un men� de opciones:

1. Ingresar Kil�metros: ( km=x )
2. Ingresar Precio de Vuelos: (Aerol�neas=y, Latam=z)
- Precio vuelo Aerol�neas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de d�bito (descuento 10%)
b) Tarjeta de cr�dito (inter�s 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerol�neas)
4. Informar Resultados
�Latam:
a) Precio con tarjeta de d�bito: r
b) Precio con tarjeta de cr�dito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerol�neas:
a) Precio con tarjeta de d�bito: r
b) Precio con tarjeta de cr�dito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r �
5. Carga forzada de datos
6. Salir

ACLARACIONES DEL FUNCIONAMIENTO
El men� se tiene que ver tal cual est� descrito en la consigna. Los resultados se tienen que
mostrar con el mismo formato. Se puede realizar un submen� para ingresar los km y los
precios.
Los resultados se tienen que ver con el formato presentado en el men�.
==============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#define valorBTC 4606954.55
#include "validaciones.h"
#include "funciones.h"
#include "calculos.h"


int main(void) {
	setbuf(stdout, NULL);
	int opcionDelMenu;
	char respuesta;
	// variables de la opci�n 1
	float kilometros;
    float flagKilometros = 0;
	// variables de la opci�n 2
	float precioDeVueloAerolineas = 0;
	int flagPrecioDeVueloAerolineas = 0;
	float precioDeVueloLatam = 0;
	int flagPrecioDeVueloLatam = 0;
	char empresaDeVuelo;
	// variables de la opci�n 3
	float precioLatamConTDeDebito;
	float precioAerolineasConTDeDebito;
	float precioLatamConTDeCredito;
	float precioAerolineasConTDeCredito;
	float precioUnitarioLatam = 0;
	float precioUnitarioAerolineas = 0;
	float diferenciaDePrecio = 0;
	double precioEnBTCLatam = 0;
	double precioEnBTCAerolineas = 0;
	// variables de la opci�n 5
	int flagCargaForzada = 0;

    respuesta = validacionDeOpcionChar("Programa de costos de vuelo.\n","ERROR. Ingrese opci�n correcta(i-ingresar/s-salir).\n","[I]Iniciar programa.\n","[S]Salir.\n",'I','S');
// Men� principal del programa:
    while(respuesta == 'I'){
    	printf("\n");
    	printf("__________________________________________\n");
    	printf("\n");
    	printf("	     [MENU  PRINCIPAL]\n");
    	printf("__________________________________________\n");
    	printf("\n");
    	printf("Ingrese opci�n: \n");
        printf("[1]Ingresar kil�metros.\n");
    	printf("[2]Ingresar precio de vuelo.\n");
        printf("[3]Calcular todos los costos.\n");
        printf("[4]Informar resultados.\n");
        printf("[5]Cargar forzadamente datos.\n");
        printf("[6]Salir.\n");
        scanf("%d", &opcionDelMenu);

        opcionDelMenu = validacionInt(opcionDelMenu,1,6);
        switch(opcionDelMenu){
        case 1:
        	if(flagCargaForzada == 1)
        	{
        		printf("ERROR. Usted ya carg� datos forzadamente, vuelva al men� principal.");

        	}
        	else
        	{
        		kilometros = validacionFloat("Ingrese kil�metros: \n", "ERROR. Ingresar kil�metros v�lidos: \n");
        		flagKilometros = 1;
        	}
        	break;

        case 2:
        	if(flagCargaForzada == 1)
        	{
        		printf("ERROR. Usted ya carg� datos forzadamente, vuelva al men� principal.");
        	}
        	else
        	{
        	empresaDeVuelo = validacionDeOpcionChar("�De qu� empresa es el vuelo?\n", "ERROR. Opci�n no v�lida.\n", "[Y]Aerol�neas","[Z]LatAm",'Y','Z');
        	if(empresaDeVuelo == 'Y')
        	{
        	    precioDeVueloAerolineas = validacionFloat("Ingrese el precio del vuelo con Aerol�neas:\n","ERROR. Ingrese precio v�lido.\n");
        	    flagPrecioDeVueloAerolineas = 1;
        	}
        	else
        	{
        		precioDeVueloLatam = validacionFloat("Ingrese el precio del vuelo con LatAm:\n","ERROR. Ingrese precio v�lido.\n");
        		flagPrecioDeVueloLatam = 1;
        	}
        	}


        	break;
        case 3:
        	if((flagPrecioDeVueloLatam == 1 || flagPrecioDeVueloAerolineas == 1) && flagKilometros == 1)
        	{
        	// punto A vuelos con debito
        	precioLatamConTDeDebito = calculosDePorcentajes(precioDeVueloLatam,10,0);
        	precioAerolineasConTDeDebito = calculosDePorcentajes(precioDeVueloAerolineas,10,0);
        	// punto B vuelos con credito
        	precioLatamConTDeCredito = calculosDePorcentajes(precioDeVueloLatam,25,1);
        	precioAerolineasConTDeCredito = calculosDePorcentajes(precioDeVueloAerolineas,25,1);
        	// punto C BITCOIN
        	precioEnBTCLatam = calculosDeDivisas(precioDeVueloLatam, valorBTC);
        	precioEnBTCAerolineas = calculosDeDivisas(precioDeVueloAerolineas, valorBTC);

        	// punto D precio unitario
        	precioUnitarioLatam = calculoPrecioUnitario(precioDeVueloLatam,kilometros);
        	precioUnitarioAerolineas = calculoPrecioUnitario(precioDeVueloAerolineas,kilometros);
        	// punto E
        	diferenciaDePrecio = calcularDiferencia(precioDeVueloLatam,precioDeVueloAerolineas);
        	printf(".\n");
        	printf("..\n");
        	printf("...\n");
        	printf(".\n");
        	printf("..\n");
        	printf("...\n");
        	printf(".\n");
        	printf("..\n");
        	printf("...\n");
        	printf("Calculando costos...\n");
        	}
        	else
        	{
        		printf("Error. No se pueden calcular los costos, vuelva al men� principal.");
        	}
        	break;
        case 4:
            // PUNTO 4
        	if((flagPrecioDeVueloLatam == 1 || flagPrecioDeVueloAerolineas == 1) && flagKilometros == 1)
        	{
        	printf("KMs Ingresados: %.f Km\n", kilometros);
        	printf("\n");
        	printf("Precio Aerolineas: $ %.2f\n", precioDeVueloAerolineas);
        	printf("a) Precio con tarjeta de d�bito: $ %.2f\n", precioAerolineasConTDeDebito);
        	printf("b) Precio con tarjeta de cr�dito: $ %.2f\n", precioAerolineasConTDeCredito);
        	printf("c) Precio pagando con bitcoin: %.8f BTC \n", precioEnBTCAerolineas);
        	printf("d) Precio unitario: $ %.2f\n", precioUnitarioAerolineas);
        	printf("\n");
        	printf("Precio Latam: $ %.2f\n", precioDeVueloLatam);
        	printf("a) Precio con tarjeta de d�bito: $ %.2f\n", precioLatamConTDeDebito);
        	printf("b) Precio con tarjeta de cr�dito: $ %.2f\n", precioLatamConTDeCredito);
        	printf("c) Precio pagando con bitcoin: %.8f BTC \n", precioEnBTCLatam);
        	printf("d) Precio unitario: $ %.2f \n", precioUnitarioLatam);
            printf("\n");
        	printf("La diferencia de precio es: $ %.2f \n", diferenciaDePrecio);
        	printf("__________________________________________\n");
        	printf("\n");
        	}
        	else
        	{
        		printf("ERROR. Todav�a no se calcularon los datos para realizar un informe o ya los carg� forzosamente.");
        	}
        	break;
        case 5:
        	if((flagPrecioDeVueloLatam == 1 || flagPrecioDeVueloAerolineas == 1) && flagKilometros == 1)
        	{
        		printf("ERROR.Ya ingres� datos manualmente, vuelva al men� principal.");
        	}
        	else
        	{
        	printf("Carga forzada de datos:\n");
        	cargaForzada();
        	flagCargaForzada = 1;
        	}
        	break;
        case 6:
        	respuesta = 'S';
        	break;
        }
    }
    if(respuesta == 'S')
    {
    	printf("Sali� del programa, vuelva pronto uwu.");
    }

	return EXIT_SUCCESS;
}



