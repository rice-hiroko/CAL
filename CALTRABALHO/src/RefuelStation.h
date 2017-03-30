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
	float velocidade;


public:
	RefuelStation(int i,int v);
	int getId();
	int getVelocidade();
	void setVelocidade(int v);
};




#endif /* SRC_REFUELSTATION_H_ */
