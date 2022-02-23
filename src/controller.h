/*
 * controller.h
 *
 *  Created on: Nov 26, 2021
 *      Author: denis
 */

#include "LinkedList.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char* path , LinkedList* pArrayListLog);
int controller_saveAsText(char* path , LinkedList* pArrayListPost);


#endif /* CONTROLLER_H_ */
