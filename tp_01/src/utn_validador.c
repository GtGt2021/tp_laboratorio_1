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
#define LEN_INT 11


int utn_esNumero(char cadena[])
{
	int retorno=-1;
	int i=0;
	if(cadena != NULL && strlen(cadena)>0)
	{
		if (cadena[i]=='-')
		{
			i=1;
		}
		while (cadena[i]!='\0')
		{

			if((cadena[i]>'9' || cadena[i]<'0') || isspace(cadena[i]))
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

int utn_obtenerEntero(int *pResultado)
{
	int retorno=-1;
	char buffer[64];
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

