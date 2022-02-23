/*
 * controller.c
 *
 *  Created on: Nov 26, 2021
 *      Author: denis
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "inputs.h"
#include "parser.h"
#include "eParticipantes.h"

int controller_loadFromText(char* path , LinkedList* pArrayListLog)
{
	int seCargo = 0;
	if(path != NULL && pArrayListLog != NULL)
	{
		FILE* pFile = fopen(path,"r");
		if(pFile != NULL)
		{
			//FILE* pFile = fopen("log.txt", "r");
			parser_participantesFromText(pFile,pArrayListLog);
			seCargo = 1;
			systemPause("Toque cualquier letra para continuar ...");
		} else
		{
			printf("pFile es nulo");
		}

	} else
	{
		printf("Error al cargar los datos.");
	}

    return seCargo;
}


int controller_saveAsText(char* path , LinkedList* pArrayListPost)
{
	int seCargo = 0;
	FILE* pFile;
	pFile = fopen(path,"w");
	if(pFile != NULL)
	{
		eParticipantes* auxParticipantes;

		int ll_tam = ll_len(pArrayListPost);
		fprintf(pFile,"%s,%s,%s,%s,%s\n","ID","NOMBRE","CATEGORIA","TIEMPO","PROMEDIO");
		for(int i = 0 ; i < ll_tam ; i++)
		{
			auxParticipantes = ll_get(pArrayListPost,i);
			fprintf(pFile,"%d,%s,%s,%d,%d\n",auxParticipantes->id_cuatri,auxParticipantes->nombre,auxParticipantes->categoria,auxParticipantes->tiempo,auxParticipantes->promedio);
		}

		seCargo = 1;
	}
	fclose(pFile);
	printf("Archivo escrito exitosamente!\n");
	pFile = NULL;
    return seCargo;
}



