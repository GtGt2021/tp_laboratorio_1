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

void mostrarMenuUsuario(int* pMenu, float operandoUno, float operandoDos, int banderaoperandoUno, int banderaoperandoDos);
int utn_pedirIntAUsuario(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);
int utn_pedirFloatAUsuario(float* pResultado, char* variableTexto, char* textoError);
//int factorialCalculadora(int operandoUno, int operandoDos);
float sumarNumerosFloat(float operandoUno, float operandoDos);
float restarNumerosFloat(float operandoUno, float operandoDos);
float multiplicarNumerosFloat(float operandoUno, float operandoDos);
int dividirNumerosFloat(float operandoUno, float operandoDos, float *pResultadoDivision);


int main(void)
{


setbuf(stdout,NULL);
int menu;
float operandoUno;
float operandoDos;
int banderaoperandoUno=-1;
int banderaoperandoDos=-1;
int banderaCalculoDeResultados=-1;
int banderaDivision=-1;
float resultadoDivision;
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
						sumarNumerosFloat(operandoUno, operandoDos);
						restarNumerosFloat(operandoUno, operandoDos);
						multiplicarNumerosFloat(operandoUno, operandoDos);
						banderaDivision=dividirNumerosFloat(operandoUno, operandoDos, &resultadoDivision);
						banderaCalculoDeResultados=0;
					}
					break;
				case 4:
					if(banderaCalculoDeResultados==-1 && (banderaoperandoUno==-1 || banderaoperandoDos==-1))
					{
						printf("Recuerde Deben Ingresar Primero los dos Operando y luego la opcion de calcular operaciones\n");
					}else
					{
						sumarNumerosFloat(operandoUno, operandoDos);
						restarNumerosFloat(operandoUno, operandoDos);
						multiplicarNumerosFloat(operandoUno, operandoDos);
						dividirNumerosFloat(operandoUno, operandoDos, &resultadoDivision);
					}
					break;
			}

	}while(menu!=5);


	return EXIT_SUCCESS;
}

void mostrarMenuUsuario(int* pMenu, float operandoUno, float operandoDos, int banderaOperandoUno, int banderaOperandoDos)
{
	if(banderaOperandoUno==0 && pMenu!=NULL)
	{
		printf("Presione 1 para Ingresar 1er Operando:A=%.2f\n", operandoUno);
	}else
	{
		printf("Presione 1 para Ingresar 1er Operando:A=X\n");
	}
	if(banderaOperandoDos==0)
	{
		printf("Presione 2 para Ingresar 2do Operando:B=%.2f\n", operandoDos);
	}else
	{
		printf("Presione 2 para Ingresar 2do Operando:B=Y\n");
	}
	printf("Presione 3 para calcular todas las operaciones\n");
	printf("presione 4 para informar resultados\n");
	printf("Presione 5 para salir\n");
	scanf("%d", pMenu);
}

int utn_pedirFloatAUsuario(float* pResultado, char* variableTexto, char* textoError)
{
	float buffer;
	int retorno;
	if(pResultado != NULL && variableTexto != NULL && textoError != NULL)
	{
			printf("%s\n",variableTexto);
			fflush( stdin );
			retorno=scanf("%f", &buffer);

			if (retorno==1)
			{
				*pResultado=buffer;
				retorno=0;
			}
			else
			{
				printf("%s\n", textoError);
				retorno=-1;
			}
	}
	return retorno;
}

int utn_pedirIntAUsuario(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError)
{
	int buffer;
	int retorno=-1;
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL && min<max && reintentos>=0)
	{
		do
		{
			printf("%s",variableTexto);
			fflush( stdin );
			scanf("%d", &buffer);

			if (scanf("%d", &buffer)==1 && buffer>=min && buffer<=max)
			{
				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				printf("%s, %s\n", textoError, variableTexto);
				reintentos--;
			}
		}while (reintentos >=0);
	}
	return retorno;
}

float sumarNumerosFloat(float operandoUno, float operandoDos)
{
	float resultado;
	resultado=operandoUno+operandoDos;
	return resultado;
}
float restarNumerosFloat(float operandoUno, float operandoDos)
{
	float resultado;
	resultado=operandoUno-operandoDos;
	return resultado;
}
float multiplicarNumerosFloat(float operandoUno, float operandoDos)
{
	float resultado;
	resultado=operandoUno*operandoDos;
	return resultado;
}
int dividirNumerosFloat(float operandoUno, float operandoDos, float *pResultadoDivision)
{
	int retorno=-1;
	if (pResultadoDivision != NULL && operandoDos!=0)
	{
		*pResultadoDivision=operandoUno/operandoDos;
		retorno=0;
	}
	return retorno;
}
/*
int factorialCalculadora(int operandoUno, int operandoDos)
{

}
*/
