/*
 * generica.c
 *
 *  Created on: 12 oct. 2021
 *      Author: gt
 */

#include "../../tp3/contratacion.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"

static int disp_nuevoId(void);

static int disp_nuevoId(void)
{
	static int counter=1;
	return (counter++);
}

int contra_inicializarLista(eContrataciones lista[], int len)
{
	int retorno=-1;
	int i;
	if(lista!=NULL && len>0)
	{

		for(i=0; i<len; i++)
		{
			lista[i].estaOcupado_contra=0;
		}
		retorno=0;
	}
	return retorno;
}

int contra_ingresarDatosAListaPorId(eContrataciones lista[], int idPantalla)
{
	char cuit[14];
	int dias;
	char nombre [128];
	int retorno=-1;
	if (lista!=NULL && idPantalla>0)
	{
		if (utn_PedirCuitAUsuario(cuit, 3, "Ingrese Cuit", "Error.\n")==0)
		{
				if(utn_pedirIntPositivoAUsuario(&dias, 3, "Ingrese Cantidad Dias: \n", "Error.\n")==0)
				{
					if(utn_PedirCualquierCaracterAUsuario(nombre, 3, "Ingrese Nombre del Archivo: \n", "Error")==0)
					{
						strncpy(lista->cuit_contra, cuit, sizeof(lista->cuit_contra));
						lista->cantidadDias_contra=dias;
						strncpy(lista->nombreArchivo_contra, nombre, sizeof(lista->nombreArchivo_contra));
						lista->id_pantalla=idPantalla;
						lista->id_contra=disp_nuevoId();
						lista->estaOcupado_contra=1;
						retorno=0;
					}
				}
		}
	}
	return retorno;
}

int contra_imprimirPocision(eContrataciones pocision[])
{
	int retorno=-1;
	if (pocision!=NULL)
	{
		if(pocision->estaOcupado_contra==1)
		{

			printf("\nID CONTRATO: %d\t nombre archivo: %s\t Cuit: %s\t dias: %d\t Pantalla: %d\n", pocision->id_contra, pocision->nombreArchivo_contra, pocision->cuit_contra, pocision->cantidadDias_contra, pocision->id_pantalla);
			retorno = 0;
		}
	}
	return retorno;
}

int contra_imprimirLista(eContrataciones list[], int len)
{
	int retorno=-1;
	if (list!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if(list[i].estaOcupado_contra==1)
			{
				contra_imprimirPocision(&list[i]);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int contra_buscarId(eContrataciones list[], int len, int idBuscado, int *posicionIdBuscado)
{
	int retorno=-1;
	if (list!=NULL && len>0 && idBuscado>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].estaOcupado_contra==1 && list[i].id_contra==idBuscado)
			{
				*posicionIdBuscado=i;
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}


int contra_modificarLista(eContrataciones lista[])
{
	int dias;
	int retorno=-1;
	if (lista!=NULL)
	{
		if(utn_pedirIntPositivoAUsuario(&dias, 3, "Ingrese Cantidad Dias: \n", "Error.\n")==0)
		{
			lista->cantidadDias_contra=dias;
			retorno=0;
		}

	}

	return retorno;
}

int contra_esLibre(eContrataciones lista[], int len, int *posicionLibre)
{
	// devuelve -2 si la falla es error de array o tamaño del array
	int retorno=-2;
	if (lista!=NULL && len>0)
	{
		retorno=-1; //-1 si la memoria esta llena
		for (int i=0; i<len; i++)
		{
			if (lista[i].estaOcupado_contra==0)
			{
				*posicionLibre=i; //devuelve el indice de la primera pocision libre
				retorno=0; // 0 si se consiguio
				break;
			}
		}

	}
	return retorno;
}

int contra_bajaPocision(eContrataciones lista[], int len, int idParaDarBaja)
{
	int retorno=-1;
	int i;
	if (lista!=NULL && len>0 && idParaDarBaja>0)
	{
		if (contra_buscarId(lista, len, idParaDarBaja, &i)==0)
		{
			lista[i].estaOcupado_contra=0;
			retorno=0;
		}

	}
	return retorno;
}

int contra_verificarQueTieneDatosLista(eContrataciones lista[], int len)
{
	int retorno=-1;
	if (lista!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if (lista[i].estaOcupado_contra==1)
			{
				retorno=0;
				break;
			}
		}

	}
	return retorno;
}

int contra_buscarCuit(eContrataciones list[], int len, char cuitBuscado[])
{
	int retorno=-1;
	if (list!=NULL && len>0 && cuitBuscado!=NULL)
	{

		for(int i=0; i<len; i++)
		{
			if(list[i].estaOcupado_contra==1 && strcmp(list[i].cuit_contra,cuitBuscado)==0)
			{
				contra_imprimirPocision(&list[i]);
				retorno=0;
			}
		}
	}

	return retorno;
}

int contra_imprimirContratoAModificar(eContrataciones pocision[])
{
	int retorno=-1;
	if (pocision!=NULL)
	{
		if(pocision->estaOcupado_contra==1)
		{
			printf("dias: %d",pocision->cantidadDias_contra);
			retorno = 0;
		}
	}
	return retorno;
}

