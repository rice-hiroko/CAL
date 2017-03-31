/*
 * RefuelStation.h
 *
 *  Created on: 30/03/2017
 *      Author: João Tomé Saraiva
 */

#ifndef SRC_REFUELSTATION_H_
#define SRC_REFUELSTATION_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class RefuelStation {
	int id;
	float x;
	float y;
	float z;
	int velocity;
	bool passed;

public:
	RefuelStation(int i, int v, float a, float b, float c);
	int getId();
	int getVelocity();
	void setVelocity(int v);
	float getX();
	float getY();
	void setPassed();
	bool getPassed();
};




#endif /* SRC_REFUELSTATION_H_ */
