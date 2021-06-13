


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"


Employee* employee_new(){
	Employee* auxNuevo;
	auxNuevo= (Employee*)malloc(sizeof(Employee));
		return auxNuevo;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo){

	Employee* aux;
	aux= (Employee*)malloc(sizeof(Employee));
	if(aux!=NULL){

		employee_setId(aux,atoi(idStr));
		employee_setNombre(aux,nombreStr);
		employee_setHorasTrabajadas(aux,atoi(horasTrabajadasStr));
		employee_setSueldo(aux,atoi(sueldo));
	}

	return aux;
}
void employee_delete(Employee* this){
	if(this!= NULL){
		free(this);
	}
}

int employee_setId(Employee* this,int id){
	int E=0;

	if(this!=NULL){
		E=1;
		this->id=id;
	}
	return E;
}
int employee_getId(Employee* this,int* id){

	int E=0;
	int auxId;
	if(this!=NULL && id !=NULL){
		E=1;
		auxId=this->id;
		*id=auxId;
	}
    return E;
}

int employee_setNombre(Employee* this,char* nombre){
	int E=0;

	if(this !=NULL && nombre !=NULL){
		E=1;
		strcpy(this->nombre,nombre);
	}
	return E;
}
int employee_getNombre(Employee* this,char* nombre){
	int E=0;

		if(this!=NULL && nombre !=NULL){
			E=1;
			strcpy(nombre,this->nombre);
		}
	    return E;


}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int E=0;

		if(this !=NULL ){
			E=1;
			this->horasTrabajadas=horasTrabajadas;
		}
		return E;

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){

	int E=0;
	int auxHorasTrabajadas;
	if(this!=NULL && horasTrabajadas !=NULL){
		E=1;
		auxHorasTrabajadas=this->horasTrabajadas;
		*horasTrabajadas=auxHorasTrabajadas;
	}
    return E;

}

int employee_setSueldo(Employee* this,int sueldo){
	int E=0;

			if(this !=NULL ){
				E=1;
				this->sueldo=sueldo;
			}
			return E;
}
int employee_getSueldo(Employee* this,int* sueldo){
	int E=0;
	int auxSueldo;
	if (this != NULL && sueldo != NULL){
		auxSueldo=this->sueldo;
		*sueldo=auxSueldo;
	}
	return E;
}
