/*
 * Laser.c
 *
 *  Created on: Sep 17, 2013
 *      Author: owner
 */
#include "../Include/Laser.h"


void openLaserConnection(){

}
void closeLaserConnection(){

}
double getLaserRange(char sInputCommand[]){

	struct laser oLaser;
	double dblTest;

	oLaser.dblRange=3.1;
	dblTest = (double)oLaser.dblRange;
	return dblTest;
}

