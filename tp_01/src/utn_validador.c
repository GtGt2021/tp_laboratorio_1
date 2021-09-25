/*
 * utn_validador.c
 *
 *  Created on: 22 sep. 2021
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
*\ brief verifica que cada caracter de cadena sea un numero solo permitiendo
*\ un '-' o '+' en la primera pocision
*\ param cadena[] cadena de caracteres a verificar
*\ return retorna 1 en caso de ser una cadena numerica (entero) y 0 si no lo es
*/
int utn_esNumero(char cadena[])
{
	int retorno=-1;
	int i=0;
	if(cadena != NULL && strlen(cadena)>0)
	{
		if (cadena[i]=='-' || cadena[i]=='+')
		{
			i=1;
		}
		while (cadena[i]!='\0')
		{

			if(cadena[i]>'9' || cadena[i]<'0')
			{
				retorno=-1;
				break;
			}
			i++;
			retorno=0;
		}

	}
	return retorno;
}

/**
*\ brief verifica lee de stdin los caracteres de la cadena si encuentra un '\n'
*\  lo reemplaza con '\0', o hasta que llega al maximo (longitud-1)
*\ param cadena[] cadena de caracteres a ser verificados
*\ return retorna 0 si se obtiene una cadena valida y -1 si no se pudo por algun error
*/
int utn_miFgets(char cadena[], int longitud)
{
	int retorno=-1;
	if(cadena!=NULL && longitud>0 && fgets(cadena, longitud, stdin)==cadena)
	{
		fflush(stdin);
		if (cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1]= '\0';
		}
		retorno=0;
	}
	return retorno;
}

/**
*\ brief recibe una cadena de caracteres por la consola,
*\ valida que sea un entero (llamando a otra funcion)
*\ a su vez ejecutando la funcion utn_miFgets() para establecer un final a la cadena('\0')
*\ luego convierte la cadena de caracteres a un numero entero (atoi)
*\ param * pResultado puntero a donde se enviara el dato ya validado
*\ return retorna 0 si se recibio correctamente el entero o -1 si hay algun error
*/
int utn_obtenerEntero(int *pResultado)
{
	int retorno=-1;
	char buffer[LEN_INT];
	fflush(stdin);
	if (pResultado!=NULL)
	{

		if (utn_miFgets(buffer, sizeof(buffer))==0 && utn_esNumero(buffer)==0)
		{
			*pResultado=atoi(buffer);
			retorno=0;
		}
	}
	return retorno;
}

/**
*\ brief Pide un valor al Usuario (tipo float), valida que el dato ingresado por el usuario pase la validacion
*\ del scanf de ser asi devuelve al puntero pResultado el valor del dato recibido
*\ param pResultado puntero al espacio de memoria donde se almacenara el valor del tipo float en caso de ser recibido correctamente
*\ param variableTexto mensaje para pedir al usuario el entero
*\ param textoError mensaje de error en caso de equivocarse
*\ return retorno 0 si el valor es valido y -1 si no lo es
*/
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

/**
*\ brief Pide un Entero al Usuario, valida que el entero este entre los limites
*\  establecidos por el usuario y con un numero determinado de reintentos
*\  (se llama la funcion utn_obtenerEntero(se le pasa el puntero que almacena dato recibido) para completar esta funcion)
*\ param *pResultado puntero al espacio de memoria donde se almacenara el entero en caso de ser recibido correctamente
*\ param min valor minimo aceptado para el entero a validar
*\ param max valor maximo aceptado para el entero a validar
*\ param variableTexto mensaje para pedir al usuario el entero
*\ param textoError mensaje de error en caso de equivocarse
*\ return retorno 0 si el entero es valido y -1 si no lo es
*/
int utn_pedirIntAUsuario(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError)
{
	int buffer;
	int retorno=-1;
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL && min<max && reintentos>=0)
	{
		do
		{
			printf("%s\n",variableTexto);
			fflush( stdin );
			if (utn_obtenerEntero(&buffer)==0 && buffer>=min && buffer<=max)
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

