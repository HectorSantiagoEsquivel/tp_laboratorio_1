/*
 * calculos.h
 *
 *  Created on: 12 Apr 2022
 *      Author: Santiago
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/**
 * @brief Funcion para calcular descuento por porcentaje
 * @param numero1
 * @param numero2
 * @param descuento1
 * @param descuento2
 * @return
 */

int descuento(float numero1, float numero2, float* descuento1, float* descuento2);

/**
 * @brief Funcion para calcular el interes por porcentaje
 * @param numero1
 * @param numero2
 * @param interes1
 * @param interes2
 * @return
 */

int interes(float numero1, float numero2, float *interes1, float *interes2);

/**
 * @brief Funcion para calcular el pasaje de pesos a bitcoin
 * @param numero1
 * @param numero2
 * @param bitcoin1
 * @param bitcoin2
 * @return
 */

int bitcoin(float numero1, float numero2, float *bitcoin1, float *bitcoin2);

/**
 * @brief Funcion para calcular la diferencia entre dos valores.
 * @param numero1
 * @param numero2
 * @param diferenciaVar
 * @return
 */

int diferencia(float numero1, float numero2, float* diferenciaVar);

#endif /* CALCULOS_H_*/
