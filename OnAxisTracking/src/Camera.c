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
int m_nColorMode = 0;                               // Y8/RGB16/RGB24/REG32
int m_nBitsPerPixel=8;                          // number of bits needed store one pixel
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
        // retrieve original image size
        SENSORINFO sInfo;
        is_GetSensorInfo (m_hCam, &sInfo);
        m_nSizeX = sInfo.nMaxWidth;
        m_nSizeY = sInfo.nMaxHeight;

        // setup the color depth to the current windows setting
        is_GetColorDepth (m_hCam, &m_nBitsPerPixel, &m_nColorMode);
        is_SetColorMode (m_hCam, m_nColorMode);

        //printf ("m_nBitsPerPixel=%i  m_nColorMode=%i \n", m_nBitsPerPixel, IS_CM_BAYER_RG8);

        // memory initialization
        is_AllocImageMem (m_hCam, m_nSizeX, m_nSizeY, m_nBitsPerPixel, &m_pcImageMemory, &m_lMemoryId);
        //set memory active
        is_SetImageMem (m_hCam, m_pcImageMemory, m_lMemoryId);
        // display initialization
        is_SetImageSize (m_hCam, m_nSizeX, m_nSizeY);
        is_SetDisplayMode (m_hCam, IS_SET_DM_DIB);
    }
    if (m_hCam !=0) {
        if (is_FreezeVideo (m_hCam, IS_WAIT) == IS_SUCCESS) {
            is_RenderBitmap (m_hCam, m_lMemoryId, m_hWndDisplay, m_nRenderMode);
        }
    }

    IplImage* tmpImg = cvCreateImageHeader (cvSize (m_nSizeX, m_nSizeY), IPL_DEPTH_8U, 1);
    tmpImg->imageData = m_pcImageMemory;

    cvNamedWindow ("Acquisition", 1);
    cvShowImage ("Acquisition", tmpImg);
    cvWaitKey (0);
}


