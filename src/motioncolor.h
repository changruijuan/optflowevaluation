/*
*  FILE motioncolor.h
*  AUTHOR Ruijuan Chang
*  TODO: Motion to color, is about optical flow to color. 
*/
#pragma once

#include "stdafx.h"
#include <cv.h>
#include "optutil.h"

using namespace cv;
using namespace std;

#ifndef util_MOTIONCOLOR_
#define util_MOTIONCOLOR_

/*
*  Method:     makeColorWheel
*  Description: Constructing MunsellColor System.
*               http://blog.csdn.net/zouxy09/article/details/8683859  
*  Returns:    void. 
*  vector<Scalar> & colorwheel: Required = true. (After the function ,it will be assigned)
*/
void makeColorWheel(vector<Scalar> &colorwheel);

/*
*  Method:     motionMatToColor
*  Description: Using colorwheel convert optical flow(flow) to color, and the parameter type is IplImage.
*  Returns:    void. 
*  Mat flow: Required = true. Optical flow. 
*  Mat & color: Required = true. (After the function ,it will be assigned)
*/
void motionMatToColor(Mat flow, Mat &color);

/*
*  Method:     motionCvMatToColor
*  Description: Using colorwheel convert optical flow(velx, vely) to color, and the parameter type is IplImage.
*  Returns:    void. 
*  CvMat * velx: Required = true. Optical flow of X.
*  CvMat * vely: Required = true. Optical flow of Y.
*  Mat & color: Required = true. (After the function ,it will be assigned)
*/
void motionCvMatToColor(CvMat* velx, CvMat* vely, Mat &color);

#endif /* util_MOTIONCOLOR_ */