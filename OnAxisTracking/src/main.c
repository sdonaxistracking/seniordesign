/*
 * test.c
 *
 *  Created on: Aug 27, 2013
 *      Author: jordan-rewolinski
 */

#include "../Include/Laser.h"
#include "../Include/Camera.h"
#include "../Include/Vectorizer.h"
#include <stdio.h>
#include <stdlib.h>
#include <cv.h>
#include <highgui.h>
#include "ueye.h"
int main()
{
	initializeCamera();
/*int c;sdf
 *
IplImage* color_img;
CvCapture* cv_cap = cvCaptureFromCAM(0);
cvNamedWindow("Video",0); // create window
for(;;) {
color_img = cvQueryFrame(cv_cap); // get frame
if(color_img != 0)
cvShowImage("Video", color_img); // show frame
c = cvWaitKey(10); // wait 10 ms or for key stroke
if(c == 27)
break; // if ESC, break and quit
}

cvReleaseCapture( &cv_cap );
cvDestroyWindow("Video");
*/
	char* sRange[]={'s'};
	double dblRange;
	dblRange = getLaserRange(sRange);
	//printf("The range is: %f",dblRange);
}
