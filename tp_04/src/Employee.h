#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define NOMBRE_LEN 128
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


int employee_createId(void);
Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
int employee_setNombreFile(Employee* pEmployee,char* nombre);
int employee_setHorasTrabajadasFile(Employee* pEmployee,char* horasTrabajadas);
int employee_setIdFile(Employee* pEmployee,char* id);
int employee_setSueldoFile(Employee* pEmployee,char* sueldo);

void employee_delete(Employee* pEmployee);

int employee_setId(Employee* pEmployee,int id);
int employee_getId(Employee* pEmployee,int* id);

int employee_setNombre(Employee* pEmployee,char* nombre);
int employee_getNombre(Employee* pEmployee,char* nombre);

int employee_setHorasTrabajadas(Employee* pEmployee,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* pEmployee,int* horasTrabajadas);

int employee_setSueldo(Employee* pEmployee,int sueldo);
int employee_getSueldo(Employee* pEmployee,int* sueldo);

//int employee_addEmployee(LinkedList *pListEmployee);

int employee_findById(LinkedList *pListEmployee, int id);

int employee_printEmployee(Employee *Employee);
int employee_getOrden(int *orden, int *tipo);

int employee_compareById(void* employee1, void* employee2);
int employee_compareBySueldo(void* employee1, void* employee2);
int employee_compareByHoras(void* employee1, void* employee2);
int employee_compareByName(void* employee1, void* employee2);

//int employee_

#endif // employee_H_INCLUDED
