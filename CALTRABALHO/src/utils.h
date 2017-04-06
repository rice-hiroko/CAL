/*
 * utils.h
 *
 *  Created on: 31/03/2017
 *      Author: João Tomé Saraiva
 */

#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_

#include <cmath>
#include <time.h>
#include <sys/timeb.h>

/**
 * Calculates the distance between two deltas X and Y
 * @param x deltaX
 * @param y delataY
 * @return distance
 */
double calculateDist(int x1, int y1, int x2, int y2) {
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

int GetMilliCount()

{

  timeb tb;

  ftime( &tb );

  int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;

  return nCount;

}



int GetMilliSpan(int nTimeStart)

{

  int nSpan = GetMilliCount() - nTimeStart;

  if (nSpan < 0)

	  nSpan += 0x100000 * 1000;

  return nSpan;

}

#endif /* SRC_UTILS_H_ */
