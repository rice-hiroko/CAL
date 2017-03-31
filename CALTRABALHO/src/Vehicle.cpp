/*
 * Bus.cpp
 *
 *  Created on: 30/03/2017
 *      Author: João Tomé Saraiva
 */
#include "Vehicle.h"

Automovel::Automovel(int i, float b, float c): id(i),battery(b),consume(c){}

float Automovel::getBattery(){
	return battery;
}

int Automovel::getId(){
	return id;
}

float Automovel::getConsume(){
	return consume;
}

void Automovel::setBattery(float b) {
	if(b >= 100)
		battery = 100;
	else
		battery = b;
}

void Automovel::setConsume(float c) {
	consume = c;
}

bool Automovel::checkDist(int dist) {
	if(battery -(consume * dist) >= 0) {
		return true;
	}
	return false;
}

