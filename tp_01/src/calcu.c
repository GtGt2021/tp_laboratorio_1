/*
 * calcu.c
 *
 *  Created on: 21 sep. 2021
 *      Author: gt
 */

#include <stdio.h>
#include <stdlib.h>


void mostrarMenuUsuario(float operandoUno, float operandoDos, int banderaOperandoUno, int banderaOperandoDos)
{
	if(banderaOperandoUno==0)
	{
		printf("Presione 1 para Ingresar 1er Operando:A=%.2f\n", operandoUno);
	}else
	{
		printf("Presione 1 para Ingresar 1er Operando:A=X\n");
	}
	if(banderaOperandoDos==0)
	{
		printf("Presione 2 para Ingresar 2do Operando:B=%.2f\n", operandoDos);
	}else
	{
		printf("Presione 2 para Ingresar 2do Operando:B=Y\n");
	}
	printf("Presione 3 para calcular todas las operaciones\n");
	printf("presione 4 para informar resultados\n");
	printf("Presione 5 para salir\n");
}

void sumarNumerosFloat(float operandoUno, float operandoDos, float *pResultado)
{
	if (pResultado!=NULL)
	{
		*pResultado=operandoUno+operandoDos;
	}
}
void restarNumerosFloat(float operandoUno, float operandoDos, float *pResultado)
{
	if (pResultado!=NULL)
	{
		*pResultado=operandoUno-operandoDos;
	}
}
void multiplicarNumerosFloat(float operandoUno, float operandoDos, float *pResultado)
{
	if (pResultado!=NULL)
	{
		*pResultado=operandoUno*operandoDos;
	}
}
int dividirNumerosFloat(float operandoUno, float operandoDos, float *pResultadoDivision)
{
	int retorno=-1;
	if (pResultadoDivision != NULL && operandoDos!=0)
	{
		*pResultadoDivision=operandoUno/operandoDos;
		retorno=0;
	}
	return retorno;
}

int factorialEnteros(float operando, int *factorial, int *operandoInt)
{
	int numero=(int)operando;
	*operandoInt=numero;
	int fact=1;
	int i;
	int retorno=-1;
	if (numero>0 && numero<13)
	{
		for(i=numero; i>0; i--)
		{
			fact=fact*i;
		}
		*factorial=fact;
		retorno=0;
	}
	else
	{
		if (operando==0)
		{
			*factorial=1;
			retorno=0;
		}
	}

	return retorno;

}
