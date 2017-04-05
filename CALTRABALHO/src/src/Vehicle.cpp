/*
 * Bus.cpp
 *
 *  Created on: 30/03/2017
 *      Author: João Tomé Saraiva
 */
#include "Vehicle.h"

/**
 * Class Vehicle
 */
Automovel::Automovel(int i, float b, float c): id(i),battery(b),consume(c){}

/**
 * Gets the current level of the vehicle battery
 * @return the battery level
 */
float Automovel::getBattery(){
	return battery;
}

/**
 * Gets the current level of the vehicle id
 * @return the id
 */
int Automovel::getId(){
	return id;
}

/**
 * Gets the current level of the vehicle consume
 * @return the consume
 */
float Automovel::getConsume(){
	return consume;
}

/**
 * Changes the battery of the vehicle to the value of b
 * (maximum battery = 100 & minimum battery = 0)
 * @param b the new level of the battery
 */
void Automovel::setBattery(float b) {
	if(b >= 100)
		battery = 100;
	else if (b <= 0)
		battery = 0;
	else
		battery = b;
}

/**
 * Changes the consume of the vehicle to the value of c
 * @param c the new consume of the vehicle
 */
void Automovel::setConsume(float c) {
	consume = c;
}

/**
 * Checks if the vehicle can make the distance passed
 * @param dist the distance to check
 * @return true if the vehicle can make the distance or false if he can't
 */
bool Automovel::checkDist(int dist) {
	if(battery -(consume * dist) >= 0) {
		return true;
	}
	return false;
}

