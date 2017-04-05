/*
 * Automovel.h
 *
 *  Created on: 30/03/2017
 *      Author: João Tomé Saraiva
 */

#ifndef SRC_VEHICLE_H_
#define SRC_VEHICLE_H_

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Automovel {
	int id;
	float battery;
	float consume;

public:
	Automovel(int i,float b, float c);
	int getId();
	float getBattery();
	float getConsume();
	void setBattery(float b);
	void setConsume(float c);
	bool checkDist(int dis);
};

#endif /* SRC_VEHICLE_H_ */
