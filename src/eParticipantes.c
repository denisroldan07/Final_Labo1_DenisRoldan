/*
 * eParticipantes.c
 *
 *  Created on: Feb 23, 2022
 *      Author: denis
 */


#include "eParticipantes.h"

eParticipantes* eParticipantes_new()
{
	eParticipantes* participantesRetorno = NULL;
	participantesRetorno = (eParticipantes*) malloc (sizeof(eParticipantes));
	return participantesRetorno;
}

eParticipantes* eParticipantes_newParametros(char* idStr,char* nombre,char* categoria,char* tiempoStr ,char* promedioStr)
{
	eParticipantes* participantes = NULL;
	participantes = eParticipantes_new();
	int id = atoi(idStr);
	int tiempo = atoi(tiempoStr);
	int promedio = atoi(promedioStr);
	if(participantes != NULL){
		eParticipantes_setId(participantes, id);
		eParticipantes_setNombre(participantes, nombre);
		eParticipantes_setCategoria(participantes, categoria);
		eParticipantes_setTiempo(participantes, tiempo);
		eParticipantes_setPromedio(participantes, promedio);

	}
	return participantes;
}


int eParticipantes_setId(eParticipantes* this,int id)
{
	int seCargo = 0;
	if(this != NULL)
	{
		this->id_cuatri = id;
		seCargo = 1;
	}
	return seCargo;
}

int eParticipantes_getId(eParticipantes* this,int* id)
{
	int seCargo = 0;
	if(this != NULL)
	{
		*id = this->id_cuatri;
		seCargo = 1;
	}
	return seCargo;
}

int eParticipantes_setNombre(eParticipantes* this,char* nombre)
{
	int seCargo = 0;
	if(this != NULL)
	{
		strcpy(this->nombre,nombre);
		seCargo = 1;
	}
	return seCargo;
}

int eParticipantes_getNombre(eParticipantes* this , char* nombre)
{
	int seCargo = 0;
	if(this != NULL)
	{
		strcpy(nombre,this->nombre);
		seCargo = 1;
	}
	return seCargo;
}

int eParticipantes_setCategoria(eParticipantes* this,char* categoria)
{
	int seCargo = 0;
	if(this != NULL)
	{
		strcpy(this->categoria,categoria);
		seCargo = 1;
	}
	return seCargo;
}

int eParticipantes_getCategoria(eParticipantes* this , char* categoria)
{
	int seCargo = 0;
	if(this != NULL)
	{
		strcpy(categoria,this->categoria);
		seCargo = 1;
	}
	return seCargo;
}

int eParticipantes_setTiempo(eParticipantes* this,int tiempo)
{
	int seCargo = 0;
	if(this != NULL)
	{
		this->tiempo = tiempo;
		seCargo = 1;
	}
	return seCargo;
}

int eParticipantes_getTiempo(eParticipantes* this,int* tiempo)
{
	int seCargo = 0;
	if(this != NULL)
	{
		*tiempo = this->tiempo;
		seCargo = 1;
	}
	return seCargo;
}

int eParticipantes_setPromedio(eParticipantes* this,int promedio)
{
	int seCargo = 0;
	if(this != NULL)
	{
		this->promedio = promedio;
		seCargo = 1;
	}
	return seCargo;
}

int eParticipantes_getPromedio(eParticipantes* this,int* promedio)
{
	int seCargo = 0;
	if(this != NULL)
	{
		*promedio = this->promedio;
		seCargo = 1;
	}
	return seCargo;
}

int eParticipantes_mostrarTodosLosParticipantes(LinkedList* pArrayListParticipantes)
{
	int seMostro = 0;
	eParticipantes* aux = NULL;

	if(pArrayListParticipantes != NULL)
	{
		int ll_tam = ll_len(pArrayListParticipantes);

		printf("%s %30s %30s %30s %30s \n","ID","NOMBRE","CATEGORIA","TIEMPO","PROMEDIO");
		for (int i = 0; i < ll_tam; ++i)
		{
			aux = ll_get(pArrayListParticipantes, i);
			//printf("%d %30s %30d %30d %30d \n",aux->id,aux->user,aux->likes,aux->dislikes,aux->followers);
			eParticipantes_mostrarParticipantes(aux);
		}
		seMostro = 1;
	} else
	{
		printf("Error al cargar los participantes");
		systemPause("Pulse cualquier tecla para continuar\n");
	}

	return seMostro;
}

int eParticipantes_mostrarParticipantes(eParticipantes* this)
{
	int seMostro = 0;

	int id;
	char nombre[30];
	char categoria[30];
	int tiempo;
	int promedio;

	if(this != NULL)
	{

	eParticipantes_getId(this, &id);
	eParticipantes_getNombre(this, nombre);
	eParticipantes_getCategoria(this, categoria);
	eParticipantes_getTiempo(this, &tiempo);
	eParticipantes_getPromedio(this, &promedio);

	printf("%d %30s %30s %30d %30d \n",id,nombre,categoria,tiempo,promedio);
	seMostro = 1;
	}

	return seMostro;
}

void eParticipantes_funcionMap(void* element)
{
	element = (eParticipantes*)element;

	int tiempo;
	if(element != NULL)
	{
		eParticipantes_getTiempo(element, &tiempo);
		if(tiempo > 20)
		{
			eParticipantes_setPromedio(element, 10);
		} else if(tiempo >= 15 && tiempo <= 20 )
		{
			eParticipantes_setPromedio(element,8);
		} else
		{
			eParticipantes_setPromedio(element,6);
		}

	}
}

int eParticipantes_filtrarPorMX1(void* element)
{
	int filtro = -1;
	element = (eParticipantes*) element;
	char categoria[50];
	eParticipantes_getCategoria(element, categoria);
		if(strcmp(categoria,"MX1") == 0)
		{
			filtro = 0;
		} else
		{
			filtro = 1;
		}

	return filtro;
}

int eParticipantes_filtrarPorMX2(void* element)
{
	int filtro = -1;
	element = (eParticipantes*) element;
	char categoria[50];
	eParticipantes_getCategoria(element, categoria);
		if(strcmp(categoria,"MX2") == 0)
		{
			filtro = 0;
		} else
		{
			filtro = 1;
		}

	return filtro;
}

int eParticipantes_filtrarPorMX3(void* element)
{
	int filtro = -1;
	element = (eParticipantes*) element;
	char categoria[50];
	eParticipantes_getCategoria(element, categoria);
		if(strcmp(categoria,"MX3") == 0)
		{
			filtro = 0;
		} else
		{
			filtro = 1;
		}

	return filtro;
}

int eParticipantes_filtrarPorSuperAtv(void* element)
{
	int filtro = -1;
	element = (eParticipantes*) element;
	char categoria[50];
	eParticipantes_getCategoria(element, categoria);
		if(strcmp(categoria,"SUPER_ATV") == 0)
		{
			filtro = 0;
		} else
		{
			filtro = 1;
		}

	return filtro;
}

int eParticipantes_sortCategoria(void* part1 , void* part2)
{
	int seSorteo = 1;
	eParticipantes* partAux1;
	eParticipantes* partAux2;
	if(part1 != NULL && part2 != NULL)
	{
		partAux1 = (eParticipantes*)part1;
		partAux2 = (eParticipantes*)part2;
		// 1 ascendente , -1 descendente
		if(strcmp(partAux1->categoria,partAux2->categoria) == 1)
		{
			seSorteo = -1;

		}else if(strcmp(partAux1->categoria,partAux2->categoria) == 0)
		{
			if(partAux1->promedio < partAux2->promedio){
				seSorteo = -1;
			}
		}

	}
	return seSorteo;
}

