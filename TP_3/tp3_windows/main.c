#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    setbuf(stdout,NULL);
    int option = 0;
    int flagOne=0;
    int flagTwo=0;
    int flagThree=0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    while(option != 10){
		printf("\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
				"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
				"3. Alta de pasajero\n"
				"4. Modificar datos de pasajero\n"
				"5. Baja de pasajero\n"
				"6. Listar pasajeros\n"
				"7. Ordenar pasajeros\n"
				"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
				"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
				"10. Salir\n");
    	scanf("%d",&option);
        switch(option)
        {
            case 1:
            	if(flagThree==0){
            		controller_loadFromText("data.csv",listaPasajeros);
            		flagOne=1;
            		flagThree=1;
            	}else{
            		printf("Ya se cargaron los pasajeros desde el archivo");
            	}

                break;
            case 2:
            	if(flagThree==0){
                	controller_loadFromBinary("data.bin",listaPasajeros);
                	flagOne=1;
                	flagThree=1;
            	}else{
            		printf("Ya se cargaron los pasajeros desde el archivo");
            	}

            	break;
            case 3:
            	controller_addPassenger(listaPasajeros);
            	flagOne=1;
            	break;
            case 4:
            	if (flagOne==1)
            	{
                	controller_editPassenger(listaPasajeros);
            	}else
            	{
            		printf("Ingrese un pasajero antes de hacer la modificacion");
            	}

            	break;
            case 5:
            	if (flagOne==1)
            	{
                	controller_removePassenger(listaPasajeros);
                	if(ll_isEmpty(listaPasajeros)==1)
                	{
                		flagOne=0;
                	}
            	}else
            	{
            		printf("Ingrese un pasajero antes de hacer la baja");
            	}

            	break;
            case 6:
            	if (flagOne==1){
            	controller_ListPassenger(listaPasajeros);
            	}else
            	{
            		printf("No hay pasajeros cargados");
            	}

            	break;
            case 7:

            	if (flagOne==1){
                	controller_sortPassenger(listaPasajeros);
            	}else
            	{
            		printf("Ingrese un pasajero antes de ordenar");
            	}


            	break;
            case 8:
            	if (flagOne==1){
            		controller_saveAsText("data.csv",listaPasajeros);
            		flagTwo=1;
            	}else
            	{
            		printf("Ingrese un pasajero antes de cargar el texto");

            	}
            	break;
            case 9:
            	if (flagOne==1)
            	{
            		controller_saveAsBinary("data.bin",listaPasajeros);
            		flagTwo=1;
            	}else
            	{
            		printf("Ingrese un pasajero antes de cargar el binario");
            	}
            	break;
            case 10:
            	if(flagTwo==1){
            		printf("Finalizando Programa");
            		ll_deleteLinkedList(listaPasajeros);
            	}else
            	{
            		option=0;
            		printf("Antes de finalizar el programa guarde un archivo por favor");
            	}
            	break;
        }
    }
    return 0;
}

