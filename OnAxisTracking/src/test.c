//Test again

//git hub is installedsdfsdfsdf!!!!!
//test
//Jeremy penis
//sketchy sketchy...never click on the hammer!!
/*
 * test.c
 *
 *  Created on: Aug 27, 2013
 *      Author: jordan-rewolinski
 */


////////////////////////////////////////////////////////////////////////
//
// hello-world.cpp
//
// This is a simple, introductory OpenCV program. The program reads an
// image from a file, inverts it, and displays the result. 
//
////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cv.h>
#include <highgui.h>


int main(int argc, char** argv){
	cvNamedWindow("Camera", CV_WINDOW_AUTOSIZE);
	CvCapture* capture = cvCaptureFromCAM(-1);
	IplImage* frame;
	IplImage* zoomImage;
	while(1){
		frame = cvQueryFrame(capture);
		zoomImage = cvCreateImage(cvSize(frame->width * 2, frame->height*2), frame->depth, frame->nChannels);
		cvResize(frame, zoomImage,CV_INTER_LINEAR);

		if(!frame)break;

		cvShowImage("Camera", zoomImage);
		char c = cvWaitKey(33);
		if(c == 27) break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Camera");
}
