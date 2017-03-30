/*
 * Automovel.h
 *
 *  Created on: 30/03/2017
 *      Author: João Tomé Saraiva
 */

#ifndef SRC_BUS_H_
#define SRC_BUS_H_

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
	Automovel(int i,int b, int c);
	int getId();
	float getBattery();
	float getConsume();
	void setBattery(float b);
	void setConsume(float c);
	bool checkDist(int dis);
};

#endif /* SRC_BUS_H_ */
