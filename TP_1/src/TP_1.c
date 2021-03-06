/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h" //Uso include para traer la biblioteca "calculos.h" que voy a utilizar

int main(void) {

	setbuf(stdout,NULL); //setbuf para poder utilizar el programa en la consola
	system("CLS");

	int opcion; //Declaro e inicializo todas la variables que voy a usar
	int flag=0;
	int km=0;
	float precioAero;
	float precioLatam=0;
	float descuentoAero=0;
	float descuentoLatam;
	float interesAero;
	float interesLatam;
	float kmAero;
	float kmLatam;
	float bitAero;
	float bitLatam;
	float diferenciaVar;

	while(opcion!=6) //Uso un switch dentro de un  while para hacer un menu
	{
		printf("\n1-Ingresar Kilometros: %d\n"
				"2-Ingresar Precios: Aerolineas = %.2f Latam = %.2f\n"
				"3-Calcular todos los costos\n"
				"4-Informar resultados\n"
				"5-Carga Forzada\n"
				"6-Finalizar\n", km, precioAero, precioLatam); //Informo al usuario las opciones

		printf("Ingrese el numero de opcion");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1: //Opcion 1 para ingresar los kilometros
				printf("Ingrese los Kilometros");
				scanf("%d", &km);
				break;
			case 2: //Opcion 2 para ingresar los precios
				printf("Ingrese el precio de Aerolineas");
				scanf("%f", &precioAero);
				printf("Ingrese el precio de Latam");
				scanf("%f", &precioLatam);
				break;
			case 3: //Opcion 3 para hacer los calculos

				if(precioAero!=0 && precioLatam!=0 && km!=0) //Valido que el usuario haya ingresado valores antes de calcular
				{
					descuento(precioAero, precioLatam, &descuentoAero, &descuentoLatam);
					interes(precioAero, precioLatam, &interesAero, &interesLatam);
					diferencia(precioAero, precioLatam, &diferenciaVar);
					bitcoin(precioAero, precioLatam, &bitAero, &bitLatam);
					kmAero=precioAero/km;
					kmLatam=precioLatam/km;
					flag=1;
					printf("\nCalculando resultados\n");
				}else
				{
					printf("\nAntes de calcular por favor ingrese distancia y precio\n");
				}
				break;
			case 4: //Opcion 4 para mostrar los resultados

				if(flag==1) //Valido que el usuario haya hecho los calculos antes de mostrar los resultados
				{
					printf("\nKilometros Ingresados: %d"
							"\nLatam:\n"
							"a) Precio con tarjeta de d?bito: %.2f\n"
							"b) Precio con tarjeta de cr?dito: %.2f\n"
							"c) Precio pagando con bitcoin : %.2f\n"
							"d) Precio unitario: %.2f\n"
							"\nAerol?neas:\n"
							"a) Precio con tarjeta de d?bito: %.2f\n"
							"b) Precio con tarjeta de cr?dito: %.2f\n"
							"c) Precio pagando con bitcoin : %.2f\n"
							"d) Precio unitario: %.2f\n"
							"La diferencia de precio es : %.2f", km, descuentoLatam, interesLatam, bitLatam, kmLatam, descuentoAero, interesAero, bitAero,kmAero, diferenciaVar);

				}else
				{
					printf("\nAntes de mostrar datos debe calcular(Opcion 3)\n");
				}
				break;
			case 5: //Opcion 5 carga los datos
				km=790;
				precioLatam=162965;
				precioAero=159339;
				printf("\nLa carga forzada se realizo con exito\n");
				break;
			case 6: //Opcion 6 finaliza el programa
				printf("Programa Finalizado");
				break;
			default:
				printf("Por favor ingrese una opcion valida");

		}
	}

	return 0;
}
