#ifndef CALCULOS_H_
#define CALCULOS_H_
#include <stdio.h>
#include <stdlib.h>
/// @brief Es la funcion que calcula un porcentaje de descuento o aumento
/// @param precio        ->Es el numero que se le pide al usuario
/// @param porcentaje    ->Es el numero de porcentaje a utilizar
/// @param auxiliar      ->Es el numero que se va a pedir para saber si es un descuento(0) o aumento(1)
/// @return resultado    ->Es el numero con el calculo hecho, devuelto

float calculosDePorcentajes(float precio,int porcentaje, int auxiliar);

/// @brief Es la funcion que calcula, en este caso, ARS a BTC
/// @param moneda         -> Es el numero de cantidad o precio de ARS
/// @param tipoDeCambio   -> El tipo de cambio en este caso BTC que ya tiene su valor en un define
/// @return resultado     -> La moneda convertida

float calculosDeDivisas(float moneda, float tipoDeCambio);

/// @brief Es la funcion que calcula un precio unitario
/// @param precio         -> Es el numero que ingresa el usuario como precio
/// @param kilometros     -> Es el numero con el cual vamos a sacar el precio unitario
/// @return resultado     -> Es la cuenta hecha retornada

float calculoPrecioUnitario(float precio, int kilometros);

/// @brief Es la funcion que calcula una diferencia o resta
/// @param precio1        -> Es el primer numero ingresado
/// @param precio2        -> Es el segundo numero ingresado
/// @return diferencia    -> Es el resultado de la resta o diferencia

float calcularDiferencia(float precio1, float precio2);
#endif /* CALCULOS_H_ */
