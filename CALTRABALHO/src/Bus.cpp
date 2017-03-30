/*
 * Bus.cpp
 *
 *  Created on: 30/03/2017
 *      Author: João Tomé Saraiva
 */
#include "Bus.h"

Automovel::Automovel(int i, int b, int c): id(i),battery(b),consume(c){}

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
	battery = b;
}

void Automovel::setConsume(float c) {
	consume = c;
}

bool Automovel::checkDist(int dist) {
	if(battery -(consume * dist) > 0) {
		cout << "Pass"<<endl;
		this->setBattery(battery - (consume * dist));
		return true;
	}
	cout << "Refuel" << endl;
	return false;
}

