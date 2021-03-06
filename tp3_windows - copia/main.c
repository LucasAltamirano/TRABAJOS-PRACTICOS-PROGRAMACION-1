#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Genericas.h"

/****************************************************
 Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 5. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

int main() {
	setbuf(stdout, NULL);

	int option = 0;
	int flagAbm = 0;
	int flagCarga = 0;
	int cargarSguardar;
	LinkedList *listaEmpleados = ll_newLinkedList();
	do {

		DesplegarMenu(&option);

		switch (option) {
		case 1:
			if (flagAbm == 1) {
				printRecuadro(
						" #Atencion# si carga el texto sin antes guardar se perderan los datos cargados hasta el momento\n ");
				levantaEnteros(&cargarSguardar, "desea continuar sin guardar?\n"
						"|1|Aceptar\n"
						"|2|Cancelar\n", "#Error ingrese opcion valida", 1, 2);
			}
			if (cargarSguardar != 2) {

				if (controller_loadFromText("data.csv", listaEmpleados)) {
					printRecuadro(
							"Carga de Archivo en modo texto finalizado con exito\n");
					flagCarga = 1;
				} else {
					printRecuadro(
							"#Error al cargar el archivo en modo texto verifique\n");
				}
			} else {
				system("pause");
			}

			break;
		case 2:
			if (flagAbm == 1) {
				printRecuadro(
						" #Atencion# si carga el texto sin antes guardar se perderan los datos cargados hasta el momento \n");
				levantaEnteros(&cargarSguardar, "desea continuar sin guardar?\n"
						"|1|Aceptar\n"
						"|2|Cancelar\n", "#Error ingrese opcion valida", 1, 2);
			}
			if (cargarSguardar != 2) {
				if (controller_loadFromBinary("data.bin", listaEmpleados)) {
					printRecuadro(
							"Carga de Archivo en modo binario finalizado con exito\n");
					flagCarga = 1;
				} else {
					printRecuadro(
							"#Error al cargar el archivo en modo binario verifique\n");
				}

			} else {
				system("pause");
			}
			break;
		case 3:

			if (controller_addEmployee(listaEmpleados)) {
				printRecuadro("Se agrego un empleado de manera exitosa\n");
				flagAbm = 1;
			} else {
				printRecuadro("#Error al cargar nuevo empleado\n");
			}

			break;
		case 4:
			if (controller_editEmployee(listaEmpleados)) {
				printRecuadro("Datos actualizados\n");
			} else {
				printRecuadro("#Error en actualizacion de datos verifique\n");
			}

			break;
		case 5:
			if (controller_removeEmployee(listaEmpleados)) {
				printRecuadro("Remocion Exitosa\n");
			} else {
				printRecuadro("#Error en remocion de datos verifique\n");
			}

			break;
		case 6:
			if (controller_ListEmployee(listaEmpleados) == 0) {
				printRecuadro("#Error en la muestra de datos verifique\n");
			}
			break;
		case 7:
			if (controller_sortEmployee(listaEmpleados)) {
				printRecuadro("Ordenamiento Exitoso\n");
			} else {
				printRecuadro("#Error en ordenamiento de datos verifique\n");
			}

			break;
		case 8:

			if (flagAbm == 1 && flagCarga != 1) {
				if (controller_saveAsText("ABMtexto.csv", listaEmpleados)) {
					printRecuadro(
							"Guardado (modo texto) Exitoso,archivo ;ABMtexto\n");
				} else {
					printRecuadro("#Error,al guardar,verifique\n");
				}

			} else {
				if (controller_saveAsText("data.csv", listaEmpleados)) {
					printRecuadro(
							"Guardado (modo texto) Exitoso reescrito en data.csv\n");
				} else {
					printRecuadro("#Error,al guardar,verifique\n");
				}

			}
			break;
		case 9:
			if (flagAbm == 1 && flagCarga != 1) {
				if (controller_saveAsBinary("ABMbinario.bin", listaEmpleados)) {
					printRecuadro(
							"Guardado (modo binario) Exitoso,archivo ;ABMbinario\n");
				} else {
					printRecuadro("#Error,al guardar,verifique\n");
				}
			} else {

				if (controller_saveAsBinary("data.bin", listaEmpleados)) {
					printRecuadro(
							"Guardado (modo texto) Exitoso reescrito en data.bin \n");
				} else {
					printRecuadro("#Error,al guardar,verifique\n");
				}
			}

			break;
		}
	} while (option != 10);
	printRecuadro("Saliendo del sistema...\n"
			"Gracias por utilizar nuestro Software.\n");
	ll_deleteLinkedList(listaEmpleados);

	return 0;
}

