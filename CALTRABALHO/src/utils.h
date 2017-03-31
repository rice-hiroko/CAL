/*
 * utils.h
 *
 *  Created on: 31/03/2017
 *      Author: João Tomé Saraiva
 */

#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_

#include <cmath>

float calculateDist(int x, int y) {
	return sqrt(x*x + y*y);
}

int calculateDif(int x, int y) {
	return (x - y);
}

#endif /* SRC_UTILS_H_ */
