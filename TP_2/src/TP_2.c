/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "utn_get.h"
#include <time.h>
#include "funcionesMenu.h"

int main(void) {


	setbuf(stdout,NULL);
	srand(time(NULL));


	abm();//Llamo a mi funcion abm que contiene el menu y todas sus funcionalidades


	return EXIT_SUCCESS;
}
