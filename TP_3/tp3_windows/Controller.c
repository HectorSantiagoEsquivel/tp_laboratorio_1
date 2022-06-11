#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn_get.h"
#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	FILE* pFile;
	if(path!=NULL&&pArrayListPassenger!=NULL)
	{
		if(ll_isEmpty(pArrayListPassenger)!=1){
			controller_changePassengerID(path,pArrayListPassenger,0);
		}

		pFile = fopen(path,"r");
		if(pFile!=NULL)
		{
			parser_PassengerFromText(pFile ,pArrayListPassenger);

			retorno=1;
			fclose(pFile);
		}else
		{
			printf("Error al abrir el archivo");
		}
	}

    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	FILE* pFile;
	if(path!=NULL&&pArrayListPassenger!=NULL)
	{
		if(ll_isEmpty(pArrayListPassenger)!=1){
			controller_changePassengerID(path,pArrayListPassenger,1);
		}
		pFile = fopen(path,"rb");
		if(pFile!=NULL)
		{
			parser_PassengerFromBinary(pFile ,pArrayListPassenger);
			printf("Se cargo todo bien!");
			retorno=1;
			fclose(pFile);
		}else
		{
			printf("Error al abrir el archivo");
		}
	}

    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{

	int id;
	char nombreStr[51];
	char apellidoStr[51];
	float precio;
	int tipoPasajero;
	char codigoVueloStr[51];
	Passenger* pPassenger;


	pPassenger=Passenger_new();


	id=Passenger_getNewID(pArrayListPassenger);

	if((utn_getAlphastr(nombreStr, "Ingrese el nombre del pasajero", "\nNombre invalido\n")==-1) ||
	(utn_getAlphastr(apellidoStr, "Ingrese el apellido del pasajero", "\nApellido invalido\n")==-1) ||
	(utn_getFloat(&precio, "Ingrese el costo del vuelo", "\nCosto invalido\n",500000,15000,100)==-1) ||
	(utn_getInt(&tipoPasajero, "Ingrese clase del pasajero\n1-Economy\n2-Executive\n3-First", "\nPor favor ingrese el numero de clase\n", 3, 1, 100)==-1) ||
	(utn_getAlnumstr(codigoVueloStr, "Ingrese el codigo de vuelo", "\nCodigo invalido\n")==-1)||
	id==-1 ||
	pPassenger==NULL||
	pArrayListPassenger==NULL)
	{
		printf("Error en el ingreso de datos");
	}else{

		Passenger_setId(pPassenger,id);
		Passenger_setNombre(pPassenger,nombreStr);
		Passenger_setApellido(pPassenger,apellidoStr);
		Passenger_setPrecio(pPassenger,precio);
		Passenger_setTipoPasajero(pPassenger, tipoPasajero);
		Passenger_setCodigoVuelo(pPassenger,codigoVueloStr);
	    ll_add(pArrayListPassenger, pPassenger);
	    printf("Se cargaron bien todos los datos\n");


	}

    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int submitedID;
	int foundIndex;


	if(Passenger_showPassengerList(pArrayListPassenger)==-1 ||
	utn_getInt(&submitedID, "Ingrese el ID del pasajero que desea modificar", "Por favor ingrese un ID valido", ll_len(pArrayListPassenger), 0, 100)==-1)
	{
		printf("Error al buscar el indice\n");
	}else{
		foundIndex=Passenger_findIndexbyID(pArrayListPassenger, submitedID);
		printf("El index encontrado fue: %d\n", foundIndex);
		Passenger_modifyPassenger(ll_get(pArrayListPassenger, foundIndex));

	}
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int submitedID;
	int foundIndex;


	if(Passenger_showPassengerList(pArrayListPassenger)==-1 ||
	utn_getInt(&submitedID, "Ingrese el ID del pasajero que desea modificar", "Por favor ingrese un ID valido", ll_len(pArrayListPassenger), 0, 100)==-1)
	{
		printf("Error al buscar el indice\n");
	}else{
		foundIndex=Passenger_findIndexbyID(pArrayListPassenger, submitedID);
		printf("El index encontrado fue: %d\n", foundIndex);
		Passenger_removePassenger(pArrayListPassenger, foundIndex);

	}
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	if(pArrayListPassenger!=NULL)
	{
		Passenger_showPassengerList(pArrayListPassenger);
	}
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int option;
	int order=1;

	if(pArrayListPassenger!=NULL)
	{
		printf("\n1-Ordenar pasajeros por apellido y nombre\n"
				"2-Ordenar pasajeros por clase y precio de vuelo \n"
				"3-Ordenar pasajeros por ID\n"
				"4-Cancelar\n"); //Informo al usuario las opciones disponibles

		printf("Ingrese el numero de opcion");
		scanf("%d", &option);
		switch(option){

		case 1:

			printf("Ordenando pasajeros...\n");
			ll_sort(pArrayListPassenger,Passenger_sortbyName,order);
			ll_sort(pArrayListPassenger,Passenger_sortbySurname,order);
			printf("¡Se ordeno de forma exitosa!\n");


			break; //utilizando sortPassengers ordenamos a la lista de pasajeros de la forma deseada, y utilizamos printPassenger para mostrar la lista ordenada

		case 2:

			printf("Ordenando pasajeros...\n");
			ll_sort(pArrayListPassenger,Passenger_sortbyPrice,order);
			ll_sort(pArrayListPassenger,Passenger_sortbyType,order);
			printf("¡Se ordeno de forma exitosa!\n");

			break;

		case 3:
			printf("Ordenando pasajeros...\n");
			ll_sort(pArrayListPassenger,Passenger_sortbyID,order);
			printf("¡Se ordeno de forma exitosa!\n");

			break;

		case 4:
			printf("Cancelando funcion");
			break;


		}
	}


    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	FILE* pFile;
	if(path!=NULL&&pArrayListPassenger!=NULL)
	{
		pFile = fopen(path,"w");
		if(pFile!=NULL)
		{
			parser_TextFromPassenger(pFile ,pArrayListPassenger);
			printf("Se cargo todo bien!");
			retorno=1;
			fclose(pFile);
		}else
		{
			printf("Error al abrir el archivo");
		}
	}

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	FILE* pFile;
	if(path!=NULL&&pArrayListPassenger!=NULL)
	{
		pFile = fopen(path,"wb");
		if(pFile!=NULL)
		{
			parser_BinaryFromPassenger(pFile ,pArrayListPassenger);
			printf("Se cargo todo bien!");
			retorno=1;
			fclose(pFile);
		}else
		{
			printf("Error al abrir el archivo");
		}
	}

    return retorno;
}

int controller_changePassengerID(char* path,  LinkedList* pArrayListPassenger, int readType)
{
	FILE* pFile;
	int maxID;

	if(path!=NULL&&pArrayListPassenger!=NULL)
	{
		if(readType==0)
		{
			pFile = fopen(path,"r");
			maxID=parser_maxIDFromText(pFile);
			Passenger_changeIDtoMax(pArrayListPassenger,maxID);
			fclose(pFile);
		}else if(readType==1)
		{
			pFile = fopen(path,"rb");
			maxID=parser_maxIDFromBinary(pFile);
			Passenger_changeIDtoMax(pArrayListPassenger,maxID);
			fclose(pFile);
		}
	}

	return 1;
}
