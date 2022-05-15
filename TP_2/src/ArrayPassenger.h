/*
 * ArrayPassenger.h
 *
 *  Created on: 23 Apr 2022
 *      Author: Santiago
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}typedef Passenger;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int initPassengers(Passenger list[], int len);

/**
 * @brief add in a existing list of passengers the values received as parameters in the first empty position
 * @param list
 * @param len
 * @param id
 * @param name
 * @param lastName
 * @param price
 * @param typePassenger
 * @param flycode
 * @return
 */

int addPassenger(Passenger list[], int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);

/**
 * @brief find a Passenger by Id en returns the index position in array.
 * @param list
 * @param len
 * @param id
 * @return
 */

int findPassengerById(Passenger list[], int len,int id);

/**
 * @brief Remove a Passenger by Id (put isEmpty Flag in 1)
 * @param list
 * @param len
 * @param id
 * @return
 */

int removePassenger(Passenger list[], int len, int id);



int lookEmptyIndex (Passenger list[], int len);

/**
 * @brief Sort the elements in the array of passengers, the argument order indicates according to which fields it orders
 * @param list
 * @param len
 * @return
 */

int sortPassengers(Passenger list[], int len, int order);

/**
 * @brief print the content of a single passenger
 * @param registeredPassenger
 * @param showHeader
 */

void showPassenger(Passenger registeredPassenger, int showHeader);

/**
 * @brief print the content of passengers array
 * @param list
 * @param length
 * @return
 */

int printPassenger(Passenger* list, int length);

/**
 * @brief opens a menu in which all the modification options are contained
 * @param submitedPassenger
 * @param modifiedPassenger
 * @return
 */

int modifyPassenger(Passenger submitedPassenger, Passenger *modifiedPassenger);

/**
 * @brief returns a random value between 1000 and 9999
 * @return
 */


int getRand();

/**
 * @brief receives an array and returns a random number between 1000 and 9999, in case of the id already being taken it runs again
 * @param list
 * @param len
 * @return
 */

int getRandID(Passenger list[], int len);

/**
 * @brief it gives by reference the total sum and average from the price field
 * @param list
 * @param len
 * @param total
 * @param average
 * @return
 */

int averageArray(Passenger list[], int len, float * total, float * average);

/**
 * @brief it shows prices, total sum and average, as well as showing how many passengers exceed the average price
 * @param list
 * @param len
 * @return
 */

int showPassengerPrice(Passenger list[], int len);

/**
 * @brief it checks if the given Passenger array is loaded, returns 1 if loaded 0 if not
 * @param list
 * @param len
 * @return
 */

int isLoaded(Passenger list[], int len);

#endif /* ARRAYPASSENGER_H_ */
