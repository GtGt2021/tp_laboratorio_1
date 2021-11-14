/*
 * Validator.c
 *
 *  Created on: 7 nov. 2021
 *      Author: gt
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"
#define LEN_INT 11
#define LEN_CHAR 50
#define LEN_MAIL 80
#define LEN_NAME 124
#define LEN_CUIT 14

/**
*\ brief verifica lee de stdin los caracteres de la cadena si encuentra un '\n'
*\  lo reemplaza con '\0', o hasta que llega al maximo (longitud-1)
*\ param cadena[] cadena de caracteres a ser verificados
*\ return retorna 0 si se obtiene una cadena valida y -1 si no se pudo por algun error
*/
static int utn_miFgets(char cadena[], int longitud)
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

static int utn_esSoloNombre(char cadena[])
{
	int retorno=-1;
	int i=0;
	if(cadena != NULL && strlen(cadena)>0)
	{

		while (cadena[i]!='\0')
		{
			if( (cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z'))
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

int tp3_obtenerSoloNombre(char cadena[], int len)
{
	int retorno=-1;
	char buffer[len];
	fflush(stdin);
	if (cadena!=NULL)
	{

		if (utn_miFgets(buffer, sizeof(buffer))==0 && utn_esSoloNombre(buffer)==0)
		{
			retorno=0;
		}
	}
	return retorno;
}


