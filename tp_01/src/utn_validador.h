/*
 * utn_validador.h
 *
 *  Created on: 22 sep. 2021
 *      Author: gt
 */

#ifndef UTN_VALIDADOR_H_
#define UTN_VALIDADOR_H_



int utn_miFgets(char cadena[], int longitud);
int utn_esNumero(char cadena[]);
int utn_obtenerEntero(int *pResultado);
int utn_pedirIntAUsuario(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);
int utn_pedirFloatAUsuario(float* pResultado, char* variableTexto, char* textoError);







#endif /* UTN_VALIDADOR_H_ */
