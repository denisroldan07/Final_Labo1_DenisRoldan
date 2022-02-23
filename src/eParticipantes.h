/*
 * eParticipantes.h
 *
 *  Created on: Feb 23, 2022
 *      Author: denis
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "LinkedList.h"

#ifndef EPARTICIPANTES_H_
#define EPARTICIPANTES_H_

struct eParticipantes
{
	int  id_cuatri;
	char nombre[30];
	char categoria[30];
	int  tiempo;
	int  promedio;
};
typedef struct eParticipantes eParticipantes;

eParticipantes* eParticipantes_new();
eParticipantes* eParticipantes_newParametros(char* idStr,char* nombre,char* categoria,char* tiempoStr ,char* promedioStr);
int eParticipantes_setId(eParticipantes* this,int id);
int eParticipantes_getId(eParticipantes* this,int* id);
int eParticipantes_setNombre(eParticipantes* this,char* nombre);
int eParticipantes_getNombre(eParticipantes* this , char* nombre);
int eParticipantes_setCategoria(eParticipantes* this,char* categoria);
int eParticipantes_getCategoria(eParticipantes* this , char* categoria);
int eParticipantes_setTiempo(eParticipantes* this,int tiempo);
int eParticipantes_getTiempo(eParticipantes* this,int* tiempo);
int eParticipantes_setPromedio(eParticipantes* this,int promedio);
int eParticipantes_getPromedio(eParticipantes* this,int* promedio);
int eParticipantes_mostrarParticipantes(eParticipantes* this);
int eParticipantes_mostrarTodosLosParticipantes(LinkedList* pArrayListParticipantes);
void eParticipantes_funcionMap(void* element);
int eParticipantes_filtrarPorMX1(void* element);
int eParticipantes_filtrarPorMX2(void* element);
int eParticipantes_filtrarPorMX3(void* element);
int eParticipantes_filtrarPorSuperAtv(void* element);
int eParticipantes_sortCategoria(void* part1 , void* part2);

#endif /* EPARTICIPANTES_H_ */
