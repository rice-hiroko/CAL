/*
 * RefuelStation.cpp
 *
 *  Created on: 30/03/2017
 *      Author: João Tomé Saraiva
 */
#include "RefuelStation.h"

RefuelStation::RefuelStation(int i, int v): id(i), velocity(v), passed(false) {}

int RefuelStation::getId() {
	return id;
}

int RefuelStation::getVelocity() {
	return velocity;
}

void RefuelStation::setVelocity(int v) {
	velocity = v;
}

void RefuelStation::setPassed(bool b) {
	passed = b;
}

bool RefuelStation::getPassed() {
	return passed;
}
