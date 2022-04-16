#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
#include <stdio.h>
#include <stdlib.h>


//	> Funcion validacion de dos opciones de char
/// @brief Recibe mensajes a mostrar y otorga dos opciones entre las cuales elegir y la valida
///
/// @param mensaje			-> es el mensaje que muestro al usuario la primera vez para que ingrese una letra
/// @param mensajeError		-> es el mensaje que se mostrara siempre que el valor ingresado sea erroneo
/// @param mensajeOpcion1	-> es el mensaje a mostrar para la opcion uno
/// @param mensajeOpcion2	-> es el mensaje a mostrar para la opcion dos
/// @param opcion1		-> es el char a ingresar para esta opcion
/// @param opcion2		-> es el char a ingresar para esta opcion
/// @return respuesta		-> es el resultado de la opcion elegida y es devuelto

char validacionDeOpcionChar(char mensaje[], char mensajeError[], char mensajeOpcion1[], char mensajeOpcion2[], char opcion1, char opcion2);

/// @brief Recibe un numero y valida que esté entre el numero minimo y el maximo.
/// @param numero    -> numero que ingresa el usuario
/// @param minimo    -> numero minimo
/// @param maximo    -> numero maximo
/// @return numero   -> retorna numero validado entre el minimo y maximo

int validacionInt(int numero, int minimo, int maximo);

/// @brief Valida que sea un numero flotante mayor a 0
/// @param mensaje         -> Es el mensaje que se mostrará al usuario para pedirle que ingrese un numero
/// @param mensajeError    -> Es el mensaje de error que se mostrará cuando el valor sea erróneo
/// @return numero         -> Es el numero validado devuelto.

float validacionFloat(char mensaje[], char mensajeError[]);

#endif /* VALIDACIONES_H_ */
