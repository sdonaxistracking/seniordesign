/*
 * Camera.h
 *
 *  Created on: Sep 12, 2013
 *      Author: owner
 */

#ifndef CAMERA_H_
#define CAMERA_H_
struct camera{

	double dblAzimuth;
	double dblElevation;

};

void getAzimuth();
void getElevation();
void initializeCamera();



#endif /* CAMERA_H_ */
