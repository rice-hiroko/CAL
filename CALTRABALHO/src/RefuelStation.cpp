/*
 * RefuelStation.cpp
 *
 *  Created on: 30/03/2017
 *      Author: João Tomé Saraiva
 */
#include "RefuelStation.h"

RefuelStation::RefuelStation(int i,int v): id(i),velocidade(v) {}

int RefuelStation::getId() {
	return id;
}

int RefuelStation::getVelocidade() {
	return velocidade;
}

void RefuelStation::setVelocidade(int v) {
	velocidade = v;
}
