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
#include "utn_validador.h"

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
		mostrarMenuUsuario(operandoUno, operandoDos, banderaoperandoUno, banderaoperandoDos);
		if (utn_pedirIntAUsuario(&menu, 1, 5, 3, "Ingrese una opcion [1-5]","opcion Invalida")==0)
		{

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
						printf("calculando Resultados, ");
						system("pause");
					}
					break;
				case 4:
					if(banderaCalculoDeResultados==0)
					{
						printf("\n------------------------------------------\n");
						printf("\n------------------------------------------\n");
						printf("\n------------------------------------------\n");
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
						if (banderaFactorialUno==0 && banderaFactorialDos==0)
						{
							printf("El Factorial de %d es: %d y el Factorial de %d es: %d\n", opeUno, factorialUno, opeDos, factorialDos);
						}
						else
						{
							if (banderaFactorialUno==0 && banderaFactorialDos!=0)
							{
								printf("El Factorial de %d es: %d y %d esta fuera de rango (0-12) para calcular su Factorial", opeUno, factorialUno, opeDos);
							}
							else
							{
								if (banderaFactorialUno!=0 && banderaFactorialDos==0)
								{
									printf("%d esta fuera de rango (0-12) para calcular su Factorial y el Factorial de %d es: %d", opeUno, opeDos, factorialDos);
								}
								else
								{
									printf("%d esta fuera de rango (0-12) para calcular su Factorial y %d esta fuera de rango (0-12) para calcular su Factorial", opeUno, opeDos);
								}
							}
						}
						/*else
						{
							if printf("No es Posible hallar Factorial para %d, fuera de rango (0-12) \n", opeUno);
						}
						if (banderaFactorialDos==0)
						{
							printf("El Factorial de %d es %d\n", opeDos, factorialDos);
						}
						else
						{
							printf("No es Posible hallar Factorial para %d, fuera de rango (0-12) \n", opeDos);
						}*/
						printf("\n------------------------------------------\n");
						printf("\n------------------------------------------\n");
						system("pause");
					}
					else
					{
						printf("Recuerde Deben Ingresar Primero los dos Operando y luego la opcion de calcular operaciones\n");
					}
					break;
				case 5:
					printf("Has Seleccionado Salir... Hasta Luego...");
					break;
			}
		}
		else
		{
			printf("Ingresaste Varias Veces Una opcion Invalida, Hasta luego...");
			break;
		}

	}while(menu!=5);


	return EXIT_SUCCESS;
}
