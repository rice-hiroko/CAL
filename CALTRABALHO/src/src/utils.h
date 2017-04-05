/*
 * utils.h
 *
 *  Created on: 31/03/2017
 *      Author: João Tomé Saraiva
 */

#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_

#include <cmath>

/**
 * Calculates the distance between two deltas X and Y
 * @param x deltaX
 * @param y delataY
 * @return distance
 */
float calculateDist(int x1, int y1, int x2, int y2) {
	return sqrt(x1*x2 + y1*y2);
}

/**
 * Calculates the difference between to values
 * @param x
 * @param y
 * @return the difference
 */
int calculateDif(int x, int y) {
	return (x - y);
}

#endif /* SRC_UTILS_H_ */
