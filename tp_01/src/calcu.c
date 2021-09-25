/*
 * calcu.c
 *
 *  Created on: 21 sep. 2021
 *      Author: gt
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calcu.h"
#include "utn_validador.h"
#define LEN_INT 11


/**
*\ brief muestra el menu al usuario dependiendo de los valores de las banderas al momento
*\ si la bandera operandoUno y operandoDos son 0 muestra un mensaje con los valores del operando respectivo
*\ y si es -1 muestra otro (cada uno se valida separado)
*\ param operandoUno (1 valor para los calculos)
*\ param operandoDos (2 valor para los calculos)
*\ param banderaOperandoUno bandera para mostrar un menu u otro
*\ param banderaOperandoDos bandera para mostrar un menu u otro
*\ return no retorna nada
*/
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
/**
*\ brief toma dos valores los suma y los almacena en el puntero a memoria pResultado
*\ param operandoUno valor 1 a sumar
*\ param operandoDos valor que se le suma a valor 1
*\ param *pResultado direccion de memoria para almacenar el resultado de la suma
*\ return en caso de que el puntero sea  NULL regresa un error
*/
int sumarNumerosFloat(float operandoUno, float operandoDos, float *pResultado)
{
	int retorno=-1;
	if (pResultado!=NULL)
	{
		*pResultado=operandoUno+operandoDos;
		retorno=0;
	}
	return retorno;
}

/**
*\ brief toma dos valores los resta y los almacena en el puntero a memoria pResultado
*\ param operandoUno valor 1 a restar
*\ param operandoDos valor que se le resta a valor 1
*\ param *pResultado direccion de memoria para almacenar el resultado de la resta
*\ return en caso de que el puntero sea  NULL regresa un error
*/

int restarNumerosFloat(float operandoUno, float operandoDos, float *pResultado)
{
	int retorno=-1;
	if (pResultado!=NULL)
	{
		*pResultado=operandoUno-operandoDos;
		retorno=0;
	}
	return retorno;
}

/**
*\ brief toma dos valores los multiplica y los almacena en el puntero a memoria pResultado
*\ param operandoUno valor 1 a multiplicar
*\ param operandoDos valor que se le multiplicara a valor 1
*\ param *pResultado direccion de memoria para almacenar el resultado de la resta
*\ return en caso de que el puntero sea  NULL regresa un error
*/

int multiplicarNumerosFloat(float operandoUno, float operandoDos, float *pResultado)
{
	int retorno=-1;
	if (pResultado!=NULL)
	{
		*pResultado=operandoUno*operandoDos;
		retorno=0;
	}
	return retorno;
}

/**
*\ brief divide operandoUno entre operandoDos y regresa el valor al puntero pResultadoDivision
*\ si operandoDos = 0 devuelve un error y no hace el calculo
*\ param operandoUno primer valor a usar
*\ para operandoDos segundo valor a usar
*\ return retorna 0 si la division se hizo exitosamente y -1 si por algun error no se puede realizar
*/
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
/**
*\ brief recibe un numero flotante lo castea a int luego validamos que este entre los dos valores
*\ admitidos (0-12) y que el numero ingresado sea un numero entero restando el numero casteado a int -
*\ el ingresado por el usuario si este resultado da cero se procede a calcular el factorial
*\ contamos en forma decreciente desde el numero parseado a entero hasta el 1 y
*\ multiplicando una variable inicialisada en 1 por cada uno de los numeros que vamos bajando
*\ param operando es el valor float que se quiere sacar factorial
*\ param *factorial valor del puntero de memoria a donde vamos a enviar el resultado del factorial
*\ param *operandoInt valor del puntero de memoria donde vamos a reflejar el entero al que se le calculo el factorial en el menu imrpimir resultados
*\ return regresa 0 si se le pudo calcular el factorial y -1 si no se pudo
*/
int factorialEnteros(float operando, int *factorial, int *operandoInt)
{
	int numero=(int)operando;
	*operandoInt=numero;
	int fact=1;
	int i;
	int retorno=-1;
	if (factorial!=NULL && operandoInt!=NULL && numero>=0 && numero<13 && (numero-operando)==0)
	{
		if (numero==0)
		{
			*factorial=1;
			return 0;
		}
		for(i=numero; i>0; i--)
		{
			fact=fact*i;
		}
		*factorial=fact;
		retorno=0;
	}

	return retorno;

}
