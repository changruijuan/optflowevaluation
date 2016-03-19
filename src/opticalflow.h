/*
*  FILE common.h
*  AUTHOR Ruijuan Chang
*  TODO: Resizing the images and realizing six optical flow algorithms
*/
#pragma once

#include "stdafx.h"
#include <cv.h>
#include "optutil.h"

using namespace cv;
using namespace std;

#ifndef util_OPTFLOW_
#define util_OPTFLOW_

/*
*  Method:     imgResize
*  Description: Resizing and graying the image with #define WIDTH and HEIGHT(in stdafx.h).
*               And the parameter type is IplImage.
*  Returns:    IplImage*. The resized and grayed image.
*  IplImage * img: Required = true. The source image.
*/
IplImage* imgResize(IplImage* img);

/*
*  Method:     Lucaskanade
*  Description: Use the function of cvCalcOpticalFlowLK.
*  Returns:    int. The threshold for stop flow, and the parameter in optcvmatutil.h.
*  IplImage * imgprev: Required = true. The first image.
*  IplImage * imgcurr: Required = true. The second image.
*  CvMat * velx: Required = true. The optical flow of X(After the function ,it will be assigned).
*  CvMat * vely: Required = true. The optical flow of Y(After the function ,it will be assigned).
*/
float Lucaskanade(IplImage* imgprev, IplImage* imgcurr, CvMat* velx, CvMat* vely);

/*
*  Method:     HornSchunck
*  Description: Use the function of cvCalcOpticalFlowHS.
*  Returns:    int. The threshold for stop flow, and the parameter in optcvmatutil.h.
*  IplImage * imgprev: Required = true. The first image.
*  IplImage * imgcurr: Required = true. The second image.
*  CvMat * velx: Required = true. The optical flow of X(After the function ,it will be assigned).
*  CvMat * vely: Required = true. The optical flow of Y(After the function ,it will be assigned).
*/
float HornSchunck(IplImage* imgprev, IplImage* imgcurr, CvMat* velx, CvMat* vely);

/*
*  Method:     BlockMatch
*  Description: Use the function of cvCalcOpticalFlowBM.
*  Returns:    int. The threshold for stop flow, and the parameter in optcvmatutil.h.
*  IplImage * imgprev: Required = true. The first image.
*  IplImage * imgcurr: Required = true. The second image.
*  CvMat * velx: Required = true. The optical flow of X(After the function ,it will be assigned).
*  CvMat * vely: Required = true. The optical flow of Y(After the function ,it will be assigned).
*/
float BlockMatch(IplImage* imgprev, IplImage* imgcurr, CvMat* velx, CvMat* vely);

/*
*  Method:     PyrLK
*  Description: Use the function of cvCalcOpticalFlowBM.
*  Returns:    int. The threshold for stop flow, and the parameter in optmatutil.h.
*  IplImage * imgprev: Required = true. The first image.
*  IplImage * imgcurr: Required = true. The second image.
*  CvPoint2D32f * cornersprev: Required = true. The optical flow of X(After the function ,it will be assigned).
*  CvPoint2D32f * cornerscurr: Required = true. The optical flow of Y(After the function ,it will be assigned).
*/
float PyrLK(IplImage* imgprev, IplImage* imgcurr,CvPoint2D32f* cornersprev,CvPoint2D32f* cornerscurr);

/*
*  Method:     matResize
*  Description: Resizing and graying the image with #define WIDTH and HEIGHT(in stdafx.h). 
*               And the parameter type is cv::Mat, for FarneBack.
*  Returns:    cv::Mat. The resized and grayed image.
*  Mat frame: Required = true. The source image.
*/
Mat matResize(Mat frame);

/*
*  Method:     matColorResize
*  Description: Resizing the image with #define WIDTH and HEIGHT(in stdafx.h). 
*               And the parameter type is cv::Mat, for SimpleFlow.
*  Returns:    cv::Mat. The resized image.
*  Mat frame: Required = true. The source image.
*/
Mat matColorResize(Mat frame);

/*
*  Method:     SimpleFlow
*  Description: Use the function of calcOpticalFlowSF. 
*  Returns:    cv::Mat. The optical flow, for SimpleFlow.
*  Mat frameprev: Required = true. The first image. 
*  Mat framecurr: Required = true. The second image.
*  Mat flow: Required = true. The optical flow(After the function ,it will be assigned).
*/
Mat SimpleFlow(Mat frameprev, Mat framecurr, Mat flow);

/*
*  Method:     FarneBack
*  Description: Use the function of calcOpticalFlowFarneback. 
*  Returns:    cv::Mat. The optical flow.
*  Mat frameprev: Required = true. The first image. 
*  Mat framecurr: Required = true. The second image.
*  Mat flow: Required = true. The optical flow(After the function ,it will be assigned).
*/
Mat FarneBack(Mat frameprev, Mat framecurr, Mat flow);

#endif /* util_OPTFLOW_ */