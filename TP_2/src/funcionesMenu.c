/*
 * funcionMenu.c
 *
 *  Created on: 10 May 2022
 *      Author: Santiago
 */


#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "funcionesMenu.h"
#include "utn_get.h"

#define CANT 2000

int abm(){

	int option=0;
	int flag=0;
    int submitedID;
	char submitedName[51];
	char submitedLastname[51];
	char submitedFlycode[10];
	float submitedPrice;
	int submitedFlightStatus;
	int submitedPassengerType;


	Passenger passengerList[CANT];

	if(initPassengers(passengerList, CANT)==-1){

		printf("ERROR");
		return -1;
	} //incializo el array con la funcion initPassengers, en caso de haber algun error terminamos el programa

	while(option!=6) //Uso un switch dentro de un  while para hacer un menu
	{
		printf("\n1-Altas\n"
				"2-Modificar\n"
				"3-Baja\n"
				"4-Informar\n"
				"5-Alta forzada\n"
				"6-Finalizar\n"); //Informo al usuario las opciones

		printf("Ingrese el numero de opcion");
		scanf("%d", &option);
		switch(option)
		{
			case 1: //Opcion 1 para ingresar un pasajero

				if(lookEmptyIndex(passengerList, CANT)!=-1)
				{
					submitedID=getRandID(passengerList,CANT);//utilizo la funcion getRandID para poder obtener un ID al azar entre 1000 y 9999 que no este ocupado
					if((utn_getAlphastr(submitedName, "Ingrese el nombre del pasajero", "\nNombre invalido\n")==-1) ||
					(utn_getAlphastr(submitedLastname, "Ingrese el apellido del pasajero", "\nApellido invalido\n")==-1) ||
					(utn_getFloat(&submitedPrice, "Ingrese el costo del vuelo", "\nCosto invalido\n",500000,15000,100)==-1) ||
					(utn_getInt(&submitedPassengerType, "Ingrese clase del pasajero\n1-Turista\n2-Ejecutiva\n3-P.Clase", "\nPor favor ingrese el numero de clase\n", 3, 1, 100)==-1) ||
					(utn_getInt(&submitedFlightStatus, "Ingrese el estado del vuelo\n1-Activo\n2-Retrasado\n3-Cancelado", "\nPor favor ingrese el numero de estado\n", 3, 1, 100)==-1) ||
					(utn_getAlnumstr(submitedFlycode, "Ingrese el codigo de vuelo", "\nCodigo invalido\n")==-1)||
					submitedID==-1)
					{
						printf("Error en el ingreso de datos");
						break;
					}//Valido que todas las funciones hayan salido bien utilizando un if



					if(addPassenger(passengerList, CANT, submitedID, submitedName,submitedLastname,submitedPrice,submitedPassengerType, submitedFlycode, submitedFlightStatus)!=-1)//utilizo la funcion addPassenger para cargar los datos que le pedimos al usuario
					{
						flag=1;
					}else{
						printf("Error en la carga de datos");
					}//Valido la carga de datos y en caso de haberse cargado datos uso un flag para indicar que la base de datos contiene por lo menos un pasajero
				}else{
					printf("Error, es posible que la base de datos este llena");
				}//Valido que haya espacio libre, en caso de que la base de datos este llena

				break;
			case 2: //Opcion 2 para ingresar

				//utilizo las funciones printPassenger para mostrar una lista con todos los pasajeros ingresados y modifyPassenger para abrir el submenu de modificaciones. Utilizamos la funcion findPassengerById para poder subir el pasajero pedido por el usuario


				if(flag!=0){
					if(printPassenger(passengerList, CANT)==-1 ||
					utn_getInt(&submitedID, "Ingrese el ID del pasajero que desea modificar", "Por favor ingrese un ID valido", 9999, 1000, 100)==-1 ||
					modifyPassenger(passengerList[findPassengerById(passengerList,CANT,submitedID)], &passengerList[findPassengerById(passengerList,CANT,submitedID)])==-1)
					{
						printf("Error en la modificacion del pasajero");
					}
				}else{

					printf("\n Primero ingrese un pasajero, por favor");
				}//Si el flag esta en 0 le pedimos al usuario que ingrese un pasajero antes de poder continuar


				break;
			case 3: //Opcion 3 para dar de baja a un pasajero

				if(flag!=0){

					if(printPassenger(passengerList, CANT)==-1 ||
					utn_getInt(&submitedID, "Ingrese el ID del pasajero que desea eliminar", "ID invalido", 9999, 1000, 100)==-1||
					removePassenger(passengerList, CANT, submitedID)==-1)
					{
						printf("Error en la baja del pasajero");
						break;
					} //Nuevamente utilizo la funcion printPassenger, como en la opcion 2, y llamamos a la funcion removePassenger que abre una confirmacion antes de borrar permanentemente al pasajero ingresado

					if(isLoaded(passengerList, CANT) == 0){
						flag=0;
					}//Luego usamos la funcion isLoaded para asegurarnos de que no hayan quedado todos los espacios vacios, en caso de haber pasado volvemos a poner el flag en 0 para que el usuario no pueda entrar a las opciones 2,3 y 4
				}else{

					printf("\n Primero ingrese un pasajero, por favor");

				}

				break;
			case 4: //Opcion 4 Informa los pasajeros

				if(flag!=0){

					printf("\n1-Listado de pasajeros por Apellido y Tipo\n"
							"2-Promedio de precios y cantidad de pasajeros que lo exceden\n"
							"3-Listado de pasajeros por estado del vuelo y codigo de vuelo\n"
							"4-Cancelar\n"); //Informo al usuario las opciones disponibles

					printf("Ingrese el numero de opcion");
					scanf("%d", &option);
					switch(option){

					case 1:

						if(sortPassengers(passengerList, CANT, 1)==-1||
						printPassenger(passengerList, CANT)==-1)
						{
							printf("Error en el listado del pasajero");
						}
						break; //utilizando sortPassengers ordenamos a la lista de pasajeros de la forma deseada, y utilizamos printPassenger para mostrar la lista ordenada

					case 2:

						if(showPassengerPrice(passengerList, CANT)==-1){
							printf("Error en el listado de precios");
						} //La funcion showPassengerPrice acumula los precios, saca el promedio y nos muestra los pasajeros que exceden el promedio

						break;

					case 3:

						if(sortPassengers(passengerList, CANT, 1)==-1||
						printPassenger(passengerList, CANT)==-1)
						{
							printf("Error en el listado del pasajero");
						}
						break;

					case 4:
						printf("Cancelando funcion");
						break;


					}



				}else{

					printf("\n Primero ingrese un pasajero, por favor");

				}



				break;
			case 5://Opcion 5 para ingresar carga de forma forzada los datos con valores hardcodeados

				for(int i=0;i<CANT;i++){

					if(passengerList[i].isEmpty == 1 ){
						passengerList[i].id=getRandID(passengerList,CANT);
						strcpy(passengerList[i].name, "Jose");
						strcpy(passengerList[i].lastName, "de San Martin");
						strcpy(passengerList[i].flycode, "ARG 1816");
						passengerList[i].price=50000;
						passengerList[i].typePassenger=1;
						passengerList[i].statusFlight=1;
						passengerList[i].isEmpty=0;
					}

				}
				flag=1;

				break;

			case 6: //Opcion 6 finaliza el programa

				printf("Programa Finalizado");
				break;

			default:
				printf("Por favor ingrese una opcion valida");
				break;

		}
	}

	return 0;

}
