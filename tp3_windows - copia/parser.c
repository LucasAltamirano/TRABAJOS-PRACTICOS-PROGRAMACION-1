#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
	Employee* punteroEmployee=NULL;
	int E=0;
	char buffer [4] [128];
	int contador=0;
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3));

	while(!feof(pFile)){

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3));

		punteroEmployee=employee_newParametros(*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3));
		if(punteroEmployee!=NULL){
			E=1;
			ll_add(pArrayListEmployee,(Employee*)punteroEmployee);
			contador++;

		}

	}
	printf("La lista de empleados cargada asciende a: %d empleados\n",contador);
    return E;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{	Employee* punteroEmployee=NULL;
	int E=0;
	int contador=0;
	char buffer [4] [128];
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3));

	while(!feof(pFile)){

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3));

		punteroEmployee=employee_newParametros(*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3));
		if(punteroEmployee!=NULL){
			E=1;
			ll_add(pArrayListEmployee,(Employee*)punteroEmployee);
			contador++;
		}
	}
	printf("la lista de empleados cargada asciende a: %d empleados\n",contador);
    return E;
}
