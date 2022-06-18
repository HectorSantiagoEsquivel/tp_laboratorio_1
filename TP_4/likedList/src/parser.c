#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */



int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{


	char idStr[51];
	char nombreStr[51];
	char apellidoStr[51];
	char precioStr[51];
	char tipoPasajeroStr[51];
	char codigoVueloStr[51];
	char estadoVueloStr[51];

	Passenger* pPassenger;
	if(pFile!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,], %[^,],%[^,],%[^\n]\n",idStr,nombreStr,apellidoStr,precioStr,codigoVueloStr,tipoPasajeroStr,estadoVueloStr);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,], %[^,],%[^,],%[^\n]\n",idStr,nombreStr,apellidoStr,precioStr,codigoVueloStr,tipoPasajeroStr,estadoVueloStr)==7)
			{
				//printf("%s-%s-%s-%s-%s-%s \n",idStr,nombreStr,apellidoStr,precioStr,tipoPasajeroStr,codigoVueloStr);

				pPassenger=Passenger_new();

				Passenger_setId(pPassenger,atoi(idStr));
				Passenger_setNombre(pPassenger,nombreStr);
				Passenger_setApellido(pPassenger,apellidoStr);
				Passenger_setPrecio(pPassenger,atof(precioStr));
				Passenger_setTipoPasajero(pPassenger, charClassToInt(tipoPasajeroStr));
				Passenger_setCodigoVuelo(pPassenger,codigoVueloStr);

			    if (ll_add(pArrayListPassenger, pPassenger)==0){
			    	printf("Se cargaron bien todos los datos\n");
			    }

			}else
			{
				break;
			}

		}while(feof(pFile)==0);


	}

    return 1;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	Passenger* pPassenger;
	int end=1;

	if(pFile!=NULL&&pArrayListPassenger!=NULL)
	{
		do
		{
			pPassenger=Passenger_new();

			end=fread(pPassenger,sizeof(Passenger),1,pFile);

		    if (ll_add(pArrayListPassenger, pPassenger)==0){
		    	printf("%d %s %s %s %d\n", pPassenger->id,pPassenger->nombre,pPassenger->apellido,pPassenger->codigoVuelo, pPassenger->tipoPasajero);
		    }
		}while(end!=0);
	}

	return retorno;
}

/**
 * @brief parsea los datos del archivo de texto desde una linked list con passengers
 * @param pFile
 * @param pArrayListPassenger
 * @return
 */

int parser_TextFromPassenger(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int id;
	char nombreStr[51];
	char apellidoStr[51];
	float precio;
	int tipoPasajero;
	char tipoPasajeroStr[51];
	char codigoVueloStr[51];
	char estadoVueloStr[51];

	Passenger* pPassenger;
	if(pFile!=NULL)
	{
		fprintf(pFile, "%s,%s,%s,%s, %s,%s,%s\n","ID","Name","Surname","Price","FlyCode","Class","StatusFlight");

		for(int i=0;i<ll_len(pArrayListPassenger);i++)
		{
			pPassenger=ll_get(pArrayListPassenger,i);

			Passenger_getId(pPassenger,&id);
			Passenger_getNombre(pPassenger,nombreStr);
			Passenger_getApellido(pPassenger,apellidoStr);
			Passenger_getPrecio(pPassenger,&precio);
			Passenger_getTipoPasajero(pPassenger, &tipoPasajero);
			Passenger_getCodigoVuelo(pPassenger,codigoVueloStr);
			strcpy(estadoVueloStr,"N/A");

			intClassToChar(tipoPasajero, tipoPasajeroStr);

			fprintf(pFile, "%d,%s,%s,%f,%s,%s,%s\n",id,nombreStr,apellidoStr, precio,codigoVueloStr,tipoPasajeroStr,estadoVueloStr);
		}


	}

    return 1;
}

/**
 * @brief parsea los datos del archivo binario desde una linked list con passengers
 * @param pFile
 * @param pArrayListPassenger
 * @return
 */


int parser_BinaryFromPassenger(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	Passenger* pPassenger;

	if(pFile!=NULL&&pArrayListPassenger!=NULL)
	{
		for(int i=0;i<ll_len(pArrayListPassenger);i++)
		{
			pPassenger=ll_get(pArrayListPassenger,i);
			fwrite(pPassenger,sizeof(Passenger),1,pFile);
		}
	}

	return retorno;
}

/**
 * @brief obtiene un id maximo desde un archivo de texto
 * @param pFile
 * @return
 */

int parser_maxIDFromText(FILE* pFile)
{

	char idStr[51];
	char nombreStr[51];
	char apellidoStr[51];
	char precioStr[51];
	char tipoPasajeroStr[51];
	char codigoVueloStr[51];
	char estadoVueloStr[51];
	int auxID;
	int maxID=-1;

	if(pFile!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,], %[^,],%[^,],%[^\n]\n",idStr,nombreStr,apellidoStr,precioStr,codigoVueloStr,tipoPasajeroStr,estadoVueloStr);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,], %[^,],%[^,],%[^\n]\n",idStr,nombreStr,apellidoStr,precioStr,codigoVueloStr,tipoPasajeroStr,estadoVueloStr)==7)
			{
				auxID=atoi(idStr);
				if(auxID>maxID)
				{
					maxID=auxID;
				}
			}else
			{
				break;
			}

		}while(feof(pFile)==0);


	}

    return maxID;
}

/**
 * @brief obtiene un id maximo desde un archivo binario
 * @param pFile
 * @return
 */

int parser_maxIDFromBinary(FILE* pFile)
{
	Passenger auxPassenger;
	int maxID=0;
	int end=1;

	if(pFile!=NULL)
	{
		do
		{

			end=fread(&auxPassenger,sizeof(Passenger),1,pFile);

			if(auxPassenger.id>maxID)
			{
				maxID=auxPassenger.id;
			}

		}while(end!=0);
	}

	return maxID;
}


