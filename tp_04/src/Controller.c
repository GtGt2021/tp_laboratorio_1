#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn_validador.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE *fp;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		fp = fopen(path, "r");
		if(fp!=NULL)
		{
			if (parser_EmployeeFromText(fp, pArrayListEmployee)==0)
				{
					retorno=0;
				}
				else
				{
					retorno=-2;
				}
			fclose(fp);
		}
		else
		{
			printf("Archivo no Existe\n");
		}

	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
		if(path!=NULL && pArrayListEmployee!=NULL)
		{
			FILE *fp = fopen(path, "rb");
			if(fp!=NULL)
			{

				if (parser_EmployeeFromBinary(fp, pArrayListEmployee)==0)
					{
						retorno=0;

					}
					else
					{
						retorno=-2;

					}
				fclose(fp);
			}
			else
			{
				printf("Archivo no Existe\n");
			}

		}
		return retorno;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int id;
	char nombre[128];
	int horasTrabajadas;
	float sueldo;
	Employee* newEmployee;

	if (pArrayListEmployee!=NULL)
	{

		newEmployee=employee_new();
		if(newEmployee!=NULL)
		{

			if(utn_pedirSoloNombre(nombre, NOMBRE_LEN, 3, "Ingrese el Nombre del Empleado", "Error")==0
					&& utn_pedirIntPositivoAUsuario(&horasTrabajadas, 3, "Ingrese Horas Trabajadas", "Error")==0
					&& utn_pedirFloatPositivoAUsuario(&sueldo, 3, "Ingrese Sueldo", "Error")==0)
			{
				id=employee_createId();
				employee_setNombre(newEmployee, nombre);
				employee_setHorasTrabajadas(newEmployee, horasTrabajadas);
				employee_setSueldo(newEmployee, sueldo);
				employee_setId(newEmployee, id);
				ll_add(pArrayListEmployee, newEmployee);
				retorno=0;
			}
			else
			{
				retorno=-2;
				free(newEmployee);
			}

		}


	}


	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	char nombre[NOMBRE_LEN];
	int salario;
	int horas;
	int menu;
	int idEdit;
	int indexAux;
	Employee *pEmployeeAux;
	if(pArrayListEmployee!=NULL)
	{
		if(utn_pedirIntPositivoAUsuario(&idEdit, 3, "Ingrese Id A Editar", "Error")==0)
		{
			indexAux=employee_findById(pArrayListEmployee, idEdit);
    		if (indexAux>=0)
    		{
    			pEmployeeAux=(Employee*)ll_get(pArrayListEmployee, indexAux);
    			if (utn_pedirIntAUsuarioConLimites(&menu, 1, 3, 3, "Editar Empleados\n1.-Nombre2.-Horas3.-Sueldo", "Error de Seleccion")==0)
				{
					switch (menu)
					{
					case 1:
						if(utn_pedirSoloNombre(nombre, NOMBRE_LEN, 3, "Ingrese el Nombre del Empleado", "Error")==0)
						{
							employee_setNombre(pEmployeeAux, nombre);
							retorno=0;
						}
						else
						{
							printf("Error al ingresar Nombre");
						}
						break;
					case 2:
						if(utn_pedirIntPositivoAUsuario(&horas, 3, "Ingrese Horas", "error")==0)
						{
							employee_setHorasTrabajadas(pEmployeeAux, horas);
							retorno=0;
						}
						else
						{
							printf("Error al ingresar Horas");
						}
						break;

					case 3:
						if(utn_pedirIntPositivoAUsuario(&salario, 3, "Ingrese sueldo", "error")==0)
						{
							employee_setSueldo(pEmployeeAux, salario);
							retorno=0;
						}
						else
						{
							printf("Error al ingresar Sueldo");
						}
						break;

					}

  				}
    		}
    		else
    		{
    			printf("id NO existe\n");
    		}
		}
		else
		{
			printf("Ingreso Id Invalido Varias Veces\n");
		}

	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int idFree;
	int indexAux;
	Employee *pEmployeeAux;
	if(pArrayListEmployee!=NULL)
	{
		if(utn_pedirIntPositivoAUsuario(&idFree, 3, "Ingrese Id A Eliminar", "Error")==0)
		{
			indexAux=employee_findById(pArrayListEmployee, idFree);
			if (indexAux>=0)
			{
				pEmployeeAux=(Employee*)ll_get(pArrayListEmployee, indexAux);
				ll_remove(pArrayListEmployee, indexAux);
				free(pEmployeeAux);
				retorno=0;
			}
			else
			{
				printf("id NO existe\n");
			}
		}
		else
		{
			printf("Ingreso Id Invalido Varias Veces\n");
		}

	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	Employee *pEmployeeAux;
	if(pArrayListEmployee!=NULL)
	{
		int len=ll_len(pArrayListEmployee);
		if(len>0)
		{
			printf("          Lista de Empleados\n");
			for(int i=0; i<len; i++)
			{
				pEmployeeAux=(Employee*)ll_get(pArrayListEmployee, i);
				employee_printEmployee(pEmployeeAux);
			}
			retorno=0;
		}
	}
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int orden;
	int tipo;

	if(pArrayListEmployee!=NULL && employee_getOrden(&tipo, &orden)==0)
	{
		printf("Espere un Momento Mientras Ordena");
		switch (tipo)
		{
		case 1://ordenamos por Id
			ll_sort(pArrayListEmployee, employee_compareById, orden);
			break;
		case 2: //ordenamos por nombre
			ll_sort(pArrayListEmployee, employee_compareByName, orden);
			break;
		case 3://sueldo
			ll_sort(pArrayListEmployee, employee_compareBySueldo, orden);
			break;
		case 4:// horas
			ll_sort(pArrayListEmployee, employee_compareByHoras, orden);
			break;

		}
		retorno=0;
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	Employee *pEmployee;
	int sueldo;
	int horasTrabajadas;
	int id;
	char nombre[256];
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		FILE *fu=fopen(path, "w");

		if(fu!=NULL)
		{

			fprintf(fu,"id,nombre,horasTrabajadas,sueldo\n");
			for(int i=0; i<ll_len(pArrayListEmployee); i++)
			{

				pEmployee=ll_get(pArrayListEmployee, i);
				employee_getId(pEmployee, &id);
				employee_getNombre(pEmployee, nombre);
				employee_getHorasTrabajadas(pEmployee, &horasTrabajadas);
				employee_getSueldo(pEmployee, &sueldo);
				fprintf(fu,"%d,%s,%d,%d\n",id, nombre, horasTrabajadas, sueldo);
			}
			fclose(fu);
			retorno=0;
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo fileBinary.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	Employee *pEmploye;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		//printf("valide ll y nombre archivo");
		FILE *fb=fopen(path, "wb");
		if(fb!=NULL)
		{
			//fwrite()
			for(int i=0; i<ll_len(pArrayListEmployee); i++)
			{
				pEmploye=ll_get(pArrayListEmployee, i);
				if(pEmploye!=NULL)
				{
					fwrite(pEmploye,sizeof(Employee),1,fb);
				}
			}
			fclose(fb);
			retorno=0;
		}
	}
    return retorno;
}
