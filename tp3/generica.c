/*
 * generica.c
 *
 *  Created on: 12 oct. 2021
 *      Author: gt
 */

#include "../../tp3/generica.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"

static int disp_nuevoId(void);

static int disp_nuevoId(void)
{
	static int counter=1000;
	return (counter++);
}

int gen_inicializarLista(eGenerica lista[], int len)
{
	int retorno=-1;
	int i;
	if(lista!=NULL && len>0)
	{

		for(i=0; i<len; i++)
		{
			lista[i].estaOcupado_gen=0;
		}
		retorno=0;
	}
	return retorno;
}

int gen_ingresarDatosALista(eGenerica lista[])
{
	int tipo;
	float precio;
	char nombre [128];
	char direccion [128];
	int retorno=-1;
	if (lista!=NULL)
	{
		if (utn_pedirIntAUsuarioConLimites(&tipo, 1, 2, 3, "Ingrese Tipo(ingresar numero: \n1.-LCD\n2.-LED\n", "Error.\n")==0)
			{
				if(utn_pedirFloatPositivoAUsuario(&precio, 3, "Ingrese Valor Para Pantalla: \n", "Error.\n")==0)
				{
					if(utn_pedirNombreYApellidoAUsuario(nombre, 3, "Ingrese Nombre: (solo Letras)", "Error.\n")==0)
					{
						if(utn_PedirCualquierCaracterAUsuario(direccion, 3, "Ingrese Direccion", "Error.\n")==0)
						{
							lista->tipo_gen=tipo;
							lista->precio_gen=precio;
							strncpy(lista->nombre_gen, nombre, sizeof(lista->nombre_gen));
							strncpy(lista->direccion_gen, direccion, sizeof(lista->direccion_gen));
							lista->id_gen=disp_nuevoId();
							lista->estaOcupado_gen=1;
							retorno=0;
						}
					}
				}
			}
	}

	return retorno;
}

int gen_imprimirPocision(eGenerica Pocision[])
{
	int retorno=-1;
	if (Pocision!=NULL)
	{
		if(Pocision->estaOcupado_gen==1)
		{
			printf("\nID: %d\t nombre: %s\t direccion: %s\t tipo: %d\t precio:%.2f\n", Pocision->id_gen, Pocision->nombre_gen, Pocision->direccion_gen, Pocision->tipo_gen, Pocision->precio_gen);
			retorno = 0;
		}
	}
	return retorno;
}

int gen_imprimirLista(eGenerica list[], int len)
{
	int retorno=-1;
	if (list!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if(list[i].estaOcupado_gen==1)
			{
				printf("\nID: %d\t nombre: %s\t direccion: %s\t\t tipo: %d\t precio:%.2f", list[i].id_gen, list[i].nombre_gen, list[i].direccion_gen, list[i].tipo_gen, list[i].precio_gen);
				retorno = 0;
			}
		}
		printf("\n\n");
	}
	return retorno;
}

int gen_buscarId(eGenerica list[], int len, int idBuscado, int *posicionIdBuscado)
{
	int retorno=-1;
	if (list!=NULL && len>0 && idBuscado>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].estaOcupado_gen==1 && list[i].id_gen==idBuscado)
			{
				*posicionIdBuscado=i;
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}

int gen_modificarLista(eGenerica lista[])
{
	int tipo;
	float precio;
	char nombre [128];
	char direccion [128];
	int retorno=-1;
	int menu;
	if (lista!=NULL && utn_pedirIntAUsuarioConLimites(&menu, 1, 4, 3, "Ingrese Numero segun lo que desee Modificar: \n 1-Tipo \n 2-Precio \n 3-Nombre \n 4-Direccion", "Error, no es una opcion")==0)
	{

		switch (menu)
			{
			case 1:
				if (utn_pedirIntAUsuarioConLimites(&tipo, 1, 2, 3, "Ingrese Tipo(ingresar numero: \n1.-LCD\n2.-LED\n", "Error.\n")==0)
				{
					lista->tipo_gen=tipo;
					retorno=0;
				}
				break;
			case 2:
				if(utn_pedirFloatPositivoAUsuario(&precio, 3, "Ingrese Valor Para Pantalla: \n", "Error.\n")==0)
				{
					lista->precio_gen=precio;
					retorno=0;
				}
				break;
			case 3:
				if(utn_pedirNombreYApellidoAUsuario(nombre, 3, "Ingrese Nombre: \n", "Error.\n")==0)
				{
					strncpy(lista->nombre_gen, nombre, sizeof(lista->nombre_gen));
					retorno=0;
				}
				break;
			case 4:
				if(utn_PedirCualquierCaracterAUsuario(direccion, 3, "Ingrese Direccion\n", "Error.\n")==0)
				{
					strncpy(lista->direccion_gen, direccion, sizeof(lista->direccion_gen));
					retorno=0;
				}
				break;
			}
	}

	return retorno;
}

int gen_esLibre(eGenerica lista[], int len, int *posicionLibre)
{
	// devuelve -2 si la falla es error de array o tamaño del array
	int retorno=-2;
	if (lista!=NULL && len>0 && posicionLibre!=NULL)
	{
		retorno=-1; //-1 si la memoria esta llena
		for (int i=0; i<len; i++)
		{
			if (lista[i].estaOcupado_gen==0)
			{
				*posicionLibre=i; //devuelve el indice de la primera pocision libre
				retorno=0; // 0 si se consiguio
				break;
			}
		}

	}
	return retorno;
}

int gen_bajaPocision(eGenerica lista[], int len, int idParaDarBaja)
{
	int retorno=-1;
	int i;
	if (lista!=NULL && len>0 && idParaDarBaja>0)
	{
		if (gen_buscarId(lista, len, idParaDarBaja, &i)==0)
		{
			lista[i].estaOcupado_gen=0;
			retorno=0;
		}

	}
	return retorno;
}

int gen_verificarQueTieneDatosLista(eGenerica lista[], int len)
{
	int retorno=-1;
	if (lista!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if (lista[i].estaOcupado_gen==1)
			{
				retorno=0;
				break;
			}
		}

	}
	return retorno;
}

int gen_verificarIdExiste(eGenerica list[], int len, int idBuscado)
{
	int retorno=-1;
	if (list!=NULL && len>0 && idBuscado>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].estaOcupado_gen==1 && list[i].id_gen==idBuscado)
			{
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}

int gen_Altaforzada(eGenerica lista[], int tipo, float precio, char nombre[], char direccion[])
{
	int retorno=-1;
	lista->tipo_gen=tipo;
	lista->precio_gen=precio;
	strncpy(lista->nombre_gen, nombre, sizeof(lista->nombre_gen));
	strncpy(lista->direccion_gen, direccion, sizeof(lista->direccion_gen));
	lista->id_gen=disp_nuevoId();
	lista->estaOcupado_gen=1;
	retorno=0;

	return retorno;
}
