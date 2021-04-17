/*

 *//*
 * BibliotecaUtn.c
 *
 *  Created on: 8 abr. 2021
 *      Author: Lucas
 */

// ME PARO en el proyecto master, creo la carpeta a travez de source file. c
/// y pego todos los desarrollos de las funciones aplicadas .
/// importante ///
// como aca estoy usando funciones prpias del lenguaje, como por ejemplo print,
//if, tengo que traer Ada las bibiliotecas del sistema.
//
#include <stdio.h>		// biblioteca del sistema
// biblioteca del sistema
#include <stdlib.h>

int Suma(int a, int b, int *rSumaF) {

	int ok;
	int resultado;
	ok = 0;

	if (rSumaF != NULL) {
		resultado = a + b;
		*rSumaF = resultado;
		ok = 1;
	}

	return ok;

}

int Resta(int a, int b, int *rRestaF) {
	int ok;
	int resultado;
	ok = 0;

	if (rRestaF != NULL) {
		resultado = a - b;
		*rRestaF = resultado;
		ok = 1;
	}
	return ok;
}

int Multiplicacion(int a, int b, int *rMultiplicacionF) {

	int ok;
	int resultado;
	ok = 0;

	if (rMultiplicacionF != NULL) {
		resultado = a * b;
		*rMultiplicacionF = resultado;
		ok = 1;
	}
	return ok;
}

int Division(int a, int b, float *rDivisionF) {

	int ok;
	float resultado;
	ok = 0;

	if (rDivisionF != NULL && b != 0) {

		resultado = (float) a / b;
		*rDivisionF = resultado;
		ok = 1;
	}
	return ok;
}

int Factorial(int a, int *punteroFactorial) {
	int ok;
	int factorial;
	factorial = 1;
	ok = 0;
	if (a >= 0 && a < 12) {
		for (int i = 1; i <= a; i++) {
			factorial = factorial * i;
		}
		*punteroFactorial = factorial;
		ok = 1;

	}

	return ok;
}

