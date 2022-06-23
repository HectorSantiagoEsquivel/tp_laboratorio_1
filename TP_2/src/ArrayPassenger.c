/*
 * ArrayPassenger.c
 *
 *  Created on: 23 Apr 2022
 *      Author: Santiago
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn_get.h"
#include "ArrayPassenger.h"

int initPassengers(Passenger list[], int len)
{
	int retorno = -1;
	if (list != NULL && len > 0) {
		retorno=0;
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = 1;//Buscamos todos los subindices del array y cambiamos el campo isEmpty a 1 para indicar que esta vacio
		}
	}

	return retorno;
}





int getRand()
{
	int retorno;

		retorno = rand()%(8999)+1000; //Esta funcion retorna un numero al azar entre 1000 y 9999


		return retorno;
}

int getRandID(Passenger list[], int len)
{

	int retorno=-1;

	if (list != NULL && len > 0){
		retorno=getRand();//esta funcion llama a la funcion getRand, en caso del raro caso que el numero dado coincida con una id ya en uso lo volvemos a llamar hasta que nos de un id aceptable

		while(findPassengerById(list, len, retorno)!=0){
			retorno=getRand();
		}


	}

	return retorno;


}

int addPassenger(Passenger list[], int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[], int statusFlight)
{
	int retorno = -1;
	int emptyIndex;
	if (list != NULL && len > 0) {
		emptyIndex = lookEmptyIndex(list, len);//Llamamos a la funcion lookEmptyIndex para poder encontrar un subindice vacio
		if (emptyIndex != -1) {

			list[emptyIndex].id=id;
			strcpy(list[emptyIndex].name, name);
			strcpy(list[emptyIndex].lastName, lastName);
			list[emptyIndex].price=price;
			list[emptyIndex].typePassenger=typePassenger;
			strcpy(list[emptyIndex].flycode, flycode);
			list[emptyIndex].statusFlight=statusFlight;
			list[emptyIndex].isEmpty = 0;
			retorno = 0;
		}

	}
	return retorno; //luego de recibir todos la informacion que necesitamos para llenar todos los espacios de nuestra estructura las cargamos despues de una validacion

}

int lookEmptyIndex (Passenger list[], int len) {
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 1) {
				retorno = i;
				break; //esta funcion busca todos los espacios del array hasta encontrar un subindice vacio, cuando lo encuentra lo guarda como retorno y usamos break para parar de iterar
			}
		}
	}
	return retorno;
}


int findPassengerById(Passenger list[], int len,int id)
{
	int retorno = -1;
	if (list != NULL && len > 0 && id > 0) {
		retorno=0;
		for (int i = 0; i < len; i++) {
			if (list[i].id == id && list[i].isEmpty == 0) {
				retorno = i;
				break;//esta funcion busca todos los espacios del array hasta encontrar un id igual al que le dimos, cuando lo encuentra lo guarda como retorno y usamos break para parar de iterar
			}
		}
	}
	return retorno;
}

int modifyPassenger(Passenger submitedPassenger, Passenger *modifiedPassenger){

	int retorno=-1;
	int opcion=0;


	if(modifiedPassenger!=NULL){

		while(opcion!=7 && opcion!=8){

			printf("Ingrese que opcion desea modificar:" //utilizamos un menu de opciones para pedirle al usuario que ingrese el tipo de campo que desea cambiar
					"\n1-Nombre"
					"\n2-Apellido"
					"\n3-Precio del vuelo"
					"\n4-Tipo de pasajero"
					"\n5-Codigo de vuelo"
					"\n6-Estado del vuelo"
					"\n7-Confirmar cambios"
					"\n8-Cancelar modificaciones");

			showPassenger(submitedPassenger,1); //mientras hacemos todos los cambios le mostramos al usuario los datos ingresados

			fflush(stdin);
			scanf("%d", &opcion);



			switch(opcion){

			case 1:


				utn_getAlphastr(submitedPassenger.name, "Ingrese un nuevo nombre para el pasajero", "Por favor ingrese un nombre valido");
				break;

			case 2:


				utn_getAlphastr(submitedPassenger.lastName, "Ingrese un nuevo apellido para pasajero", "Por favor ingrese un apellido valido");
				break;

			case 3:


				utn_getFloat(&submitedPassenger.price, "Ingrese el costo del vuelo", "Por favor ingrese un costo valido",300000,15000,100);
				break;

			case 4:


				utn_getInt(&submitedPassenger.typePassenger, "Ingrese el tipo de pasajero", "Por favor ingrese un tipo valido", 3, 1, 100);
				break;


			case 5:


				utn_getAlnumstr(submitedPassenger.flycode, "Ingrese el codigo de vuelo", "Por favor ingrese un codigo valido");
				break;

			case 6:

				utn_getInt(&submitedPassenger.statusFlight, "Ingrese el estado del vuelo", "Por favor ingrese un estado valido", 3, 1, 100);
				break;

			case 7:

				printf("\nFinalizando modificacion del empleado");
				*modifiedPassenger=submitedPassenger;
				break; //utillizamos la opcion 7 para confirmar los cambios y salir del programa

			case 8:

				printf("\nSe han cancelado los cambios");//utilizamos la opcion 8 para cancelar los cambios y salir del programa
				break;

			default:

				printf("\nPor favor ingrese una opcion valida");
				break;

			}

		}




	}


	return retorno;
}

int removePassenger(Passenger list[], int len, int id)
{
	int retorno = -1;
	int index;
	int opcion=0;
	if (list != NULL && len > 0 && id > 0) {
		index = findPassengerById(list, len, id);
		if (index != -1) {

			while(opcion!=1 && opcion!=2){
				printf("¿Seguro desea borrar el siguiente pasajero?\n");
				showPassenger(list[index],1);
				printf( "\n1-Si"
						"\n2-no");
				scanf("%d", &opcion);//antes de borrar permanentemente al pasajero se l mostramos al usuario y le pedimos una confirmacion
				switch(opcion){

				case 1:
					list[index].isEmpty = 1;
					retorno = 1;
					printf("El pasajero ha sido borrado"); //en caso de ser si, cambiamos el campo is empty a 1
					break;

				case 2:
					printf("El pasajero no ha sido borrado");//en caso de ser no, no hacemos nada y terminamos la funcion
					break;

				default:
					printf("Por favor ingrese una opcion valida");
					break;


				}
			}

		}

	}

	return retorno;

}

int sortPassengers(Passenger list[], int len, int order)//utilizamos la variable order para saber como queremos ordenar el array
{
	int retorno = -1;
	int i;
	Passenger aux;
	int isSorted;

	if(list != NULL && len > 0){


		if(order==1){
			do {
				isSorted = 1;
				len--;
				for (i = 0; i < len; i++) {
					if (list[i].typePassenger > list[i + 1].typePassenger){
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						isSorted = 0;
					} else if (list[i].typePassenger == list[i + 1].typePassenger && (strcmp(list[i].name, list[i + 1].name)>0)) {
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						isSorted = 0;
					}
				}
			} while (isSorted == 0); //en caso de que order sea 1 lo ordenamos por tipo de pasajero, y alfabeticamente. Usando un burbujeo eficiente.
		}else if(order==2){
			do {
				isSorted = 1;
				len--;
				for (i = 0; i < len; i++) {
					if (strcmp(list[i].flycode, list[i + 1].flycode)>0){
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						isSorted = 0;
					} else if (strcmp(list[i].flycode, list[i + 1].flycode)==0 && list[i].statusFlight > list[i + 1].statusFlight) {
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						isSorted = 0;
					}
				}
			} while (isSorted == 0);//en caso de que order sea 2 lo ordenamos por codigo de vuelo, y el estado que se ingreso. Usando un burbujeo eficiente.
		}
		retorno = 0;
	}

	return retorno;

}

void showPassenger(Passenger registeredPassenger, int showHeader) //utilizamos showPassenger para mostrar solo un empleado
{

	char statusFlight[51];
	char passengerType[51];


	if (registeredPassenger.isEmpty == 0){

		  // usamos showHeader para saber si debemos mostrar un encabezado, o si este se mostrara a traves de la funcion printPassenger
		  if(showHeader==1){
				printf("\n+-----+--------------------+--------------------+----------+----------+---------------+----------+\n");
				printf("|%-5s|%-20s|%-20s|%-10s|%-10s|%-15s|%-10s|\n","ID", "Nombre", "Apellido", "FlyCode", "Clase", "Precio", "Estado");
				printf("+-----+--------------------+--------------------+----------+----------+---------------+----------+\n");

		  }

		  if(registeredPassenger.typePassenger==1){
			  strcpy(passengerType,"Turista");
		  }else if(registeredPassenger.typePassenger==2){
			  strcpy(passengerType,"Ejecutiva");
		  }else{
			  strcpy(passengerType,"P.Clase");
		  }//usamos un if else if  para saber a que clase pertenece el pasajero ingresado y poder mostrarlo como una cadena de caracteres

		  if(registeredPassenger.statusFlight==1){
			  strcpy(statusFlight,"Activo");
		  }else if(registeredPassenger.statusFlight==2){
			  strcpy(statusFlight,"Retrasado");
		  }else{
			  strcpy(statusFlight,"Cancelado");
		  }//usamos un if else if  para saber el estado del vuelo ingresado y poder mostrarlo como una cadena de caracteres


		  //hacemos un printf de una sola linea
		  printf("|%-5d|%-20s|%-20s|%-10s|%-10s|%-15.2f|%-10s|\n", registeredPassenger.id, registeredPassenger.name, registeredPassenger.lastName,registeredPassenger.flycode,passengerType,registeredPassenger.price,statusFlight);
		  printf("+-----+--------------------+--------------------+----------+----------+---------------+----------+\n");

	}
}




int printPassenger(Passenger* list, int length)
{
	int retorno = -1;
	if (list != NULL && length > 0) {

		//La funcion muestra un encabezado por lo cual a show passenger le vamos a pasar un 0 para que no lo muestre en todas las iteraciones
		printf("\n+-----+--------------------+--------------------+----------+----------+---------------+----------+\n");
		printf("|%-5s|%-20s|%-20s|%-10s|%-10s|%-15s|%-10s|\n","ID", "Nombre", "Apellido", "FlyCode", "Clase", "Precio", "Estado");
		printf("+-----+--------------------+--------------------+----------+----------+---------------+----------+\n");

		for (int i = 0; i < length; i++) {

			if(list[i].isEmpty==0){

				showPassenger(list[i],0); //utilizamos un for para buscar todos los espacion del array en donde isEmpty sea 0, y por cada uno que encuentra le pasamos los datos a showPassenger para que lo muestre
			}
		}

		retorno = 0;
	}
	return retorno;
}

int isLoaded(Passenger list[], int len) //con esta funcion recorremos todas las posiciones del array hasta encontrar una en la que isEmpty sea igual a cero, es decir este cargada
{
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 0) {
				retorno = 1;//en caso de encontrar una posicion en la cual isEmpty sea 0 retornamos 1
				return retorno;
			}
		}
		retorno=0;//en caso de no encontrar ninguna posicion cargada retornamos 0
	}

	return retorno;
}

int averageArray(Passenger list[], int len, float * total, float * average)
{

	int retorno = -1;
	int counter=0; //incializamos un contador
	float sum=0; //inicializamos un acumulador
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++)
		{
			if (list[i].isEmpty == 0) //recorremos todaslas posiciones de nuestro array que esten cargadas y le sumamos al contador y al acumulador
			{
				counter=counter+1;
				sum=list[i].price+sum;
			}
		}
		*total=sum;
		*average=sum/counter;//al finalizar le pasamos por referencia la suma total y su promedio
		retorno=0;
	}
	return retorno;

}

int showPassengerPrice(Passenger list[], int len)
{
	int retorno=-1;
	float total;
	float average;
	int counter=0;

	if (list != NULL && len > 0) {
		averageArray(list,len,&total,&average);//llamamos a la funcion averageArray para obtener un total y un promedio por referencia
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 0 && list[i].price>average){
				counter=counter+1;//recorremos todas las posiciones del array y le sumamos uno a nuestro contador cada vez que el coste sea mayor al promedio
			}
		}
		printf("\n+--------------------+--------------------+--------------------+\n");
		printf("|%-20s|%-20s|%-20s|\n","Total", "Promedio", "Encima del Promedio");
		printf("+--------------------+--------------------+--------------------+\n");
		printf("|%-20.2f|%-20.2f|%-20d|\n",total, average, counter);
		printf("+--------------------+--------------------+--------------------+\n");
		retorno=0;//utilizamos una tabla para mostrarle al usuario los valores y devolvemos 0
	}

	return retorno;
}
