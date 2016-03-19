/*
*  FILE optfeatureutil.h
*  AUTHOR Ruijuan Chang
*  TODO: PyrLK thin optical flow algorithm common function, e.g. balance, draw flow.
*/
#pragma once

#include "stdafx.h"
#include <cv.h>

#include "optutil.h"
#include "optcvmatutil.h"

using namespace cv;
using namespace std;

#ifndef util_OPT_FEATURE_CVMAT_
#define util_OPT_FEATURE_CVMAT_

/*
*  Method:     balanceForFeatureCvPoint
*  Description: Left flow is balance to right flow. 
*  Returns:    int. Control command. 1 - left, 2 - right, 3 - forward, 4 - stop. 
*  CvPoint2D32f * cornersprev: Required = true. Optical flow of X. 
*  CvPoint2D32f * cornerscurr: Required = true. Optical flow of Y. 
*  IplImage * imgdst: Required = true. The destination image imgdst.
*  int threshold: Required = true. The threshold for stop, and when optical flow bigger then it will return 4.
*  float k: Required = false. The weight between left and right, and when the weight is less then k will return 3.
*  int px: Required = false. The dividing line of left and right.
*  int py: Required = false. The dividing line of up and down.
*/
float balanceForFeatureCvPoint(CvPoint2D32f* cornersprev_11, CvPoint2D32f* cornerscurr_11, IplImage* imgdst, float k);

/*
*  Method:     drawFlowForFeatureCvPoint
*  Description: Drawing flow of imgdst.
*  Returns:    void. 
*  CvPoint2D32f * cornersprev: Required = true. Optical flow of X. 
*  CvPoint2D32f * cornerscurr: Required = true. Optical flow of Y.
*  IplImage * imgdst: Required = true. The destination image imgdst.
*/
void drawFlowForFeatureCvPoint(CvPoint2D32f* cornersprev_11, CvPoint2D32f* cornerscurr_11, IplImage* imgdst);

#endif