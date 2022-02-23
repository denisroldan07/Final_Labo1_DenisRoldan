/*
 * parser.c
 *
 *  Created on: Feb 20, 2022
 *      Author: denis
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eParticipantes.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListperro LinkedList*
 * \return int
 *
 */
int parser_participantesFromText(FILE* pFile , LinkedList* pArrayListParticipantes)
{

	int seCargo = 0;
	pFile = fopen("enduro.csv", "r");
	char id[10];
	char nombre[50];
	char categoria[10];
	char tiempo[10];
	char promedio[10];

	if(pFile != NULL && pArrayListParticipantes != NULL){

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]",id,nombre,categoria,tiempo,promedio);
		while(!feof(pFile)){


			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]",id,nombre,categoria,tiempo,promedio);

			if(feof(pFile))
			{
				break;
			}

			eParticipantes* auxParticipantes = eParticipantes_newParametros(id, nombre,categoria, tiempo, promedio);
			//printf("%d , %s , %s , %d , %d\n",auxParticipantes->id_cuatri,auxParticipantes->nombre,auxParticipantes->categoria,auxParticipantes->tiempo,auxParticipantes->promedio);
			ll_add(pArrayListParticipantes,auxParticipantes);


			seCargo = 1;

		}
		fclose(pFile);
	}

	return seCargo;
}
