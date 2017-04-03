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

float RefuelStation::getZ() {
	return z;
}

void RefuelStation::setPassed(bool b) {
	passed = b;
}

bool RefuelStation::getPassed() {
	return passed;
}
