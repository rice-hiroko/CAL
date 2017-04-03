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

//alterei
class RefuelStation {
	int id;
	int velocity;
	bool passed;

public:
	RefuelStation(int i, int v);
	int getId();
	int getVelocity();
	void setVelocity(int v);
	void setPassed(bool b);
	bool getPassed();
};




#endif /* SRC_REFUELSTATION_H_ */
