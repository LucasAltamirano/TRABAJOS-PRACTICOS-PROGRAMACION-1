/*
 ============================================================================
 Name        : Trab.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int factorialA(int a  );//
//int factorialB(int b );//
int main(void) {
	setbuf(stdout, NULL);


	int valor;
	int result;
	printf("\nIngrese numero:");
	scanf("%d",&valor);
	result=factorialA(valor);
	printf("\nEl factorial de %d es %d",valor,result);


	return EXIT_SUCCESS;
}

int factorialA(int a  )
{
int resp;
if(a==1)
return 1;
resp=a* factorialA(a-1);


return (resp);
}
/*
int factorialB(int b )
{
int resp;
if(b==1)
return 1;
resp=b* factorial(b-1);


return (resp);
}*/
