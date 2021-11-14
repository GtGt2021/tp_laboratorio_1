#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Validator.h"



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
	char id[16];
	char sueldo[256];
	char horas[256];
	char nombre[256];
	int retorno=-1;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo); // para saltarme la primera linea (leo char hasta la , y el ultimo hasta \n
		do
		{
			//printf("retorno fscanf:%d \n", prueba);
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo)==4) // leo uno  auno
			{
				//printf("id:%s nombre %s horas %s sueldo %s\n",id,nombre,horas,sueldo ); // los muestro
				pEmployee=employee_newParametros(id, nombre, horas, sueldo); // creo un employee con los datos
				if(pEmployee!=NULL)
				{
					ll_add(pArrayListEmployee, pEmployee); // agrego employee a ll
					retorno=0;//hay al menos 1 empleado
				}
				else
				{
					printf("Error en Archivo Empleado Id: %s\n", id); //solo muestro los Id de los Empleados con errores ( MOSTRE SOLO NOMBRE NO TOMO NOMBRES CON ESPACIO)
					employee_delete(pEmployee);
				}
			}
			else
			{
				printf("Archivo Sin informacion\n");
				break;
			}

		}while (feof(pFile)==0);
	}
	return retorno;
}
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}



