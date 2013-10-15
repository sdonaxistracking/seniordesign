/*
 * Camera.c
 *
 *  Created on: Sep 17, 2013
 *      Author: owner
 */
#include "../Include/Camera.h"
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <ueye.h>

// uEye variables
HIDS m_hCam;                                    // handle to room
HWND m_hWndDisplay;                             // handle to diplay window
int m_Ret;                                      // return value of uEye  SDK functions
int m_nColorMode = IS_CM_BGR8_PACKED;                               // Y8/RGB16/RGB24/REG32
int m_nBitsPerPixel=24;                          // number of bits needed store one pixel
int m_nSizeX = 1280;                             // width of video
int m_nSizeY = 1024;                             // height of video
int m_lMemoryId;                                // grabber memory - buffer   ID
char* m_pcImageMemory;                          // grabber memory - pointer to buffer
int m_nRenderMode = IS_RENDER_FIT_TO_WINDOW;    //render  mode

void getAzimuth(){

}
void getElevation(){

}
void initializeCamera(){

    if (m_hCam !=0 ) {
        //free old image mem.
        is_FreeImageMem (m_hCam, m_pcImageMemory, m_lMemoryId);
        is_ExitCamera (m_hCam);
    }


    // init room
    m_hCam = (HIDS) 0;    // open next room
    m_Ret = is_InitCamera (&m_hCam, NULL);    // init room

    if (m_Ret == IS_SUCCESS) {
    	//is_SetBinning(m_hCam,IS_BINNING_4X_VERTICAL);

        // retrieve original image size
        SENSORINFO sInfo;
        is_GetSensorInfo (m_hCam, &sInfo);
        m_nSizeX = sInfo.nMaxWidth;
        m_nSizeY = sInfo.nMaxHeight;
        UINT nCaps;
       // is_Exposure(m_hCam, IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE_MAX,(void*)&nCaps,sizeof(nCaps));
        double dEnable=1;
        double nominal = 128;
        double maxshutter;


        is_GetColorDepth (m_hCam, &m_nBitsPerPixel, &m_nColorMode);
        is_SetColorMode (m_hCam, m_nColorMode);
        is_AllocImageMem (m_hCam, m_nSizeX, m_nSizeY, m_nBitsPerPixel, &m_pcImageMemory, &m_lMemoryId);
        is_SetImageMem (m_hCam, m_pcImageMemory, m_lMemoryId);
        IS_SIZE_2D imageSize;
        imageSize.s32Width=m_nSizeX;
        imageSize.s32Height=m_nSizeY;
        is_AOI(m_hCam,IS_AOI_IMAGE_SET_SIZE,(void*)&imageSize,sizeof(imageSize));
        //is_Exposure(m_hCam, IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE_MAX,(void*)&nCaps,sizeof(nCaps));

        is_SetDisplayMode(m_hCam, IS_SET_DM_DIB);
        // setup the color depth to the current windows setting







        //printf ("m_nBitsPerPixel=%i  m_nColorMode=%i \n", m_nBitsPerPixel, IS_CM_BAYER_RG8);

        // memory initialization

        //set memory active

        // display initialization
        //is_SetImageSize (m_hCam, m_nSizeX, m_nSizeY);
        //is_SetDisplayMode (m_hCam, IS_SET_DM_DIB);
        //is_CaptureVideo(m_hCam, IS_WAIT);
    }
    if (m_hCam !=0) {

        if (is_FreezeVideo (m_hCam, IS_WAIT) == IS_SUCCESS) {
            is_RenderBitmap (m_hCam, m_lMemoryId, m_hWndDisplay, m_nRenderMode);
            	IplImage* tmpImg = cvCreateImageHeader (cvSize (m_nSizeX, m_nSizeY), IPL_DEPTH_8U,3);
                tmpImg->imageData = m_pcImageMemory;
                IplImage* threshold = cvCreateImage(cvGetSize(tmpImg),IPL_DEPTH_8U,1);

                cvCvtColor(tmpImg, tmpImg, CV_BGR2HSV);
                cvSmooth(tmpImg,tmpImg,CV_GAUSSIAN,3,0,1,0);
                cvInRangeS(tmpImg,cvScalar(0,44,80,0),cvScalar(77,256,256,0), threshold);
               // cvNamedWindow ("Actual", 1);
                //cvShowImage ("Acquisition", tmpImg);
                //cvWaitKey(0);
                cvNamedWindow ("Acquisition", 1);
                cvShowImage ("Acquisition", threshold);
                cvWaitKey (0);
        }
    }



}


