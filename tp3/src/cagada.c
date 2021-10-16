/*
 ============================================================================
 Name        : cagada.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"
#include "ArrayEmployees.h"
#include "ListEmployees.h"

#define EMPLOYEES_LEN 1000
int main(void) {
	setbuf(stdout,NULL);
	int menu=0;
	int auxIsFree;
	int auxModificar;
	Employee arrayEmployee[EMPLOYEES_LEN];
	gen_inicializarLista(arrayEmployee, EMPLOYEES_LEN);


    gen_Altaforzada(&arrayEmployee[0], 1, 122, "Gustavo", "vargas");
	gen_Altaforzada(&arrayEmployee[1], 2, 456, "Alberto", "padron");
	gen_Altaforzada(&arrayEmployee[2], 2, 451, "maximiliano", "mendoza");
	gen_Altaforzada(&arrayEmployee[3], 1, 526, "mariana", "gonzalez");
	gen_Altaforzada(&arrayEmployee[4], 1, 123, "jorgina", "labrador");
	gen_Altaforzada(&arrayEmployee[0], 1, 122, "Gustavo", "vargas");
	gen_Altaforzada(&arrayEmployee[1], 2, 456, "Alberto", "padron");
	gen_Altaforzada(&arrayEmployee[2], 2, 451, "maximiliano", "mendoza");
	gen_Altaforzada(&arrayEmployee[3], 1, 526, "mariana", "gonzalez");
	gen_Altaforzada(&arrayEmployee[4], 1, 123, "jorgina", "labrador");
	gen_Altaforzada(&arrayEmployee[0], 1, 122, "Gustavo", "vargas");
	gen_Altaforzada(&arrayEmployee[1], 2, 456, "Alberto", "padron");
	gen_Altaforzada(&arrayEmployee[2], 2, 451, "maximiliano", "mendoza");
	gen_Altaforzada(&arrayEmployee[3], 1, 526, "mariana", "gonzalez");
	gen_Altaforzada(&arrayEmployee[4], 1, 123, "jorgina", "labrador");
	gen_Altaforzada(&arrayEmployee[0], 1, 122, "Gustavo", "vargas");
    gen_Altaforzada(&arrayEmployee[1], 2, 456, "Alberto", "padron");
	gen_Altaforzada(&arrayEmployee[2], 2, 451, "maximiliano", "mendoza");
	gen_Altaforzada(&arrayEmployee[3], 1, 526, "mariana", "gonzalez");
	gen_Altaforzada(&arrayEmployee[4], 1, 123, "jorgina", "labrador");
	do{
		if (utn_pedirIntAUsuarioConLimites(&menu, 0, 4, 3, "Ingrese Numero Segun Corresponda\n1.-Alta Empleado\n2.-Modificar datos de Empleado\n3.-Baja de Empleado\n4.-Informes \n0.-Salir de Sistema\n\n\n\n\n", "Error")==-1)
			{
				printf("Saliendo de Sistema...");
				break;
			}

		switch (menu)
		{
			case 1:
				if (gen_esLibre(arrayEmployee, EMPLOYEES_LEN, &auxIsFree)==0)
				{
					gen_ingresarDatosALista(&arrayEmployee[auxIsFree]);
				}
				else
				{
					printf("Lista de Empleados LLena\n");
				}
				break;
			case 2:
				if (gen_verificarQueTieneDatosLista(arrayEmployee, EMPLOYEES_LEN)==0)
				{
					gen_imprimirLista(arrayEmployee, EMPLOYEES_LEN);
					if(utn_pedirIntPositivoAUsuario(&auxModificar, 3, "Ingrese el Id del Empleado a Modificar", "Error")==0)
					{
						if(gen_buscarId(arrayEmployee, EMPLOYEES_LEN, auxModificar, &auxIsFree)==0)
						{
							gen_modificarLista(&arrayEmployee[auxIsFree]);
						}
						else
						{
							printf("ID NO EXISTE\n");
						}
					}
					else
					{
						printf("Errores Consecutivos al Ingresar Datos, Volviendo al Menu Principal\n");
					}
				}
				else
				{
					printf("No tienes Ningun Empleado Cargado en Sistema");
				}
				break;
			case 3:
				if (gen_verificarQueTieneDatosLista(arrayEmployee, EMPLOYEES_LEN)==0)
				{
					gen_imprimirLista(arrayEmployee, EMPLOYEES_LEN);
					if(utn_pedirIntPositivoAUsuario(&auxIsFree, 3, "Ingrese Id Empleado a Dar de Baja", "Error")==0)
					{
						if(gen_bajaPosicion(arrayEmployee, EMPLOYEES_LEN, auxIsFree)==0)
						{
							printf("BAJA DEL ID %d EXITOSA \n", auxIsFree);;
						}
						else
						{
							printf("ID NO EXISTE\n");
						}
					}
					else
					{
						printf("Errores Consecutivos al Ingresar Datos, Volviendo al Menu Principal\n");
					}
				}
				else
				{
					printf("No tienes Ningun Empleado Cargado en Sistema");
				}
				break;
			case 4:
				listadoOrdenadoApellidoAlfabetico(arrayEmployee, EMPLOYEES_LEN);
				//menuParaImprimirInformes(arrayEmployee, EMPLOYEES_LEN);
				break;
		}
		}while(menu!=0);



	return EXIT_SUCCESS;
}