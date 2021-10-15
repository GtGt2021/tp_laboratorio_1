/*
 * ArrayEmployees.h
 *
 *  Created on: 15 oct. 2021
 *      Author: gt
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define LASTNAME_LEN 51
#define NAME_LEN 51
typedef struct{
	int sector_gen;
	float salary_employee;
	int id_employee;
	char name_employee [NAME_LEN];
	char lastName_employee [LASTNAME_LEN];
	int isEmpty_employee;
}Employee;

int init_employees(Employee lista[], int len);
int addEmployee(Employee lista[]);
int gen_imprimirLista(Employee lista[], int len);
int gen_esLibre(Employee lista[], int len, int *posicionLibre);
int findEmployeeById(Employee lista[], int len, int idBuscado, int *posicionIdBuscado);
int gen_modificarLista(Employee lista[]);
int gen_imprimirPosicion(Employee lista[]);
int removeEmployee(Employee lista[], int len, int idParaDarBaja);
int gen_verificarQueTieneDatosLista(Employee lista[], int len);
int gen_verificarIdExiste(Employee list[], int len, int idBuscado);
int gen_Altaforzada(Employee lista[], int sector, float salario, char nombre[], char apellido[]);
int sortEmployed(Employee lista[], int len, int orden);



#endif /* ARRAYEMPLOYEES_H_ */
