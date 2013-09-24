/*
 * Laser.h
 *
 *  Created on: Sep 12, 2013
 *      Author: owner
 */

#ifndef LASER_H_
#define LASER_H_
struct laser{


	double dblRange;
};
void openLaserConnection();
void closeLaserConnection();
double getLaserRange(char sInputCommand[]);

#endif /* LASER_H_ */


