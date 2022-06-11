/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int isEmpty;

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int charClassToInt(char* class);
int intClassToChar(int classCode,char* class);

int Passenger_showPassenger(Passenger* this, int showHeader);
int Passenger_showPassengerList(LinkedList* this);

int Passenger_modifyPassenger(Passenger* pPassenger);
int Passenger_removePassenger(LinkedList* this, int index);

int Passenger_sortbyID(void* pElementOne, void* pElementTwo);
int Passenger_sortbyType(void* pElementOne, void* pElementTwo);
int Passenger_sortbyPrice(void* pElementOne, void* pElementTwo);
int Passenger_sortbySurname(void* pElementOne, void* pElementTwo);
int Passenger_sortbyName(void* pElementOne, void* pElementTwo);

int Passenger_findIndexbyID(LinkedList* this, int submitedID);
int Passenger_getNewID(LinkedList* this);

int Passenger_changeIDtoMax(LinkedList* this, int maxID);


#endif /* PASSENGER_H_ */
