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

double calculateX(double lon, int width) {
	// width is map width
	double x = fmod((width * (180 + lon) / 360), (width + (width / 2)));
	return x;
}

double calculateY(double lat, int height, int width) {
	// height and width are map height and width
	double PI = 3.14159265359;
	double latRad = lat * PI / 180;

	// get y value
	double mercN = log(tan((PI / 4) + (latRad / 2)));
	double y = (height / 2) - (width * mercN / (2 * PI));
	return y;
}

#endif /* SRC_UTILS_H_ */
