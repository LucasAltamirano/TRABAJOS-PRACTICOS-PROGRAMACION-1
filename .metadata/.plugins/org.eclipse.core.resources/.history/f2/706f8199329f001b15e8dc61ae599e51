/*
 * BibliotecasMenu.c
 *
 *  Created on: 14 abr. 2021
 *      Author: Lucas
 */
//
#include <stdio.h>		// biblioteca del sistema
#include <stdlib.h>
#include "Calculos.h"// biblioteca del sistema

void Menu() {

	int x;
	int y;
	int rSumaM;
	int rRestaM;
	int rMultiplicacionM;
	float rDivisionM;
	int resultadoFactorialA;
	int resultadoFactorialB;

	int controlDivision;
	int controlResultadoFactorialA;
	int controlResultadoFactorialB;

	int opcion;
	int flagOperador1;
	int flagOperador2;
	int flagCalculando;
	flagOperador1 = 0;
	flagOperador2 = 0;
	flagCalculando = 0;

	printf("\n\tLa calculadora esta lista para operar\n");

	printf("\natencion! esta calculadora fue diseñada para programar solo con numeros enteros,a excepcion del resultado de la division\n");
	do {

		printf("\n1-Ingresar 1er Operando\n");
		printf("2-Ingresar 2do Operando\n");
		printf("3-Calcular\n");
		printf("4-Mostrar todos los resultados\n");
		printf("5-Salir");

		scanf("%d", &opcion);
		switch (opcion) {
		case 1:

			printf("\nIngrese el 1er Operando (A)\n");
			scanf("%d", &x);
			printf("\t A=%d\n", x);
			flagOperador1 = 1;
			break;

		case 2:

			if (flagOperador1 == 1) {
				printf("\nIngrese el 2do Operando (B)\n ");
				scanf("%d", &y);
				printf("\t A=%d     B=%d\n", x, y);
				flagOperador2 = 1;

			} else {
				printf(
						"\n Primero tiene que ingresar el 1er (A) Operando en opcion 1 \n");
			}

			break;

		case 3:
			if (flagOperador1 != 1 || flagOperador2 != 1) {
				printf(
						" Debera ingresar los dos operadores para comenzar a operar\n ");
			} else {

				printf("\n   Calculando.......\n");
				if (Suma(x, y, &rSumaM)) {

					printf("Suma de (%d+%d)\n", x, y);
				} else {
					printf("Suma  de  (%d+%d) Operacion fallida", x, y);
				}

				if (Resta(x, y, &rRestaM)) {
					printf("Resta de  (%d-%d)\n", x, y);
				} else {
					printf("Resta de  (%d-%d) Operacion fallida", x, y);
				}

				if (Multiplicacion(x, y, &rMultiplicacionM)) {

					printf("Multiplicacion de  (%d*%d)\n", x, y);
				} else {
					printf("Multiplicacion de  (%d*%d)", x, y);
				}
				controlDivision = Division(x, y, &rDivisionM);
				if (controlDivision != 1) {
					printf("Syntax ERROR  / division por cero / \n");

				} else {
					printf("Division de (%d/ %d)\n", x, y);

				}
				controlResultadoFactorialA = Factorial(x, &resultadoFactorialA);

				if (controlResultadoFactorialA == 1) {
					printf("Factorial de A (%d)\n", x);
				} else {
					printf("Syntax ERROR");

				}
				controlResultadoFactorialB = Factorial(y, &resultadoFactorialB);
				if (controlResultadoFactorialA == 1) {
					printf("Factorial de B (%d)\n", y);
				} else {
					printf("Syntax ERROR");
				}

			}

			flagCalculando = 1;

			break;

		case 4:
			if (flagCalculando != 1) {
				printf(
						"\nPara Mostrar los resultados ,primero es necesario Calcular los mismos  en Opcion #3\n");
			}

			else {
				printf(" El resultado de %d + %d es: %d\n", x, y, rSumaM);

				printf(" El resultado de %d - %d es: %d\n", x, y, rRestaM);

				if (controlDivision != 1) {
					printf(" Syntax ERROR  / division por cero / \n");

				} else {
					printf(" El resultado de %d/ %d es: %.2f \n", x, y,
							rDivisionM);
				}

				printf(" El resultado de %d * %d es: %d\n", x, y,
						rMultiplicacionM);

				if (controlResultadoFactorialA == 1) {
					printf(" El resultado de Factorial A(%d) es: %d \n", x,
							resultadoFactorialA);
				} else {
					printf(
							"Calculadora no permite factoriar valores negativos o mayores a 12 ");
				}

				if (controlResultadoFactorialB == 1) {
					printf(" El resultado de Factorial B(%d) es: %d\n", y,
							resultadoFactorialB);
				} else {
					printf(
							"Calculadora no permite factoriar valores negativos o mayores a 12 ");
				}

			}

			break;

		case 5:
			printf("\n Saliendo...\n");
			break;

		default:

			printf("\n Ingrese una opcion valida\n");

			break;

		}

	} while (opcion != 5);
}
