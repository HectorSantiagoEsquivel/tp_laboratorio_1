/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn_get.h"
#include "Passenger.h"
#include "LinkedList.h"

/**
 * @brief this function creates a new passenger through dynamic memory
 * @return
 */

Passenger* Passenger_new(){

	Passenger* pPassenger;

	pPassenger=(Passenger*)malloc(sizeof(Passenger));
	return pPassenger;

}

/**
 * @brief sets the id of the passenger on the given structure
 * @param this
 * @param id
 * @return
 */

int Passenger_setId(Passenger* this,int id){
	int retorno=-1;

	if(this!=NULL&&id>=0)
	{

		this->id=id;
		retorno=0;

	}

	return retorno;

}

/**
 * @brief gets the id of the passenger from the given structure
 * @param this
 * @param id
 * @return
 */

int Passenger_getId(Passenger* this,int* id){

	int retorno=-1;

	if(this!=NULL&&id!=NULL)
	{

		*id=this->id;
		retorno=0;

	}

	return retorno;

}

/**
 * @brief sets the name of the passenger on the given structure
 * @param this
 * @param nombre
 * @return
 */

int Passenger_setNombre(Passenger* this,char* nombre){

	int retorno=-1;

	if(this!=NULL&&nombre!=NULL)
	{
		if(esAlfastr(nombre)==1)
		{
			strcpy(this->nombre,nombre);
			retorno=0;
		}
	}

	return retorno;

}

/**
 * @brief gets the name of the passenger from the given structure
 * @param this
 * @param nombre
 * @return
 */

int Passenger_getNombre(Passenger* this,char* nombre){

	int retorno=-1;

	if(this!=NULL&&nombre!=NULL)
	{

		strcpy(nombre,this->nombre);
		retorno=0;

	}

	return retorno;

}

/**
 * @brief sets the surname of the passenger on the given structure
 * @param this
 * @param apellido
 * @return
 */

int Passenger_setApellido(Passenger* this,char* apellido){

	int retorno=-1;

	if(this!=NULL&&apellido!=NULL)
	{
		if(esAlfastr(apellido)==1)
		{
			strcpy(this->apellido,apellido);
			retorno=0;
		}
	}

	return retorno;

}

/**
 * @brief gets the surname of the passenger from the given structure
 * @param this
 * @param apellido
 * @return
 */

int Passenger_getApellido(Passenger* this,char* apellido){

	int retorno=-1;

	if(this!=NULL&&apellido!=NULL)
	{

		strcpy(apellido,this->apellido);
		retorno=0;

	}

	return retorno;

}

/**
 * @brief sets the flycode of the passenger on the given structure
 * @param this
 * @param codigoVuelo
 * @return
 */

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){

	int retorno=-1;

	if(this!=NULL&&codigoVuelo!=NULL)
	{
		if(esAlnumstr(codigoVuelo)==1)
		{
			strcpy(this->codigoVuelo,codigoVuelo);
			retorno=0;
		}
	}

	return retorno;

}

/**
 * @brief gets the flycode of the passenger from the given structure
 * @param this
 * @param codigoVuelo
 * @return
 */

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){

	int retorno=-1;

	if(this!=NULL&&codigoVuelo!=NULL)
	{

		strcpy(codigoVuelo,this->codigoVuelo);
		retorno=0;

	}

	return retorno;

}

/**
 * @brief sets the type of the passenger on the given structure
 * @param this
 * @param tipoPasajero
 * @return
 */

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
	int retorno=-1;

	if(this!=NULL&&(tipoPasajero>0 || tipoPasajero<=3))
	{

		this->tipoPasajero=tipoPasajero;
		retorno=0;

	}

	return retorno;

}

/**
 * @brief gets the type of the passenger from the given structure
 * @param this
 * @param tipoPasajero
 * @return
 */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){

	int retorno=-1;

	if(this!=NULL&&tipoPasajero!=NULL)
	{

		*tipoPasajero=this->tipoPasajero;
		retorno=0;

	}

	return retorno;

}

/**
 * @brief sets the price of the flight on the given structure
 * @param this
 * @param precio
 * @return
 */

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno=-1;

	if(this!=NULL&&precio>=0)
	{

		this->precio=precio;
		retorno=0;

	}

	return retorno;

}

/**
 * @brief gets the price of the flight from the given structure
 * @param this
 * @param precio
 * @return
 */
int Passenger_getPrecio(Passenger* this,float* precio)
{

	int retorno=-1;

	if(this!=NULL&&precio!=NULL)
	{

		*precio=this->precio;
		retorno=0;

	}

	return retorno;

}

/**
 * @brief shows the passenger list
 * @param this
 * @return
 */

int Passenger_showPassengerList(LinkedList* this)
{
	int retorno = -1;

	Passenger* pPassenger;
	if (this != NULL)
	{

		//La funcion muestra un encabezado por lo cual a show passenger le vamos a pasar un 0 para que no lo muestre en todas las iteraciones
		printf("+-----+--------------------+--------------------+----------+---------------+---------------+\n");
		printf("|%-5s|%-20s|%-20s|%-10s|%-15s|%-15s|\n","ID", "Nombre", "Apellido", "FlyCode", "Clase", "Precio");
		printf("+-----+--------------------+--------------------+----------+---------------+---------------+\n");

		for (int i = 0; i < ll_len(this); i++) {

			pPassenger=ll_get(this,i);

			if(pPassenger!=NULL){

				Passenger_showPassenger(pPassenger,0);
			}
		}

		retorno = 0;
	}
	return retorno;


}

/**
 * @brief shows a single passenger
 * @param this
 * @param showHeader
 * @return
 */

int Passenger_showPassenger(Passenger* this, int showHeader)
{

	int retorno=-1;
	char tipoPasajeroStr[51];


	if (this != NULL){

		  // usamos showHeader para saber si debemos mostrar un encabezado, o si este se mostrara a traves de la funcion printPassenger
		  if(showHeader==1){
				printf("+-----+--------------------+--------------------+----------+---------------+---------------+\n");
				printf("|%-5s|%-20s|%-20s|%-10s|%-15s|%-15s|\n","ID", "Nombre", "Apellido", "FlyCode", "Clase", "Precio");
				printf("+-----+--------------------+--------------------+----------+---------------+---------------+\n");

		  }
		  retorno=0;
		  intClassToChar(this->tipoPasajero,tipoPasajeroStr);


		  //hacemos un printf de una sola linea
		  printf("|%-5d|%-20s|%-20s|%-10s|%-15s|%-15.2f|\n", this->id, this->nombre, this->apellido,this->codigoVuelo,tipoPasajeroStr,this->precio);
		  printf("+-----+--------------------+--------------------+----------+---------------+---------------+\n");

	}
	return retorno;
}

/**
 * @brief allows the modification of the fields of the given passenger structure
 * @param pPassenger
 * @return
 */

int Passenger_modifyPassenger(Passenger* pPassenger){

	int retorno=-1;
	int opcion=0;
	char nombreStr[51];
	char apellidoStr[51];
	float precio;
	int tipoPasajero;
	char codigoVueloStr[51];
	Passenger* pPassengerAux;


	pPassengerAux=Passenger_new();

	*pPassengerAux=*pPassenger;

	if(pPassenger!=NULL&&pPassengerAux!=NULL){

		while(opcion!=6 && opcion!=7){

			printf("Ingrese que opcion desea modificar:" //utilizamos un menu de opciones para pedirle al usuario que ingrese el tipo de campo que desea cambiar
					"\n1-Nombre"
					"\n2-Apellido"
					"\n3-Precio del vuelo"
					"\n4-Tipo de pasajero"
					"\n5-Codigo de vuelo"
					"\n6-Confirmar cambios"
					"\n7-Cancelar modificaciones\n");

			Passenger_showPassenger(pPassengerAux,1);

			fflush(stdin);
			scanf("%d", &opcion);

			switch(opcion){

			case 1:


				utn_getAlphastr(nombreStr, "Ingrese un nuevo nombre para el pasajero", "Por favor ingrese un nombre valido");
				Passenger_setNombre(pPassengerAux,nombreStr);
				break;

			case 2:


				utn_getAlphastr(apellidoStr, "Ingrese un nuevo apellido para pasajero", "Por favor ingrese un apellido valido");
				Passenger_setApellido(pPassengerAux,apellidoStr);
				break;


			case 3:


				utn_getFloat(&precio, "Ingrese el costo del vuelo", "Por favor ingrese un costo valido",300000,15000,100);
				Passenger_setPrecio(pPassengerAux,precio);
				break;


			case 4:


				utn_getInt(&tipoPasajero, "Ingrese el tipo de pasajero", "Por favor ingrese un tipo valido", 3, 1, 100);
				Passenger_setTipoPasajero(pPassengerAux, tipoPasajero);
				break;


			case 5:


				utn_getAlnumstr(codigoVueloStr, "Ingrese el codigo de vuelo", "Por favor ingrese un codigo valido");
				Passenger_setCodigoVuelo(pPassengerAux,codigoVueloStr);
				break;

			case 6:

				printf("\nFinalizando modificacion del empleado");
				*pPassenger=*pPassengerAux;
				free(pPassengerAux);
				break; //utillizamos la opcion 6 para confirmar los cambios y salir del programa

			case 7:

				printf("\nSe han cancelado los cambios");//utilizamos la opcion 7 para cancelar los cambios y salir del programa
				free(pPassengerAux);
				break;

			default:

				printf("\nPor favor ingrese una opcion valida");
				break;

			}

		}
	}
	return retorno;
}

/**
 * @brief removes the given passenger
 * @param this
 * @param index
 * @return
 */

int Passenger_removePassenger(LinkedList* this, int index)
{
	int retorno = -1;
	int opcion=0;
	Passenger* pPassenger;




	if (this != NULL)
	{

		pPassenger=ll_get(this,index);

		while(opcion!=1 && opcion!=2)
		{
			printf("¿Seguro desea borrar el siguiente pasajero?\n");
			Passenger_showPassenger(pPassenger,1);
			printf( "\n1-Si"
					"\n2-no");
			scanf("%d", &opcion);//antes de borrar permanentemente al pasajero se l mostramos al usuario y le pedimos una confirmacion
			switch(opcion){

			case 1:
				ll_remove(this,index);
				retorno = 1;
				printf("El pasajero ha sido borrado");
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

	return retorno;

}

/**
 * @brief compares two passengers through id
 * @param pElementOne
 * @param pElementTwo
 * @return
 */

int Passenger_sortbyID(void* pElementOne, void* pElementTwo)//utilizamos la variable order para saber como queremos ordenar el array
{
	int retorno = 0;
	Passenger* pPassengerAuxOne=(Passenger*)pElementOne;
	Passenger* pPassengerAuxTwo=(Passenger*)pElementTwo;
	int idOne;
	int idTwo;

	if (pPassengerAuxOne != NULL &&pPassengerAuxTwo != NULL)
	{

		if(Passenger_getId(pPassengerAuxOne, &idOne)==0 &&Passenger_getId(pPassengerAuxTwo, &idTwo)==0)
		{

			if(idOne>idTwo)
			{
				retorno=1;
			}else if(idOne<idTwo)
			{
				retorno=-1;
			}
		}
	}

	return retorno;

}

/**
 * @brief compares two passengers through name
 * @param pElementOne
 * @param pElementTwo
 * @return
 */

int Passenger_sortbyName(void* pElementOne, void* pElementTwo)//utilizamos la variable order para saber como queremos ordenar el array
{
	int retorno = 0;
	Passenger* pPassengerAuxOne=(Passenger*)pElementOne;
	Passenger* pPassengerAuxTwo=(Passenger*)pElementTwo;
	char nombreOneStr[51];
	char nombreTwoStr[51];

	if (pPassengerAuxOne != NULL &&pPassengerAuxTwo != NULL)
	{

		if(Passenger_getNombre(pPassengerAuxOne, nombreOneStr)==0 &&Passenger_getNombre(pPassengerAuxTwo, nombreTwoStr)==0)
		{

			if(strcmp(nombreOneStr,nombreTwoStr)>0)
			{
				retorno=1;
			}else if(strcmp(nombreOneStr,nombreTwoStr)<0)
			{
				retorno=-1;
			}
		}
	}

	return retorno;

}

/**
 * @brief compares two passengers through surname
 * @param pElementOne
 * @param pElementTwo
 * @return
 */

int Passenger_sortbySurname(void* pElementOne, void* pElementTwo)//utilizamos la variable order para saber como queremos ordenar el array
{
	int retorno = 0;
	Passenger* pPassengerAuxOne=(Passenger*)pElementOne;
	Passenger* pPassengerAuxTwo=(Passenger*)pElementTwo;
	char apellidoOneStr[51];
	char apellidoTwoStr[51];

	if (pPassengerAuxOne != NULL &&pPassengerAuxTwo != NULL)
	{

		if(Passenger_getApellido(pPassengerAuxOne, apellidoOneStr)==0 &&Passenger_getApellido(pPassengerAuxTwo, apellidoTwoStr)==0)
		{

			if(strcmp(apellidoOneStr,apellidoTwoStr)>0)
			{
				retorno=1;
			}else if(strcmp(apellidoOneStr,apellidoTwoStr)<0)
			{
				retorno=-1;
			}
		}
	}

	return retorno;

}

/**
 * @brief compares two passengers through price
 * @param pElementOne
 * @param pElementTwo
 * @return
 */

int Passenger_sortbyPrice(void* pElementOne, void* pElementTwo)//utilizamos la variable order para saber como queremos ordenar el array
{
	int retorno = 0;
	Passenger* pPassengerAuxOne=(Passenger*)pElementOne;
	Passenger* pPassengerAuxTwo=(Passenger*)pElementTwo;
	float priceOne;
	float priceTwo;

	if (pPassengerAuxOne != NULL &&pPassengerAuxTwo != NULL)
	{

		if(Passenger_getPrecio(pPassengerAuxOne, &priceOne)==0 &&Passenger_getPrecio(pPassengerAuxTwo, &priceTwo)==0)
		{

			if(priceOne>priceTwo)
			{
				retorno=1;
			}else if(priceOne<priceTwo)
			{
				retorno=-1;
			}
		}
	}

	return retorno;

}

/**
 * @brief compares two passengers through type
 * @param pElementOne
 * @param pElementTwo
 * @return
 */

int Passenger_sortbyType(void* pElementOne, void* pElementTwo)//utilizamos la variable order para saber como queremos ordenar el array
{
	int retorno = 0;
	Passenger* pPassengerAuxOne=(Passenger*)pElementOne;
	Passenger* pPassengerAuxTwo=(Passenger*)pElementTwo;
	int typeOne;
	int typeTwo;

	if (pPassengerAuxOne != NULL &&pPassengerAuxTwo != NULL)
	{

		if(Passenger_getTipoPasajero(pPassengerAuxOne, &typeOne)==0 &&Passenger_getTipoPasajero(pPassengerAuxTwo, &typeTwo)==0)
		{

			if(typeOne>typeTwo)
			{
				retorno=1;
			}else if(typeOne<typeTwo)
			{
				retorno=-1;
			}
		}
	}

	return retorno;

}

/**
 * @brief returns the index of the passenger with the correct ID
 * @param this
 * @param submitedID
 * @return
 */

int Passenger_findIndexbyID(LinkedList* this, int submitedID)
{
	int foundID;
	int retorno=-1;
	int i;


	if(this!=NULL&&submitedID>=0)
	{
		for(i=0;i<ll_len(this);i++)
		{

			Passenger_getId(ll_get(this,i),&foundID);
			if(foundID==submitedID){
				retorno=i;
				break;
			}
		}
	}

	return retorno;

}

/**
 * @brief returns the correct class code given a char
 * @param class
 * @return
 */
int charClassToInt(char* class)
{
	int retorno=-1;

	if(class!=NULL)
	{
		  if(strcmp(class,"EconomyClass")==0){
			  retorno=1;
		  }else if(strcmp(class,"ExecutiveClass")==0){
			  retorno=2;
		  }else if(strcmp(class,"FirstClass")==0){
			  retorno=3;
		  }
	}

	return retorno;
}
/**
 * @brief gives the class description from the class code
 * @param classCode
 * @param class
 * @return
 */
int intClassToChar(int classCode,char* class)
{
	int retorno=-1;

	if(class!=NULL)
	{
		  if(classCode==1){
			  strcpy(class,"EconomyClass");
		  }else if(classCode==2){
			  strcpy(class,"ExecutiveClass");
		  }else{
			  strcpy(class,"FirstClass");
		  }
	}
	return retorno;
}

/**
 * @brief generates a new id for the passenger
 * @param this
 * @return
 */

int Passenger_getNewID(LinkedList* this)
{
	Passenger* pPassenger;
	int newID=-1;
	int auxID=0;
	int maxID=0;
	int i;

	if(this!=NULL){

		if(ll_isEmpty(this)==0)
		{
			for(i=0;i<ll_len(this); i++){

				pPassenger=ll_get(this,i);
				Passenger_getId(pPassenger,&auxID);

				if(auxID>maxID)
				{
					maxID=auxID;
				}

			}
			newID=maxID+1;
		}else
		{
			newID=1;
		}

	}
	return newID;

}

/**
 * @brief changes the id of previously submitted passengers to accommodate passengers submitted through text;
 * @param this
 * @param maxID
 * @return
 */

int Passenger_changeIDtoMax(LinkedList* this, int maxID)
{
	Passenger* pPassenger;
	int previousID;
	int newID;
	int i;

	if(this!=NULL){


		for(i=0;i<ll_len(this); i++){

			pPassenger=ll_get(this,i);
			Passenger_getId(pPassenger,&previousID);
			newID=previousID+maxID;
			Passenger_setId(pPassenger,newID);

		}

	}
	return newID;

}

