/*
 * ArrayEmployees.c
 *
 *  Created on: 15 oct. 2021
 *      Author: gt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"
#include "ArrayEmployees.h"
#define VACIO 0
#define OCUPADO 1
#define LASTNAME_LEN 51
#define NAME_LEN 51

static int disp_nuevoId(void);


/**brief nos genera un id nuevo consecutivo cuando se invoca ( en este caso comienza a partir del 1000 en adelante)
 * param (no recibe nada)
 * return retorna un entero positivo que se usa como id "SOLO PARA USAR EN ESTA BIBLIOTECA"
 */
static int disp_nuevoId(void)
{
	static int counter=1000;
	return (counter++);
}

/**brief nos inicializa todo el array colocando en la posicion isEmpty un 0 para indicar lugar Libre
 * param recibe el array de la estructura completa y el tamaño del mismo
 * return retorna -1 si por algun error en el array o tamaño no se pudo inicializar y 0 si fue exitoso
 */
int init_employees(Employee lista[], int len)
{
	int retorno=-1;
	int i;
	if(lista!=NULL && len>0)
	{

		for(i=0; i<len; i++)
		{
			lista[i].isEmpty_employee=VACIO; // posicion Libre
		}
		retorno=0;
	}
	return retorno;
}

/**brief recibimos una posicion de la estructura y la llenamos con los datos que nos da el usuario, el sistema completa
 * con 1 el lugar isEmpty para indicar que esta ocupado y invoca la funcion generarId para darnos un Id nuevo
 * param 1  recibo puntero a la pocision X en el arrray estructura
 * return retorna -1 si por algun error en el array o tamaño no se pudo inicializar y 0 si fue exitosa la carga de "TODOS LOS DATOS"
 */
int addEmployee(Employee lista[])
{
	int sector;
	float salario;
	char nombre [NAME_LEN];
	char apellido [LASTNAME_LEN];
	int retorno=-1;
	if (lista!=NULL)
	{
		if (utn_pedirIntAUsuarioConLimites(&sector, 1, 6, 3, "ingresar numero sector: (Sector 1-2-3-4-5-6):", "Error.\n")==0)
			{
				if(utn_pedirFloatPositivoAUsuario(&salario, 3, "Ingrese Salario: \n", "Error.\n")==0)
				{
					if(utn_pedirNombreYApellidoAUsuario(nombre, 3, "Ingrese Nombre: (solo Letras)", "Error.\n")==0)
					{
						if(utn_pedirNombreYApellidoAUsuario(apellido, 3, "Ingrese apellido", "Error.\n")==0)
						{
							lista->sector_gen=sector;
							lista->salary_employee=salario;
							strncpy(lista->name_employee, nombre, sizeof(lista->name_employee));
							strncpy(lista->lastName_employee, apellido, sizeof(lista->lastName_employee));
							lista->id_employee=disp_nuevoId();
							lista->isEmpty_employee=OCUPADO;
							retorno=0;
						}
					}
				}
			}
	}

	return retorno;
}


/**brief recibimos una posicion de la estructura con su informacion
 * verificamos isEmpty=1 si esta ocupada IMPRIME SU INFORMACION
 *  param 1  recibo puntero a la pocision X en el arrray estructura
 * return retorna -1 si la posicion de la estructura viene con errores y 0 si fue exitosa la impresion
 */
int gen_imprimirPosicion(Employee *posicion)
{
	int retorno=-1;
	if (posicion!=NULL)
	{
		if(posicion->isEmpty_employee==1)
		{
			printf("\nID: %d\t nombre: %-10s\t apellido: %-5s\t sector: %d\t salario:%.2f\n", posicion->id_employee, posicion->name_employee, posicion->lastName_employee, posicion->sector_gen, posicion->salary_employee);
			retorno = 0;
		}
	}
	return retorno;
}

/**brief recibimos el array de la Estructura y el tamaño de la misma la recorremos con un For todo el array y
 * llamamos a la funcion que imprime por posicion
 *  param Lista completa del array estructura y el tamaño
 * return retorna -1 si la posicion de la estructura viene con errores y 0 si fue exitosa la impresion
 */
int gen_imprimirLista(Employee list[], int len)
{
	int retorno=-1;
	if (list!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			gen_imprimirPosicion(&list[i]);
		}
		retorno=0;
	}
	return retorno;
}

/**brief Verificamos que el array venga bien el tamaño del array mayor q 0 y el id buscado sea un int positivo
 * recibimos el array de la Estructura y el tamaño de la misma la recorremos con un For por todo el array y
 * primero comparamos que la posicion este ocupada isempty=1 y luego preguntamos si el id de esa posicion es igual
 * al id buscado y retornamos por puntero la posicion en la que esta el id
 *  param recibo el array de la estructura el tamaño del array el id qu buscamos retornamos por puntero la posicion del id buscado
 * return retorna -1 si la posicion el array de la estructura viene con errores el id o el tamaño del array son menores a 0
 *  y 0 si fue encontrado el id
 */
int findEmployeeById(Employee list[], int len, int idBuscado, int *posicionIdBuscado)
{
	int retorno=-1;
	if (list!=NULL && len>0 && idBuscado>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty_employee==OCUPADO && list[i].id_employee==idBuscado)
			{
				*posicionIdBuscado=i;
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}

/**brief recibimos una pocision del array de la estructura
 * validamos que el puntero este bien y pedimos al usuario mediane un menu que desea modificar vamos al suitch y modificamos
 * lo que el usuario quiere
 *  param recibo puntero a la pocision X en el arrray estructura
 * return retorna -1 si la posicion de la estructura viene con errores o se ingreso mal la opcion del menu
 *  y 0 si fue exitosa la MODIFICACION
 */
int gen_modificarLista(Employee lista[])
{
	int sector;
	float salario;
	char nombre [NAME_LEN];
	char apellido [LASTNAME_LEN];
	int retorno=-1;
	int menu;
	if (lista!=NULL && utn_pedirIntAUsuarioConLimites(&menu, 1, 4, 3, "Ingrese Numero segun lo que desee Modificar: \n 1-sector \n 2-Salario \n 3-Nombre \n 4-apellido", "Error, no es una opcion")==0)
	{

		switch (menu)
			{
			case 1:
				if (utn_pedirIntAUsuarioConLimites(&sector, 1, 6, 3, "Ingrese sector(ingresar numero: (Sector 1-2-3-4-5-6)", "Error")==0)
				{
					lista->sector_gen=sector;
					retorno=0;
				}
				break;
			case 2:
				if(utn_pedirFloatPositivoAUsuario(&salario, 3, "Ingrese Salario Empleado: \n", "Error.\n")==0)
				{
					lista->salary_employee=salario;
					retorno=0;
				}
				break;
			case 3:
				if(utn_pedirNombreYApellidoAUsuario(nombre, 3, "Ingrese Nombre: \n", "Error.\n")==0)
				{
					strncpy(lista->name_employee, nombre, sizeof(lista->name_employee));
					retorno=0;
				}
				break;
			case 4:
				if(utn_pedirNombreYApellidoAUsuario(apellido, 3, "Ingrese apellido\n", "Error.\n")==0)
				{
					strncpy(lista->lastName_employee, apellido, sizeof(lista->lastName_employee));
					retorno=0;
				}
				break;
			}
	}

	return retorno;
}


/**brief Verificamos que el array venga bien el tamaño del array mayor q 0 y el puntero a la posicion libre sea != NULL tambien
 * recorremos el array en todo su tamaño y en la primera casilla que encontremos desocupada isempty=0  retornamos
 * por puntero la posicion libre y hacemos un break para salir del for y no seguir iterando
 *  param recibo el array de la estructura el tamaño del array y el puntero de la posicion libre
 * return retorna -2 si el array de la estructura  o el puntero posicionLibre viene con errores  o el tamaño del array es menor a 0
 *  -1  si la memoria esta llena y 0 si fue encontrada una casilla libre
 */
int gen_esLibre(Employee lista[], int len, int *posicionLibre)
{
	// devuelve -2 si la falla es error de array o tamaño del array
	int retorno=-2;
	if (lista!=NULL && len>0 && posicionLibre!=NULL)
	{
		retorno=-1; //-1 si la memoria esta llena
		for (int i=0; i<len; i++)
		{
			if (lista[i].isEmpty_employee==VACIO)
			{
				*posicionLibre=i; //devuelve el indice de la primera posicion libre
				retorno=0; // 0 si se consiguio
				break;
			}
		}

	}
	return retorno;
}

/**brief Verificamos que el array venga bien el tamaño del array y el id para dar de baja mayor q 0
 * llamamos a la funcio buscar ID para que nos de la poscion en la que esta el id que queremos borrar
 * en la misma funcion preguntamos si es 0 es priqeu encontro el id y de ser asi cambiamos el estado para esa posicion de
 * isempty a 0 es decir queda libre
 *  param recibo el array de la estructura el tamaño del array y el id que se quiee elimimnar
 * return retorna -2 si el array de la estructura viene con errores, el tamaño del array  o el id para dar baja es menor a 0
 *  0 si fue dado de baja (SI NO SE ENCONTRO EL ID RETORNA -1)
 */
int removeEmployee(Employee lista[], int len, int idParaDarBaja)
{
	int retorno=-2;
	int i;
	if (lista!=NULL && len>0 && idParaDarBaja>0)
	{
		retorno=-1;
		if (findEmployeeById(lista, len, idParaDarBaja, &i)==0)
		{
			lista[i].isEmpty_employee=VACIO;
			retorno=0;
		}

	}
	return retorno;
}
/**
 * brief recorremos el array para ver si tiene informacion cargada es decir si isEmpty= 1 en alguna posicion
 * apenas enccuenta una posicion conrta el for con un break y nos devuelve un mensaje que nos indica que si tiene info el mismo
 * param array estructura y el tamaño del array
 * return -1 si no encontro datos es decir el array esta vacio y retorna 0 si tiene al menos 1 dato cargado
 */
int gen_verificarQueTieneDatosLista(Employee lista[], int len)
{
	int retorno=-1;
	if (lista!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if (lista[i].isEmpty_employee==OCUPADO)
			{
				retorno=0;
				break;
			}
		}

	}
	return retorno;
}
/*
int gen_verificarIdExiste(Employee list[], int len, int idBuscado)
{
	int retorno=-1;
	if (list!=NULL && len>0 && idBuscado>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty_employee==1 && list[i].id_employee==idBuscado)
			{
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}
*/
/**
*\ brief ingresa de manera forzada parametros a una posicion de la lista con el fin de poder
*\ realizar pruebas de manera mas rapida
*\ param lista[] es 1 posicion en el arrayEmployee
*\ return retorna 1 en caso de ser una cadena numerica (entero) y 0 si no lo es
*/
int gen_Altaforzada(Employee lista[], int sector, float salario, char nombre[], char apellido[])
{
	int retorno=-1;
	lista->sector_gen=sector;
	lista->salary_employee=salario;
	strncpy(lista->name_employee, nombre, sizeof(lista->name_employee));
	strncpy(lista->lastName_employee, apellido, sizeof(lista->lastName_employee));
	lista->id_employee=disp_nuevoId();
	lista->isEmpty_employee=1;
	retorno=0;

	return retorno;
}

int sortEmployed(Employee lista[], int len, int orden)
{
	int retorno =-1;
	Employee auxEmployee;
	int i; int j;
	if (lista!=NULL && len>0)
	{
		if (orden==1)
		{
			for (i=0; i<len-1; i++)
			{
				for (j=i+1; j<len; j++)
				{
					if ((lista[i].isEmpty_employee==OCUPADO && lista[j].isEmpty_employee==OCUPADO) && strncmp(lista[i].lastName_employee, lista[j].lastName_employee,LASTNAME_LEN)>0)
					{
						auxEmployee=lista[i];
						lista[i]=lista[j];
						lista[j]=auxEmployee;
					}
					else
						if((lista[i].isEmpty_employee==OCUPADO && lista[j].isEmpty_employee==OCUPADO) && strncmp(lista[i].lastName_employee, lista[j].lastName_employee,LASTNAME_LEN)==0)
						{
							if(lista[i].sector_gen>lista[j].sector_gen)
							{
								auxEmployee=lista[i];
								lista[i]=lista[j];
								lista[j]=auxEmployee;
							}
						}
				}
			}
		}
		else
		{
			if(orden==0)
			{
				for (i=0; i<len-1; i++)
				{
					for (j=i+1; j<len; j++)
					{
						if ((lista[i].isEmpty_employee==OCUPADO && lista[j].isEmpty_employee==OCUPADO) && strncmp(lista[i].lastName_employee, lista[j].lastName_employee,LASTNAME_LEN)<0)
						{
							auxEmployee=lista[i];
							lista[i]=lista[j];
							lista[j]=auxEmployee;
						}
						else
							if((lista[i].isEmpty_employee==OCUPADO && lista[j].isEmpty_employee==OCUPADO) && strncmp(lista[i].lastName_employee, lista[j].lastName_employee,LASTNAME_LEN)==0)
							{
								if(lista[i].sector_gen<lista[j].sector_gen)
								{
									auxEmployee=lista[i];
									lista[i]=lista[j];
									lista[j]=auxEmployee;
								}
							}
					}
				}

			}
		}
		retorno = 0;
	}
	return retorno;
}

int calcularsalarios(Employee lista[], int len)
{
	int retorno=-1;
	float acumulador=0;
	int contador=0;
	float promedio;
	int contadorDos=0;
	if (lista!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{
			if (lista[i].isEmpty_employee==OCUPADO)
			{
				acumulador=acumulador+lista[i].salary_employee;
				contador=contador+1;
			}
		}
		promedio=acumulador/contador;
		for(int j=0; j<len; j++)
		{
			if (lista[j].isEmpty_employee==OCUPADO && lista[j].salary_employee>promedio)
			{
				contadorDos=contadorDos+1;
			}
		}
	printf("El Total Pagado en Salarios es de %.2f, el salario promedio %.2f y %d empleados superan el salario promedio\n", acumulador, promedio, contadorDos);
	}

	return retorno;
}
