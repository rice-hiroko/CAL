/*
 * RefuelStation.cpp
 *
 *  Created on: 30/03/2017
 *      Author: João Tomé Saraiva
 */
#include "RefuelStation.h"

RefuelStation::RefuelStation(int i, int v, float a, float b, float c): id(i), velocity(v), x(a), y(b), z(c), passed(false) {}

int RefuelStation::getId() {
	return id;
}

int RefuelStation::getVelocity() {
	return velocity;
}

void RefuelStation::setVelocity(int v) {
	velocity = v;
}

float RefuelStation::getX() {
	return x;
}

float RefuelStation::getY() {
	return y;
}

void RefuelStation::setPassed() {
	passed = true;
}

bool RefuelStation::getPassed() {
	return passed;
}
