/*
 * Genericas.c
 *
 *  Created on: 7 jun. 2021
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"


int levantaEnteros(int *resultado, char *mensaje, char *mensajeError,int min, int max) {
		int  aux;
		int exito = 0;
		int tipoValidado;

		if (resultado != NULL && mensaje != NULL && mensajeError != NULL
				&& min <= max) {
			do {
				printf("%s\n", mensaje);
				fflush(stdin);
				tipoValidado = scanf("%d", &aux);
				if (aux < min || aux > max || tipoValidado == 0) {
					printf("%s\n", mensajeError);
					exito = 0;
				} else {
					*resultado = aux;
					exito = 1;
					break;
				}
			} while (exito == 0);
		}
		return exito;
	}

void DesplegarMenu(int*pMenu){

	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"
			"||||                      Menu Principal                           ||||\n"
			"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"
     "|1| Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
     "|2| Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
	 "|3| Alta de empleado\n"
     "|4| Modificar datos de empleado\n"
     "|5| Baja de empleado\n"
     "|6| Listar empleados\n"
     "|7| Ordenar empleados\n"
     "|8| Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
     "|9| Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
     "|10| Sueldos superiores a 20k ,Aumentarlos en un 10 por ciento. \n"
     "|11| Salir\n");
	levantaEnteros(pMenu," ","#Error,ingrese una opcion valida",1, 11);
}

void printRecuadro (char *mensaje){

	printf("==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==\n"
			"""%s"""
		   "==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==/==\n",mensaje);
}



int inicializarCadenaCaracteres(char cadenaRecibida[], int largoCadena) {
		int exito = 0;
		int i;
		if (cadenaRecibida != NULL) {
			for (i = 0; i < largoCadena; i++) {
				cadenaRecibida[i] = ' ';
			}
			exito = 1;
		}
		return exito;
	}
int utn_levantaCadenaCaracteres(char cadena[], char *mensaje,char *mensajeError, int largoCadena) {
	int exito = 0;
	int i;
	char auxCadena[largoCadena];

	inicializarCadenaCaracteres(auxCadena, largoCadena);

	if (cadena != NULL && mensaje != NULL && mensajeError != NULL
			&& largoCadena > 0) {
		while (exito == 0) {
			printf("%s\n", mensaje);
			fflush(stdin);
			if (fgets(auxCadena, largoCadena, stdin) != NULL) {
				exito = 1;
				for (i = 0; i < largoCadena; i++) {
					if (isdigit(auxCadena[i])) {
						exito = 0;
						break;
					}
				}
				auxCadena[strcspn(auxCadena, "\n")] = 0;
				strcpy(cadena, auxCadena);
			} else {
				printf("%s\n", mensajeError);
			}
		}
	}
	return exito;
}

