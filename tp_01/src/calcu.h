/*
 * calcu.h
 *
 *  Created on: 21 sep. 2021
 *      Author: gt
 */

#ifndef CALCU_H_
#define CALCU_H_

void mostrarMenuUsuario(int* pMenu, float operandoUno, float operandoDos, int banderaoperandoUno, int banderaoperandoDos);
int utn_pedirIntAUsuario(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);
int utn_pedirFloatAUsuario(float* pResultado, char* variableTexto, char* textoError);
void sumarNumerosFloat(float operandoUno, float operandoDos, float *pResultado);
void restarNumerosFloat(float operandoUno, float operandoDos, float *pResultado);
void multiplicarNumerosFloat(float operandoUno, float operandoDos, float *pResultado);
int dividirNumerosFloat(float operandoUno, float operandoDos, float *pResultadoDivision);
int factorialEnteros(float operando, int *factorial, int *operandoInt);

#endif /* CALCU_H_ */
