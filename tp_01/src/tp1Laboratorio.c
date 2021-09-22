/*
 ============================================================================
 Name        : tp1Laboratorio.c
 Author      : Gustavo Vargas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calcu.h"


int main(void)
{


setbuf(stdout,NULL);
int menu;
float operandoUno;
float operandoDos;
int opeUno;
int opeDos;
float suma;
float resta;
float multiplicacion;
float division;
int factorialUno;
int factorialDos;
int banderaoperandoUno=-1;
int banderaoperandoDos=-1;
int banderaCalculoDeResultados=-1;
int banderaDivision;
int banderaFactorialUno;
int banderaFactorialDos;
do
	{
		fflush( stdin );
		mostrarMenuUsuario(&menu, operandoUno, operandoDos, banderaoperandoUno, banderaoperandoDos);

			switch(menu)
			{
				case 1:
					banderaoperandoUno=utn_pedirFloatAUsuario(&operandoUno, "Ingrese Operando 1:\n", "error, intentelo nuevamente\n");
					break;
				case 2:
					if(banderaoperandoUno!=0)
						{
							printf("Primero debe Ingresar el Operando Uno\n");
						}else
						{
							banderaoperandoDos=utn_pedirFloatAUsuario(&operandoDos, "Ingrese Operando 2:\n", "error, intentelo nuevamente\n");
						}
					break;
				case 3:
					if(banderaoperandoDos==-1)
					{
						printf("Debe Ingresar Ambos Operadores para usar esta opcion\n");
					}else
					{
						sumarNumerosFloat(operandoUno, operandoDos, &suma);
						restarNumerosFloat(operandoUno, operandoDos, &resta);
						multiplicarNumerosFloat(operandoUno, operandoDos, &multiplicacion);
						banderaDivision=dividirNumerosFloat(operandoUno, operandoDos, &division);
						banderaFactorialUno=factorialEnteros(operandoUno, &factorialUno, &opeUno);
						banderaFactorialDos=factorialEnteros(operandoDos, &factorialDos, &opeDos);
						banderaCalculoDeResultados=0;
					}
					break;
				case 4:
					if(banderaCalculoDeResultados==0)
					{
						printf("El resultado de %.2f + %.2f es: %.2f\n", operandoUno, operandoDos, suma);
						printf("El resultado de %.2f - %.2f es: %.2f\n", operandoUno, operandoDos, resta);
						printf("El resultado de %.2f x %.2f es: %.2f\n", operandoUno, operandoDos, multiplicacion);
						if(banderaDivision==0)
						{
							printf("El resultado de %.2f / %.2f es: %.2f\n", operandoUno, operandoDos, division);
						}
						else
						{
							printf("No es Posible la division Entre 0\n");
						}
						if (banderaFactorialUno==0)
						{
							printf("El Factorial de %d es %d\n", opeUno, factorialUno);
						}
						else
						{
							printf("No es Posible hallar Factorial para %d, fuera de rango (0-12) \n", opeUno);
						}
						if (banderaFactorialDos==0)
						{
							printf("El Factorial de %d es %d\n", opeDos, factorialDos);
						}
						else
						{
							printf("No es Posible hallar Factorial para %d, fuera de rango (0-12) \n", opeDos);
						}
					}
					else
					{
						printf("Recuerde Deben Ingresar Primero los dos Operando y luego la opcion de calcular operaciones\n");
					}
					break;

			}

	}while(menu!=5);


	return EXIT_SUCCESS;
}
