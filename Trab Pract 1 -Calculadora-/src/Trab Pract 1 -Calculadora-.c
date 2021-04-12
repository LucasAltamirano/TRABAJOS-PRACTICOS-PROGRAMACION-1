/*
 ============================================================================

 Author      : ALTAMIRANO LUCAS DIC 1 E

 	 	 	 TRABAJO PRACTICO 1 " CALCULADORA !
  Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
 1. Ingresar 1er operando (A=x)
 2. Ingresar 2do operando (B=y)
 3. Calcular todas las operaciones
 a) Calcular la suma (A+B)
 b) Calcular la resta (A-B)
 c) Calcular la division (A/B)
 d) Calcular la multiplicacion (A*B)
 e) Calcular el factorial (A!)
 4. Informar resultados
 a) “El resultado de A+B es: r”
 b) “El resultado de A-B es: r”
 c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 d) “El resultado de A*B es: r”
 e) “El factorial de A es: r1 y El factorial de B es: r2”
 5. Salir
 • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
 que contenga las funciones para realizar las cinco operaciones.
 • En el menú deberán aparecer los valores actuales cargados en los operandos A y B
 (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
 • Deberán contemplarse los casos de error (división por cero, etc)
 • Documentar todas las funciones

 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

		int x;
		int y;
		int rInt;
		float rFloat;

		int opcion;




		do {

		printf("\n\tLa calculadora esta lista\n");

		printf("Ingresar 1er Operando\n");
		scanf(" %d", &x);

		printf("Ingresar 2do Operando\n");
		scanf(" %d", &y);


			printf("\n------Eligir Operacion-----\n");
			printf("1- Suma\n");
			printf("2- Resta\n");
			printf("3- Multiplicacion \n");
			printf("4- Division\n");
			printf("5- Factorial\n");

			fflush(stdin);

			scanf("%d", &opcion);

			switch (opcion) {
			case 1:
				printf("1- Suma\n");


				break;

			case 2:
				printf("2- Resta\n");
				break;

			case 3:
				printf("3- Multiplicacion \n");
				break;
			case 4:

				printf("4- Division\n");
				break;
			case 5:
				//factorial
				printf("5- Factorial\n");
				break;


			}



		}while(opcion);

		return EXIT_SUCCESS;


	return EXIT_SUCCESS;
}
