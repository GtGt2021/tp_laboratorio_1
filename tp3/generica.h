/*
 * generica.h
 *
 *  Created on: 12 oct. 2021
 *      Author: gt
 */

#ifndef GENERICA_H_
#define GENERICA_H_

#define ADDRESS_LEN 128
#define NAME_LEN 128
typedef struct{
	int tipo_gen;
	float precio_gen;
	int id_gen;
	char nombre_gen [NAME_LEN];
	char direccion_gen [ADDRESS_LEN];
	int estaOcupado_gen;
}eGenerica;

int gen_inicializarLista(eGenerica lista[], int len);
int gen_ingresarDatosALista(eGenerica lista[]);
int gen_imprimirLista(eGenerica lista[], int len);
int gen_esLibre(eGenerica lista[], int len, int *posicionLibre);
int gen_buscarId(eGenerica lista[], int len, int idBuscado, int *posicionIdBuscado);
int gen_modificarLista(eGenerica lista[]);
int gen_imprimirPocision(eGenerica lista[]);
int gen_bajaPocision(eGenerica lista[], int len, int idParaDarBaja);
int gen_verificarQueTieneDatosLista(eGenerica lista[], int len);
int gen_verificarIdExiste(eGenerica list[], int len, int idBuscado);
int gen_Altaforzada(eGenerica lista[], int tipo, float precio, char nombre[], char direccion[]);
#endif /* GENERICA_H_ */
