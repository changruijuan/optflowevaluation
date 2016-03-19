/*
*  FILE optmatutil.h
*  AUTHOR Ruijuan Chang
*  TODO: SF/FB dense optical flow algorithm common function, e.g. balance, draw flow.
*/
#pragma once

#include "stdafx.h"
#include <cv.h>

#include "optutil.h"

using namespace cv;
using namespace std;

#ifndef util_OPT_MAT_
#define util_OPT_MAT_

/*
*  Method:     balanceForDenseMat
*  Description: Left flow is balance to right flow. 
*  Returns:    int. Control command. 1 - left, 2 - right, 3 - forward, 4 - stop. 
*  Mat flow: Required = true. Optical flow.
*  Mat framedst: Required = true. Destination image frame.
*  int threshold: Required = true. The threshold for stop, and when optical flow bigger then it will return 4.
*  float k: Required = false. The weight between left and right, and when the weight is less then k will return 3.
*  int px: Required = false. The dividing line of left and right.
*  int py: Required = false. The dividing line of up and down.
*  float edge: Required = false. The dividing line of ignore the flow area. 
*/
float balanceForDenseMat(Mat flow, Mat &framedst, float k, int px = WIDTH/2, int py = HEIGHT/2);

/*
*  Method:     drawFlowForDenseMat
*  Description: Drawing flow of framedst. 
*  Returns:    void. 
*  Mat flow: Required = true. Optical flow. 
*  Mat framedst: Required = true. The destination image frame.
*/
void drawFlowForDenseMat(Mat flow, Mat &framedst);

/*
*  Method:     drawFlow
*  Description: Drawing a optical flow with an arrow. 
*  Returns:    void
*  CvPoint p:   Required = true. Source point.
*  CvPoint q:   Required = true.  Destination point. q - p = optical flow. 
*  Mat & framedst: Required = true. Drawing arrows in framedst.
*/
void drawMatFlow(CvPoint p, CvPoint q, Mat &framedst);

/*
*  Method:     isBigObstacle
*  Description: Determining whether large obstacles. 
*  Returns:    bool. If true, the frontal of the viewpoint is a large obstacles, and vice versa.
*  IplImage * imgdst: Required = true. 
*  CvMat * velx: Required = true. The optical flow of current image in the x axis. 
*/
bool isBigObstacleMat(Mat &framedst, Mat flow);
#endif