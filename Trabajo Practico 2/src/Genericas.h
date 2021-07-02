/*
 * Genericas.h
 *
 *  Created on: 15 may. 2021
 *      Author: Lucas
 */

#ifndef GENERICAS_H_
#define GENERICAS_H_



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "employees.h"



void desplegarMenu();

/** \brief desplegarMenu de tipo Void
 * \ Utiliza la funcion print para desplegar un menu acorde a las necesidades
*
*/

int utn_levantaCadenaCaracteres(char cadena[], char *mensaje,char *mensajeError, int largoCadena);
/**
 * \brief valida que la cadena obtenida es FLOTANTE
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * return Retorna 0 si el numero es flotante, -1, SI ES ERROR.
 */

int getInt(int *pResultado, char *mensaje, char *mensajeError, int min, int max,int reintentos);

int inicializarCadenaCaracteres(char cadenaRecibida[], int largoCadena);
int utn_levantaDecimales(float *resultado, char *mensaje, char *mensajeError,float min, float max);
int levantaEnteros(int *resultado, char *mensaje, char *mensajeError, int min,int max, int reintentos);
void volverAtras();


#endif /* GENERICAS_H_ */
