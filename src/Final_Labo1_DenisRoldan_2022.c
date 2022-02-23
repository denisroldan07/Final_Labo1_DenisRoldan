/*
 ============================================================================
 Name        : Final_Labo1_DenisRoldan_2022.c
 Author      : Denis Roldán
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "controller.h"
#include "eParticipantes.h"
#include "LinkedList.h"
#include "inputs.h"


int main(void)
{
		setbuf(stdout, NULL);
		int option = 0;
	    int flag = 0;
	    int flag1 = 0;
	    int flag2 = 0;

			    LinkedList* listaDeParticipantes = ll_newLinkedList();
			    LinkedList* listaDeParticipantesFiltrada = ll_newLinkedList();

			    do{
					getEntero(&option,99999999, "-------------------------------------\n"
												"1. Cargar los datos del Log.txt\n"
												"2. Imprimir lista\n"
												"3. Agregar estadisticas\n"
												"4. Filtrar por MX1\n"
												"5. Filtrar por MX2\n"
												"6. Filtrar por MX3\n"
												"7. Filtrar por SUPER_ATV\n"
												"8. Mostrar posiciones\n"
												"9. Guardar posiciones\n"
												"10. Salir\n"
										 	 	"-------------------------------------\n"
										 	 	"Ingrese una opcion: ",
												"-------------------------------------\n"
												"1. Cargar los datos del Log.txt\n"
												"2. Imprimir lista\n"
												"3. Agregar estadisticas\n"
												"4. Filtrar por MX1\n"
												"5. Filtrar por MX2\n"
												"6. Filtrar por MX3\n"
												"7. Filtrar por SUPER_ATV\n"
												"8. Mostrar posiciones\n"
												"9. Guardar posiciones\n"
												"10. Salir\n"
												"-------------------------------------\n"
												"Opcion invalida , por favor intentelo de nuevo:\n", 1, 10);

			    switch(option)
			    {
					case 1:
						controller_loadFromText("enduro.csv", listaDeParticipantes);
						printf("Se cargo el archivo correctamente !\n");
						flag = 1;
						break;
					case 2:
						if(flag == 0)
						{
							printf("Apreta 1 primero \n");
						}else
						{
							eParticipantes_mostrarTodosLosParticipantes(listaDeParticipantes);
						}
						break;
					case 3:
						if(flag == 0)
						{
							printf("Apreta 1 primero \n");
						}else
						{
							ll_mapL(listaDeParticipantes,eParticipantes_funcionMap);
							flag1 = 1;

						}
						break;
					case 4:
						if(flag == 0)
						{
							printf("Apreta 1 primero \n");
						}else
						{
							listaDeParticipantesFiltrada = ll_filter(listaDeParticipantes,eParticipantes_filtrarPorMX1);

							eParticipantes_mostrarTodosLosParticipantes(listaDeParticipantesFiltrada);
							controller_saveAsText("MX1.csv", listaDeParticipantesFiltrada);
						}
						break;
					case 5:
						if(flag == 0)
						{
							printf("Apreta 1 primero \n");
						}else
						{
							listaDeParticipantesFiltrada = ll_filter(listaDeParticipantes,eParticipantes_filtrarPorMX2);

							eParticipantes_mostrarTodosLosParticipantes(listaDeParticipantesFiltrada);
							controller_saveAsText("MX2.csv", listaDeParticipantesFiltrada);
						}

						break;
					case 6:
						if(flag == 0)
						{
							printf("Apreta 1 primero \n");
						}else
						{
							listaDeParticipantesFiltrada = ll_filter(listaDeParticipantes,eParticipantes_filtrarPorMX3);

							eParticipantes_mostrarTodosLosParticipantes(listaDeParticipantesFiltrada);
							controller_saveAsText("MX3.csv", listaDeParticipantesFiltrada);
						}
						break;
					case 7:

						if(flag == 0)
						{
							printf("Apreta 1 primero \n");
						}else
						{
							listaDeParticipantesFiltrada = ll_filter(listaDeParticipantes,eParticipantes_filtrarPorSuperAtv);

							eParticipantes_mostrarTodosLosParticipantes(listaDeParticipantesFiltrada);
							controller_saveAsText("SUPER_ATV.csv", listaDeParticipantesFiltrada);
						}
						break;
					case 8:
						if(flag == 0 || flag1 == 0)
						{
							printf("Apreta 1 primero o si ya lo hiciste , apreta 3 \n");
						}else
						{
							ll_sort(listaDeParticipantes, eParticipantes_sortCategoria, 1);
							eParticipantes_mostrarTodosLosParticipantes(listaDeParticipantes);
							flag2 = 1;


						}
						break;
					case 9:
						if(flag == 0 || flag2 == 0)
						{
							printf("Apreta 1 primero y si ya lo hiciste apreta 8 y luego 9\n");
						}else
						{
							controller_saveAsText("participantes.txt", listaDeParticipantes);
						}
						break;

					case 10:
						printf("Salio exitosamente !");
						break;
			    }
			    }while(option != 10);

			    return 0;
		return EXIT_SUCCESS;
}
