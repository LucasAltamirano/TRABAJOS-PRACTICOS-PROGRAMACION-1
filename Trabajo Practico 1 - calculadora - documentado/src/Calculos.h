/*
 * BibliotecaUtn.h
 *
 *  Created on: 11 abr. 2021
 *      Author: Lucas
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

	/// me paro en proyecto raiz,y creo a traves de header file.h
		/// en header . h van a ir los " protottipos o headers "



int Suma(int a, int b, int *rSumaF);
/*
 * @brief suma procede a sumar dos numeros del tipo int
 * @param  parametros del tipo int consta de 2 numeros para sumar  y un puntero asginado ;
 * @return returna 1 (uno) en el caso de que la operacion se realizo exitosamente verificando que la direccion del puntero
 * se recibio correctamente , returna 0 (cero) en caso contrario .
 *
 *
 */
int Resta(int a, int b, int *rRestaF);
/*
 *  @brief resta procede a restar dos numeros del tipo int
 * @param  parametros del tipo int consta de 2 numeros para restar  y un puntero asginado ;
 * @return returna 1 (uno) en el caso de que la operacion se realizo exitosamente verificando que la direccion del puntero
 * se recibio correctamente , returna 0 (cero) en caso contrario .
 *
 *
 */
int Multiplicacion(int a, int b, int *rMultiplicacionF);
/*
 *  @brief Multiplicacion procede a Multiplicar dos numeros del tipo int
 * @param  parametros del tipo int consta de 2 numeros para Multiplicar  y un puntero asginado ;
 * @return returna 1 (uno) en el caso de que la operacion se realizo exitosamente verificando que la direccion del puntero
 * se recibio correctamente , returna 0 (cero) en caso contrario .
 *
 */
int Division(int a, int b, float *rDivisionF);
/*
 *  @brief Division procede a Division dos numeros del tipo int
 * @param  parametros del tipo int consta de 2 numeros para Multiplicar  y un puntero asginado del tipo de daato float;
 * @return returna 1 (uno) en el caso de que la operacion se realizo exitosamente verificando que la direccion del puntero
 * se recibio correctamente y el paramenttro "b" sea distinto de cero , returna 0 (cero) en caso contrario .
 */
int Factorial(int a, int *punteroFactorial);
/*
 * @brief Factorial procede a Factoriar un numero  del tipo int
 * @param  parametros del tipo int consta de 1 numeros para factoriar  y un puntero asginado ;
 * @return returna 1 (uno) en el caso de que la operacion se realizo exitosamente verificando que la direccion del puntero
 * se recibio correctamente y el paramenttro recibido "a" no sea numero negativo ni mayor a 12 , returna 0 (cero) en caso contrario .
 */
int Factorial(int b, int *punteroFactorial);
/*
 *  @brief Factorial procede a Factoriar un numero  del tipo int
 * @param  parametros del tipo int consta de 1 numeros para factoriar  y un puntero asginado ;
 * @return returna 1 (uno) en el caso de que la operacion se realizo exitosamente verificando que la direccion del puntero
 * se recibio correctamente y el paramenttro recibido "b" no sea numero negativo ni mayor a 12 , returna 0 (cero) en caso contrario .
 */
#endif /* CALCULOS_H_ */
