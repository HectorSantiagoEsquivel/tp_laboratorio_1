/*
 * calculos.c
 *
 *  Created on: 12 Apr 2022
 *      Author: Santiago
 */


#include <stdio.h>
#include <stdlib.h>

int descuento(float numero1, float numero2, float* descuento1, float* descuento2){

	int retorno=-1;
	int porcentaje=10;

	if(descuento1!=NULL && descuento2!=NULL){

		retorno=1;

		*descuento1=numero1-(numero1*porcentaje/100);
		*descuento2=numero2-(numero2*porcentaje/100);


	}


	return retorno;
}

int bitcoin(float numero1, float numero2, float *bitcoin1, float *bitcoin2){

	int retorno=-1;

	if(bitcoin1!= NULL && bitcoin2!= NULL){

		retorno=1;

		*bitcoin1=numero1/4606954.55;
		*bitcoin2=numero2/4606954.55;


	}


	return retorno;
}

int interes(float numero1, float numero2, float *interes1, float *interes2){

	int retorno=-1;
	int porcentaje=25;

	if(interes1!=NULL && interes2!=NULL){

		retorno=1;

		*interes1=numero1+(numero1*porcentaje/100);
		*interes2=numero2+(numero2*porcentaje/100);


	}


	return retorno;
}

int diferencia(float numero1, float numero2, float *diferenciaVar)
{
	int retorno=-1;

	if(diferenciaVar!=NULL){

		retorno=1;

		if(numero1>numero2){

			*diferenciaVar=numero1-numero2;

		}else{
			*diferenciaVar=numero2-numero1;
		}


	}



	return retorno;
}
