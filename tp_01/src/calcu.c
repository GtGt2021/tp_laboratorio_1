/*
 * calcu.c
 *
 *  Created on: 21 sep. 2021
 *      Author: gt
 */

#include <stdio.h>
#include <stdlib.h>


void mostrarMenuUsuario(int* pMenu, float operandoUno, float operandoDos, int banderaOperandoUno, int banderaOperandoDos)
{
	if(banderaOperandoUno==0 && pMenu!=NULL)
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
	scanf("%d", pMenu);
}

int utn_pedirFloatAUsuario(float* pResultado, char* variableTexto, char* textoError)
{
	float buffer;
	int retorno;
	if(pResultado != NULL && variableTexto != NULL && textoError != NULL)
	{
			printf("%s\n",variableTexto);
			fflush( stdin );
			retorno=scanf("%f", &buffer);

			if (retorno==1)
			{
				*pResultado=buffer;
				retorno=0;
			}
			else
			{
				printf("%s\n", textoError);
				retorno=-1;
			}
	}
	return retorno;
}

int utn_pedirIntAUsuario(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError)
{
	int buffer;
	int retorno=-1;
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL && min<max && reintentos>=0)
	{
		do
		{
			printf("%s",variableTexto);
			fflush( stdin );
			scanf("%d", &buffer);

			if (scanf("%d", &buffer)==1 && buffer>=min && buffer<=max)
			{
				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				printf("%s, %s\n", textoError, variableTexto);
				reintentos--;
			}
		}while (reintentos >=0);
	}
	return retorno;
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
