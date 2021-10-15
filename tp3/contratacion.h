/*
 * generica.h
 *
 *  Created on: 12 oct. 2021
 *      Author: gt
 */

#ifndef CONTRATACION_H_
#define CONTRATACION_H_

#define CUIT_LEN 14
#define ADDRESS_LEN 128
#define NAME_LEN 128
typedef struct{
	char cuit_contra[CUIT_LEN];
	char nombreArchivo_contra [NAME_LEN];
	int estaOcupado_contra;
	int id_contra;
	int id_pantalla;
	int cantidadDias_contra;

}eContrataciones;

int contra_inicializarLista(eContrataciones lista[], int len);
int contra_ingresarDatosAListaPorId(eContrataciones lista[], int idPantalla);
int contra_imprimirLista(eContrataciones lista[], int len);
int contra_esLibre(eContrataciones lista[], int len, int *posicionLibre);
int contra_buscarId(eContrataciones lista[], int len, int idBuscado, int *posicionIdBuscado);
int contra_modificarLista(eContrataciones lista[]);
int contra_imprimirPocision(eContrataciones lista[]);
int contra_bajaPocision(eContrataciones lista[], int len, int idParaDarBaja);
int contra_verificarQueTieneDatosLista(eContrataciones lista[], int len);
int contra_buscarCuit(eContrataciones list[], int len, char cuitBuscado[]);

#endif /* CONTRATACION_H_ */
