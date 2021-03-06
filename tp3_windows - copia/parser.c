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
{

	int contador = 0;
	Employee auxEmp;

	while(!feof(pFile))
	{
		if(fread(&auxEmp,sizeof(Employee),1,pFile) == 1)
		{
			Employee *dmEmploye = employee_new();
			employee_setId(dmEmploye,auxEmp.id);
			employee_setNombre(dmEmploye,auxEmp.nombre);
			employee_setHorasTrabajadas(dmEmploye,auxEmp.horasTrabajadas);
			employee_setSueldo(dmEmploye,auxEmp.sueldo);
			ll_add(pArrayListEmployee,(Employee*)dmEmploye);
		}

		contador++;

	}
	printf("La lista de empleados cargada asciende a: %d empleados\n",contador);
	return contador;
}


