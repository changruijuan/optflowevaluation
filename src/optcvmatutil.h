/*
*  FILE optcvmatutil.h
*  AUTHOR Ruijuan Chang
*  TODO: LK/HS/BM dense optical flow algorithm common function, e.g. balance, draw flow.
*/
#pragma once

#include "stdafx.h"
#include <cv.h>

#include "optutil.h"

using namespace cv;
using namespace std;

#ifndef util_OPT_CVMAT_
#define util_OPT_CVMAT_


/*
*  Method:     balanceForDenseCvMat
*  Description: Left flow is balance to right flow. 
*  Returns:    int. Control command. 1 - left, 2 - right, 3 - forward, 4 - stop. 
*  CvMat * velx: Required = true. Optical flow of X. 
*  CvMat * vely: Required = true. Optical flow of Y. 
*  IplImage * imgdst: Required = true. The destination image imgdst.
*  int threshold: Required = true. The threshold for stop, and when optical flow bigger then it will return 4.
*  float k: Required = false. The weight between left and right, and when the weight is less then k will return 3.
*  int px: Required = false. The dividing line of left and right.
*  int py: Required = false. The dividing line of up and down.
*  float edge: Required = false. The dividing line of ignore the flow area. 
*/
float balanceForDenseCvMat(CvMat* velx, CvMat* vely, IplImage* imgdst, float k, int px = WIDTH/2, int py = HEIGHT/2);

/*
*  Method:     drawFlowForDenseCvMat
*  Description: Drawing flow of imgdst.
*  Returns:    void. 
*  CvMat * velx: Required = true. Optical flow of X. 
*  CvMat * vely: Required = true. Optical flow of Y. 
*  IplImage * imgdst: Required = true. The destination image imgdst.
*/
void drawFlowForDenseCvMat(CvMat* velx, CvMat* vely, IplImage* imgdst);

/*
*  Method:     drawFlow
*  Description: Drawing a optical flow with an arrow. 
*  Returns:    void
*  CvPoint p:   Required = true. Source point.
*  CvPoint q:   Required = true.  Destination point. q - p = optical flow. 
*  IplImage * imgdst: Required = true. Drawing arrows in imgdst.
*/
void drawFlow(CvPoint p, CvPoint q, IplImage* imgdst);

/*
*  Method:     isBigObstacle
*  Description: Determining whether large obstacles. 
*  Returns:    bool. If true, the frontal of the viewpoint is a large obstacles, and vice versa.
*  IplImage * imgdst: Required = true. 
*  CvMat * velx: Required = true. The optical flow of current image in the x axis. 
*/
bool isBigObstacle(IplImage* imgdst, CvMat* velx);

#endif