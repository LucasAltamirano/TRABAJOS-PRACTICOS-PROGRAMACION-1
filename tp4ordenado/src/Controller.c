#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Genericas.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	int E = 0;
	ll_clear(pArrayListEmployee);
	FILE *punteroFileTexto;

	punteroFileTexto = fopen(path, "r");

	if (punteroFileTexto != NULL) {
		E = 1;
		if (parser_EmployeeFromText(punteroFileTexto, pArrayListEmployee)) {
			fclose(punteroFileTexto);
		}

	} else {
		printf("#Error al abrir archivo en modo Texto\n");
		system("pause");
	}

	return E;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	int E = 0;
	ll_clear(pArrayListEmployee);
	FILE *punteroFileBinario;
	punteroFileBinario = fopen(path, "rb");

	if (punteroFileBinario != NULL) {
		E = 1;
		if (parser_EmployeeFromBinary(punteroFileBinario, pArrayListEmployee)) {
			fclose(punteroFileBinario);
		}
	} else {
		printf("#Error al abrir archivo en modo binario\n");
		system("pause");
	}
	return E;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee) {
	int E;
	Employee *pEmpleado;
	Employee *dmUltimoEmpleado;
	int longitud;
	int retornoId;
	int idMayor=0;
	int i;
	char auxNombre[128] = " ";
	int auxHorasTrabajadas = 0;
	int auxSueldo;


	if (pArrayListEmployee != NULL) {

		pEmpleado = employee_new();
		if (pEmpleado != NULL) {
			E=1;
			longitud = ll_len(pArrayListEmployee);

			for (i = 0; i < longitud; i++) {

				dmUltimoEmpleado = ll_get(pArrayListEmployee, i);
				employee_getId(dmUltimoEmpleado, &retornoId);
				if (i == 0 || retornoId > idMayor) {

					idMayor = retornoId;
				}
			}
			idMayor++;
			employee_setId(pEmpleado, idMayor);

			utn_levantaCadenaCaracteres(auxNombre,
					"Ingrese nombre del nuevo empleado", "#Error,verifique",
					128);
			employee_setNombre(pEmpleado, auxNombre);

			levantaEnteros(&auxHorasTrabajadas,
					"Ingrese Horas trabajadas del nuevo empleado",
					"#Error,verifique", 1, 500);
			employee_setHorasTrabajadas(pEmpleado, auxHorasTrabajadas);

			levantaEnteros(&auxSueldo, "Ingrese sueldo del nuevo empleado",
					"#Error,verifique", 1000, 500000);
			employee_setSueldo(pEmpleado, auxSueldo);
			ll_add(pArrayListEmployee, (Employee*) pEmpleado);
		}
	}

	return E;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee) {

	Employee *auxModificacionEmpleado;
	int E;
	int cantidadNodos;
	int i;
	int cantidadId;

	char auxNombreModificacion[128];
	int auxHsTrabajadasModificacion;
	int auxSueldoModificacion;

	int idReferencia;
	int idModificar;
	int flagIdCoincide = 0;
	int datomodificar;

	int confirma;

	if (pArrayListEmployee == NULL) {

		printf("#Error,verifique nuevamente");
		system("pause");
	} else {

		cantidadNodos = ll_len(pArrayListEmployee);

		for (i = 0; i < cantidadNodos; i++) {

			auxModificacionEmpleado = ll_get(pArrayListEmployee, i);
			employee_getId(auxModificacionEmpleado, &cantidadId);
			if (i == 0 || cantidadId > idReferencia) {

				idReferencia = cantidadId;
			}
		}
		printf("|||Modificacion de empleado por Id|||\n");
		levantaEnteros(&idModificar, "Ingrese el Id que desea Modificar",
				"ingrese un id valido", 1, idReferencia);

		if (pArrayListEmployee != NULL && cantidadNodos > 0&& idModificar > 0) {
				E=1;
			for (i = 0; i < cantidadNodos; i++) {
				auxModificacionEmpleado = ll_get(pArrayListEmployee, i);
				if ((*auxModificacionEmpleado).id == idModificar) {
					flagIdCoincide = 1;
					break;
				}

			}
		}
		if (flagIdCoincide != 1) {
			printf("#Error,Id inexistente verifique\n");
		} else {

			printf("|||		datos del Empleado			|||\n");
			printf("|IdEmpleado    |Nombre      |Hs Trabajadas   |Sueldo\n");
			printf(" %-15d%-13s%-17d%-17d\n", (*auxModificacionEmpleado).id,
					(*auxModificacionEmpleado).nombre,
					(*auxModificacionEmpleado).horasTrabajadas,
					(*auxModificacionEmpleado).sueldo);

			levantaEnteros(&datomodificar,
					"Ingrese el campo que desea modificar\n"
							"|1|Nombre\n"
							"|2|Hs Trabajadas\n"
							"|3|Salario\n"
							"|4|Cancelar modificacion de datos\n",
					"#Error,ingrese opcion valida", 1, 4);

			switch (datomodificar) {
			case 1:
				utn_levantaCadenaCaracteres(auxNombreModificacion,"Ingrese el nuevo nombre", "#Error,verifique", 128);
				printf("Nombre Ingresado:%s\n",auxNombreModificacion);
				levantaEnteros(&confirma,"Desea guardar los cambios?\n"
						"|1|Aceptar\n"
						"|2|Cancelar\n", "#Error,ingrese opcion valida", 1, 2);
				if(employee_setNombre(auxModificacionEmpleado,
						auxNombreModificacion))
				{printRecuadro("Datos guardados Exitosamente!\n");
				}else{
					printRecuadro("Cancelado por el usuario\n");
							system("pause");

				}
				break;
			case 2:
				levantaEnteros(&auxHsTrabajadasModificacion,
						"Ingrese Horas trabajadas del nuevo empleado",
						"#Error,verifique", 1, 500);
				printf("Hs trabajadas Ingresadas:%d\n",auxHsTrabajadasModificacion);
				levantaEnteros(&confirma,"Desea guardar los cambios?\n"
										"|1|Aceptar\n"
										"|2|Cancelar\n", "#Error,ingrese opcion valida", 1, 2);
				if(employee_setHorasTrabajadas(auxModificacionEmpleado,
						auxHsTrabajadasModificacion)){
					printRecuadro("Datos guardados Exitosamente!\n");
									}else{
										printRecuadro("Cancelado por el usuario\n");
												system("pause");
				}
				break;
			case 3:
				levantaEnteros(&auxSueldoModificacion,
						"Ingrese sueldo del nuevo empleado", "#Error,verifique",
						1000, 500000);
				printf("nuevo sueldo Ingresado:%d\n",auxSueldoModificacion);
				levantaEnteros(&confirma,"Desea guardar los cambios?\n"
														"|1|Aceptar\n"
														"|2|Cancelar\n", "#Error,ingrese opcion valida", 1, 2);

				if(employee_setSueldo(auxModificacionEmpleado,
						auxSueldoModificacion)){
					printRecuadro("Datos guardados Exitosamente!\n");
				}else{
					printRecuadro("Cancelado por el usuario\n");
							system("pause");
				}

				break;
			case 4:
				printf("Modificacion de datos cancelado por el usuario\n");
				system("pause");
				break;

			}
		}
	}
	return E;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {

	Employee *auxEliminacionEmpleado;
	int E;
	int i;
	int cantidadNodos;
	int cantidadId;
	int idReferencia;

	int EliminacionporId;
	int confirmacionEliminacion;
	int flagIdCoincide = 0;
	int indexEliminacion;

	if (pArrayListEmployee == NULL) {
		printf("#Error,verifique nuevamente");
		system("pause");
	} else {

		cantidadNodos = ll_len(pArrayListEmployee);
		E=1;
		for (i = 0; i < cantidadNodos; i++) {

			auxEliminacionEmpleado = ll_get(pArrayListEmployee, i);
			employee_getId(auxEliminacionEmpleado, &cantidadId);
			if (i == 0 || cantidadId > idReferencia) {

				idReferencia = cantidadId;
			}
		}

		printf("|||Eliminacion de empleado por Id|||\n");

		levantaEnteros(&EliminacionporId, "Ingrese el Id que desea Eliminar",
				"ingrese un id valido", 1, idReferencia);

		if (pArrayListEmployee != NULL && cantidadNodos > 0	&& EliminacionporId > 0) {
			E=1;
			for (i = 0; i < cantidadNodos; i++) {
				auxEliminacionEmpleado = ll_get(pArrayListEmployee, i);
				if ((*auxEliminacionEmpleado).id == EliminacionporId) {
					indexEliminacion = i;
					flagIdCoincide = 1;
					break;
				}

			}

			if (flagIdCoincide != 1) {
				printf("#Error,Id inexistente verifique\n");
			} else {
				printf("|||		datos del Empleado			|||\n");
				printf(
						"|IdEmpleado    |Nombre      |Hs Trabajadas   |Sueldo\n");
				printf(" %-15d%-13s%-17d%-17d\n", (*auxEliminacionEmpleado).id,
						(*auxEliminacionEmpleado).nombre,
						(*auxEliminacionEmpleado).horasTrabajadas,
						(*auxEliminacionEmpleado).sueldo);

				levantaEnteros(&confirmacionEliminacion,
						"Desea confirmar la elminacion del empleado\n"
								"|1|Aceptar\n"
								"|2|Cancelar\n",
						"#Error,ingrese opcion valida\n", 1, 2);

				if (confirmacionEliminacion != 1) {
					printf(
							"Eliminacion de Empleado cancelada por el usuario\n");
					system("pause");
				} else {
					printf("Eliminacion de Empleado en proceso aguarde...\n");
					ll_remove(pArrayListEmployee, indexEliminacion);

				}
				employee_delete(auxEliminacionEmpleado);
			}
		}
	}

	return E;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee) {

	int largoDeLista;
	int i;
	int E;
	int auxPrintId;
	char auxPrintNombre[128];
	int auxPrintHorasTrabajadas;
	int auxPrintSueldo;

	largoDeLista = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && largoDeLista>0){
		E=1;
	printf("|||		datos del Empleado			|||\n");
	printf("|IdEmpleado    |Nombre      |Hs Trabajadas   |Sueldo\n");
	for (i = 0; i < largoDeLista; i++) {
		Employee *auxPrintEmpleados = ll_get(pArrayListEmployee, i);
		employee_getId(auxPrintEmpleados, &auxPrintId);
		employee_getNombre(auxPrintEmpleados, auxPrintNombre);
		employee_getHorasTrabajadas(auxPrintEmpleados,
				&auxPrintHorasTrabajadas);
		employee_getSueldo(auxPrintEmpleados, &auxPrintSueldo);
		printf(" %-15d%-13s%-17d%-17d\n", auxPrintId, auxPrintNombre,
				auxPrintHorasTrabajadas, auxPrintSueldo);

		//printf("%s     %s    %s    %s    ");
	}
	}
	return E;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {

	int E=0;
	Employee *pComparo1;
	Employee *pComparo2;

	int i, j;
	int cantidadNodos;

	int ordenarPor;
	int ascOdesc;

	int Buffer1;
	int Buffer2;

	char Buffer1C[128];
	char Buffer2C[128];

	int bufferHS1;
	int bufferHS2;

	int buffersueldo1;
	int buffersueldo2;

	levantaEnteros(&ordenarPor, "|||Ordenamiento de datos|||\n"
			"--->Indique el dato que desea ordenar\n"
			"|1|Ordenar por ID\n"
			"|2|Ordenar por Nombre\n"
			"|3|Ordenar por Hs trabajadas\n"
			"|4|Ordenar por Sueldo\n"
			"|5|Cancelar ordenamiento\n", "#Error ingrese una opcion valida", 1,
			5);
	levantaEnteros(&ascOdesc, "--->Indique el criterio de ordenamiento\n"
			"|1|De manera ascendente\n"
			"|2|De manera descendente\n"
			"|3|Volver atras\n", "#Error ingrese una opcion valida", 1, 3);

	cantidadNodos = ll_len(pArrayListEmployee);

	if (pArrayListEmployee != NULL && cantidadNodos > 0) {
		E=1;
		switch (ordenarPor) {
		case 1:

			if (ascOdesc == 1) {

				for (i = 0; i < cantidadNodos - 1; i++) {

					for (j = i + 1; j < cantidadNodos; j++) {
						pComparo1 = ll_get(pArrayListEmployee, i);
						pComparo2 = ll_get(pArrayListEmployee, j);
						employee_getId(pComparo1,&Buffer1);
						employee_getId(pComparo2,&Buffer2);
						if (Buffer1 > Buffer2) {

							ll_set(pArrayListEmployee, i, pComparo2);
							ll_set(pArrayListEmployee, j, pComparo1);
						}
					}
				}
			}

			if (ascOdesc == 2) {

				for (i = 0; i < cantidadNodos - 1; i++) {

					for (j = i + 1; j < cantidadNodos; j++) {
						pComparo1 = ll_get(pArrayListEmployee, i);
						pComparo2 = ll_get(pArrayListEmployee, j);
						employee_getId(pComparo1,&Buffer1);
						employee_getId(pComparo2,&Buffer2);
						if (Buffer1 < Buffer2) {

							ll_set(pArrayListEmployee, i, pComparo2);
							ll_set(pArrayListEmployee, j, pComparo1);
						}
					}
				}
				}
				break;

				case 2:

					if (ascOdesc == 1) {

						for (i = 0; i < cantidadNodos - 1; i++) {

							for (j = i + 1; j < cantidadNodos; j++) {
								pComparo1 = ll_get(pArrayListEmployee, i);
								pComparo2 = ll_get(pArrayListEmployee, j);
								employee_getNombre(pComparo1, Buffer1C);
								employee_getNombre(pComparo2, Buffer2C);
								if (strcmp(Buffer1C,Buffer2C)>0) {

									ll_set(pArrayListEmployee, i, pComparo2);
									ll_set(pArrayListEmployee, j, pComparo1);
								}
							}
						}
					}

					if (ascOdesc == 2) {

						for (i = 0; i < cantidadNodos - 1; i++) {

							for (j = i + 1; j < cantidadNodos; j++) {
								pComparo1 = ll_get(pArrayListEmployee, i);
								pComparo2 = ll_get(pArrayListEmployee, j);
								employee_getNombre(pComparo1,Buffer1C);
								employee_getNombre(pComparo2,Buffer2C);
								if (strcmp(Buffer2C,Buffer1C)>0) {

									ll_set(pArrayListEmployee, i, pComparo2);
									ll_set(pArrayListEmployee, j, pComparo1);
								}
							}
						}
						}
						break;

				case 3:
					if (ascOdesc == 1) {

										for (i = 0; i < cantidadNodos - 1; i++) {

											for (j = i + 1; j < cantidadNodos; j++) {
												pComparo1 = ll_get(pArrayListEmployee, i);
												pComparo2 = ll_get(pArrayListEmployee, j);
												employee_getHorasTrabajadas(pComparo1, &bufferHS1);
												employee_getHorasTrabajadas(pComparo2, &bufferHS2);
												if (bufferHS1>bufferHS2) {

													ll_set(pArrayListEmployee, i, pComparo2);
													ll_set(pArrayListEmployee, j, pComparo1);
												}
											}
										}
									}

									if (ascOdesc == 2) {

										for (i = 0; i < cantidadNodos - 1; i++) {

											for (j = i + 1; j < cantidadNodos; j++) {
												pComparo1 = ll_get(pArrayListEmployee, i);
												pComparo2 = ll_get(pArrayListEmployee, j);
												employee_getHorasTrabajadas(pComparo1,&bufferHS1);
												employee_getHorasTrabajadas(pComparo2, &bufferHS2);
												if (bufferHS1<bufferHS2)  {

													ll_set(pArrayListEmployee, i, pComparo2);
													ll_set(pArrayListEmployee, j, pComparo1);
												}
											}
										}
										}
										break;

				case 4:

					if (ascOdesc == 1) {

								for (i = 0; i < cantidadNodos - 1; i++) {

									for (j = i + 1; j < cantidadNodos; j++) {
										pComparo1 = ll_get(pArrayListEmployee, i);
										pComparo2 = ll_get(pArrayListEmployee, j);
										employee_getSueldo(pComparo1, &buffersueldo1);
										employee_getSueldo(pComparo2, &buffersueldo2);
										if (buffersueldo1>buffersueldo2) {

											ll_set(pArrayListEmployee, i, pComparo2);
											ll_set(pArrayListEmployee, j, pComparo1);
										}
									}
								}
							}

							if (ascOdesc == 2) {

								for (i = 0; i < cantidadNodos - 1; i++) {

									for (j = i + 1; j < cantidadNodos; j++) {
										pComparo1 = ll_get(pArrayListEmployee, i);
										pComparo2 = ll_get(pArrayListEmployee, j);
										employee_getSueldo(pComparo1,&buffersueldo1);
										employee_getSueldo(pComparo2,&buffersueldo2);
										if (buffersueldo1<buffersueldo2)  {

											ll_set(pArrayListEmployee, i, pComparo2);
											ll_set(pArrayListEmployee, j, pComparo1);
										}
									}
								}
								}
								break;


				case 5:
				system("pause");
				break;

			}

		}
		return E;
	}

	/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
	 *
	 * \param path char*
	 * \param pArrayListEmployee LinkedList*
	 * \return int
	 *
	 */
	int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
		FILE *punteroFileTexto;
		Employee *punteroBuffer;
		int cantNodos;
		int i;
		int bufferId;
		char bufferNombre[128];
		int bufferHsTrabajo;
		int bufferSueldo;
		int E = 0;

		punteroFileTexto = fopen(path, "w");
		cantNodos = ll_len(pArrayListEmployee);

		if (punteroFileTexto != NULL
				&& cantNodos > 0&& pArrayListEmployee!=NULL && path!=NULL) {
			E = 1;
			fprintf(punteroFileTexto, "id,nombre,horasTrabajadas,sueldo\n");
			for (i = 0; i < cantNodos; i++) {

				punteroBuffer = ll_get(pArrayListEmployee, i);
				employee_getId(punteroBuffer, &bufferId);
				employee_getNombre(punteroBuffer, bufferNombre);
				employee_getHorasTrabajadas(punteroBuffer, &bufferHsTrabajo);
				employee_getSueldo(punteroBuffer, &bufferSueldo);
				fprintf(punteroFileTexto, "%d,%s,%d,%d\n", bufferId,
						bufferNombre, bufferHsTrabajo, bufferSueldo);

			}
			fclose(punteroFileTexto);
		}

		return E;
	}

	/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
	 *
	 * \param path char*
	 * \param pArrayListEmployee LinkedList*
	 * \return int
	 *
	 */
	int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {

		FILE *punteroFileBinario;
		Employee *punteroBuffer;
		int cantNodos;
		int i;
		int bufferId;
		char bufferNombre[128];
		int bufferHsTrabajo;
		int bufferSueldo;
		int E = 0;

		punteroFileBinario = fopen(path, "wb");
		cantNodos = ll_len(pArrayListEmployee);

		if (punteroFileBinario != NULL
				&& cantNodos > 0&& pArrayListEmployee!=NULL && path!=NULL) {
			E = 1;
			fprintf(punteroFileBinario, "id,nombre,horasTrabajadas,sueldo\n");
			for (i = 0; i < cantNodos; i++) {

				punteroBuffer = ll_get(pArrayListEmployee, i);
				employee_getId(punteroBuffer, &bufferId);
				employee_getNombre(punteroBuffer, bufferNombre);
				employee_getHorasTrabajadas(punteroBuffer, &bufferHsTrabajo);
				employee_getSueldo(punteroBuffer, &bufferSueldo);
				fprintf(punteroFileBinario, "%d,%s,%d,%d\n", bufferId,
						bufferNombre, bufferHsTrabajo, bufferSueldo);

			}
			fclose(punteroFileBinario);
		}
		return E;
	}

int controller_aumentaSueldo(LinkedList* empleados)
{
	int E=0;
	LinkedList* sueldoConAumento=NULL;

	if(empleados!=NULL)
	{
		sueldoConAumento=ll_map(empleados,employee_aumentaSueldo);
		E=1;
	}

	controller_saveAsText("ListaConAumento.csv",sueldoConAumento);
	ll_deleteLinkedList(sueldoConAumento);

	return E;
}
