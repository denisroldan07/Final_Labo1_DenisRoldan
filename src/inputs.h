/*
 * inputs.h
 *
 *  Created on: Oct 13, 2021
 *      Author: denis
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef INPUTS_H_
#define INPUTS_H_

int getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int min,int max);
int getFlotante(float*pFloat,int reintentos,char* msg,char*msgError,float min,float max);
int getCadena(char* pAux,int limite);
int pedirCaracter(char* caracter, char* mensaje);
int getInt(int* pAux);
int isInt(char *pAux);
int isFloat(char* pAux);
int getFloat(float*pAux);
int input_getCadena(char *pAux,int limite,int reintentos,char* msj,char*msjError);
int isLetras(char*pAux);
int verificarConfirmacion(char* mensaje);
int systemPause(char* message);
int printRandoms(int lower, int upper);
#endif /* INPUTS_H_ */
