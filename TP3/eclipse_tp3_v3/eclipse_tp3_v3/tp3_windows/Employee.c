#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_validador.h"
#include "Employee.h"
#include "LinkedList.h"



Employee* employee_new()
{
	Employee* newEmployee;
	newEmployee=(Employee*)calloc(1,sizeof(Employee));
	return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* auxEmployee;
	if(idStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL && nombreStr!=NULL)
	{
		auxEmployee=employee_new();
		if(auxEmployee!=NULL)
		{
			if(!(employee_setNombreFile(auxEmployee, nombreStr)==0 &&	employee_setHorasTrabajadasFile(auxEmployee, horasTrabajadasStr)==0
					&&	employee_setSueldoFile(auxEmployee, sueldoStr)==0 && employee_setIdFile(auxEmployee, idStr)==0))
			{
				auxEmployee=NULL;
			}

		}

	}
	return auxEmployee;
}

int employee_setNombreFile(Employee* pEmployee,char* nombre)
{
	int retorno=-1;
	if(pEmployee!=NULL && nombre!=NULL)
	{
		if(utn_esNombre(nombre)==0)
		{
			strncpy(pEmployee->nombre,nombre,NOMBRE_LEN);
			retorno=0;
		}

	}
	return retorno;
}

int employee_setHorasTrabajadasFile(Employee* pEmployee,char* horasTrabajadas)
{
	int retorno=-1;
	int horas;
	if(pEmployee!=NULL && horasTrabajadas>=0)
	{
		if(utn_esIntPositivo(horasTrabajadas)==0)
		{
			horas=atoi(horasTrabajadas);
			pEmployee->horasTrabajadas=horas;
			retorno=0;
		}
	}
	return retorno;
}

int employee_setIdFile(Employee* pEmployee,char* id)
{
	int retorno=-1;
	int idAux;
	if (pEmployee!= NULL && id>=0)
	{
		if(utn_esIntPositivo(id)==0)
		{
			idAux=atoi(id);
			pEmployee->id=idAux;
			retorno=0;
		}
	}
	return retorno;
}

int employee_setSueldoFile(Employee* pEmployee,char* sueldo)
{
	int retorno=-1;
	int sueldoAux;
	if(pEmployee!=NULL && sueldo>=0)
	{
		if(utn_esIntPositivo(sueldo)==0)
		{
			sueldoAux=atoi(sueldo);
			pEmployee->sueldo=sueldoAux;
			retorno=0;
		}
	}
	return retorno;
}

int employee_setNombre(Employee* pEmployee,char* nombre)
{
	int retorno=-1;
	if(pEmployee!=NULL && nombre!=NULL)
	{

		strncpy(pEmployee->nombre,nombre,NOMBRE_LEN);

			retorno=0;
	}
	return retorno;
}

int employee_getNombre(Employee* pEmployee,char* nombre)
{
	int retorno=-1;
	if (pEmployee!= NULL && nombre != NULL)
	{
		strncpy(nombre,pEmployee->nombre,NOMBRE_LEN);
		retorno=0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* pEmployee,int horasTrabajadas)
{
	int retorno=-1;
	char horas[11];
	itoa(horasTrabajadas,horas,10);
	if(pEmployee!=NULL && horasTrabajadas>=0)
	{
		if(utn_esIntPositivo(horas)==0)
		{
			pEmployee->horasTrabajadas=horasTrabajadas;
			retorno=0;
		}
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* pEmployee,int* horasTrabajadas)
{
	int retorno=-1;
	if (pEmployee!= NULL && horasTrabajadas!= NULL)
	{
		*horasTrabajadas=pEmployee->horasTrabajadas;
	}
	return retorno;
}

int employee_setId(Employee* pEmployee,int id)
{
	int retorno=-1;
	char idAux[11];
	itoa(id,idAux,10);
	if (pEmployee!= NULL && id>=0)
	{
		if(utn_esIntPositivo(idAux)==0)
		{
			pEmployee->id=id;
			retorno=0;
		}
	}
	return retorno;
}

int employee_setSueldo(Employee* pEmployee,int sueldo)
{
	int retorno=-1;
	char sueldoAux[11];
	itoa(sueldo,sueldoAux,10);
	if(pEmployee!=NULL && sueldo>=0)
	{
		if(utn_esIntPositivo(sueldoAux)==0)
		{
			pEmployee->sueldo=sueldo;
			retorno=0;
		}
	}
	return retorno;
}
int employee_getSueldo(Employee* pEmployee,int* sueldo)
{
	int retorno=-1;
	if (pEmployee!= NULL && sueldo!= NULL)
	{
		*sueldo=pEmployee->sueldo;
	}
	return retorno;
}

int employee_getId(Employee* pEmployee,int* id)
{
	int retorno=-1;
	if (pEmployee!= NULL && id!=NULL)
	{
		*id=pEmployee->id;
		retorno=0;
	}
	return retorno;
}



void employee_delete(Employee* pEmployee)
{
	if(pEmployee!=NULL)
	{

		free(pEmployee);
	}
}

int employee_findById(LinkedList *pListEmployee, int id)
{
int retorno = -1;
int idAux;
Employee *pEmployee;
if(pListEmployee!=NULL && id>=0)
{
	for(int i=0; i<ll_len(pListEmployee); i++)
	{
		pEmployee=ll_get(pListEmployee, i);
		if(employee_getId(pEmployee, &idAux)==0)
		{
			if (idAux==id)
			{
				retorno=i;
				break;
			}
		}
	}
}
return retorno;
}
/*
int employee_addEmployee(LinkedList *pListEmployee)
{
	int retorno=-1;
	int id;
	char nombre[128];
	int horasTrabajadas;
	float sueldo;
	Employee* newEmployee;

	if (pListEmployee!=NULL)
	{

		newEmployee=employee_new();
		if(newEmployee!=NULL)
		{
			id=ll_len(pListEmployee)+1;
			if(utn_pedirSoloNombre(nombre, NOMBRE_LEN, 3, "Ingrese el Nombre del Empleado", "Error")==0
					&& utn_pedirIntPositivoAUsuario(&horasTrabajadas, 3, "Ingrese Horas Trabajadas", "Error")==0
					&& utn_pedirFloatPositivoAUsuario(&sueldo, 3, "Ingrese Sueldo", "Error")==0)
			{
				employee_setNombre(newEmployee, nombre);
				employee_setHorasTrabajadas(newEmployee, horasTrabajadas);
				employee_setSueldo(newEmployee, sueldo);
				employee_setId(newEmployee, id);
				ll_add(pListEmployee, newEmployee);
				retorno=0;
			}
			else
			{
				printf("Ingreso Mal Varias Veces los Datos Requeridos");
				retorno=-2;
				free(newEmployee);
			}

		}


	}


	return retorno;
}
*/
int employee_printEmployee(Employee *Employee)
{
	int retorno=-1;
	int id;
	int sueldo;
	int horas;
	char name[128];
	if(Employee!=NULL)
	{
		employee_getId(Employee, &id);
		employee_getNombre(Employee, name);
		employee_getSueldo(Employee, &sueldo);
		employee_getHorasTrabajadas(Employee, &horas);
		printf("Id: %2d Nombre: %10s Horas: %3d Sueldo: $%d\n", id, name, horas, sueldo);
		retorno=0;
	}
	return retorno;
}

int employee_createId(void)
{
	int id;
	int retorno=-1;
	char idChar[16];
    FILE *idMax;
    idMax=fopen("idMaxFile.txt", "r");
    if(idMax!=NULL)
        {
    	fscanf(idMax,"%s",idChar);
    	id=atoi(idChar);
    	retorno=id;
    	fclose(idMax);
    	if(fopen("idMaxFile.txt", "w"))
    	{
    		id=id+1;
    		fprintf(idMax,"%d",id);
    		fclose(idMax);
    	}


        }
        else
        {

        	idMax=fopen("idMaxFile.txt", "w");
        	if(idMax!=NULL)
        	{
            	fprintf(idMax,"%d",1002);
            	retorno=1001;
            	fclose(idMax);
        	}
        }
    return retorno;
}
int employee_getOrden(int *orden, int *tipo)
{
	int retorno=-1;
	if(tipo!= NULL &&  orden!=NULL && utn_pedirIntAUsuarioConLimites(orden, 1, 4, 3, "Ingresar El tipo de ordenamiento\n 1.-Id\n 2.-Nombre\n 3.-Sueldo\n 4.-Horas Trabajadas\n",
			"Error")==0 && utn_pedirIntAUsuarioConLimites(tipo, 0, 1, 3, "Ingrese\n 1.-Creciente\n 0.-Decreciente", "error")==0)
	{
		retorno=0;
	}
	else
	{
		printf("Opcion no Dispobible\n");
	}
	return retorno;
}

int employee_compareById(void* employee1, void* employee2)
{
	int retorno;

	Employee* employeeAux1 = (Employee*)employee1;
	Employee* employeeAux2 = (Employee*)employee2;
	int id1;
	int id2;
	employee_getId(employeeAux1, &id1);
	employee_getId(employeeAux2, &id2);
	if(id1>id2)
	{
		retorno=1;
	}
	else
	{
		if(id1==id2)
		{
			retorno=0;
		}
		else
		{
			retorno=-1;
		}
	}

	return retorno;
}


int employee_compareBySueldo(void* employee1, void* employee2)
{
	int retorno;
	Employee* employeeAux1 = (Employee*)employee1;
	Employee* employeeAux2 = (Employee*)employee2;
	int sueldo1;
	int sueldo2;
	employee_getSueldo(employeeAux1, &sueldo1);
	employee_getSueldo(employeeAux2, &sueldo2);
	if(sueldo1>sueldo2)
	{
		retorno=1;
	}
	else
	{
		if(sueldo1==sueldo2)
		{
			retorno=0;
		}
		else
		{
			retorno=-1;
		}
	}
	return retorno;
}


int employee_compareByHoras(void* employee1, void* employee2)
{
	int retorno;
	Employee* employeeAux1 = (Employee*)employee1;
	Employee* employeeAux2 = (Employee*)employee2;
	int horas1;
	int horas2;
	employee_getHorasTrabajadas(employeeAux1, &horas1);
	employee_getHorasTrabajadas(employeeAux2, &horas2);
	if(horas1>horas2)
	{
		retorno=1;
	}
	else
	{
		if(horas1==horas2)
		{
			retorno=0;
		}
		else
		{
			retorno=-1;
		}
	}
	return retorno;
}

int employee_compareByName(void* employee1, void* employee2)
{
	int retorno;
	Employee* employeeAux1 = (Employee*)employee1;
	Employee* employeeAux2 = (Employee*)employee2;

	char name1[128];
	char name2[128];
	employee_getNombre(employeeAux1, name1);
	employee_getNombre(employeeAux2, name2);
	int tam=strcmp(name1,name2);
	if(tam>0)
	{
		retorno=1;
	}else
	{
		if (tam==0)
		{
			retorno=0;
		}
		else
		{
			retorno=-1;
		}
	}

return retorno;
}


