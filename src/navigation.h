/*
*  FILE navigation.h
*  AUTHOR Ruijuan Chang
*  TODO: Processing the optical flow and get the navigation command. 
*/
#pragma once

#include "stdafx.h"
#include <cv.h>
#include "optutil.h"
#include "opticalflow.h"

using namespace cv;
using namespace std;

#ifndef optflow_NAVIGATION_
#define  optflow_NAVIGATION_
//Encapsulating LK/HS/BM
typedef float (*ImgFunType)(IplImage* imgprev, IplImage* imgcurr, CvMat* velx, CvMat* vely);

//Encapsulating SF/FB
typedef Mat (*MatFunType)(Mat frameprev, Mat framecurr, Mat flow);

//Encapsulating PyrLK
typedef float (*ImgFeatureFunType)(IplImage* imgprev, IplImage* imgcurr,CvPoint2D32f* cornersprev,CvPoint2D32f* cornerscurr);

/*
*  Method:     imgFeature
*  Description: Calculating optical flow and using flow to navigation.
*               Used video.h, and using common.h & opt*util.h
*  Returns:    int. 
*  ImgFeatureFunType funtype: Required = true. PyrLK optical flow.
*  IplImage * imgprev: Required = true. The first image.
*  IplImage * imgcurr: Required = true. The second image.
*  IplImage * imgdst: Required = true. The image for drawing optical flow etc..
*/
float imgFeatureStrategic(ImgFeatureFunType funtype,IplImage* imgprev, IplImage* imgcurr, IplImage* imgdst, int strategic = 1);

/*
*  Method:     imgStrategic
*  Description: Calculating optical flow and using flow to navigation, and the parameter type is IplImage.
*               Used video.h, and using common.h & opt*util.h & motioncolor.h
*  Returns:    void. 
*  ImgFunType funtype: Required = true. LK(Lucaskanade)/HS(HornSchunck)/BM(BlockMatch) optical flow.
*  IplImage * imgprev: Required = true. The first image.
*  IplImage * imgcurr: Required = true. The second image.
*  IplImage * imgdst: Required = true. The image for drawing optical flow etc..
*  Mat & color: Required = true. Motion to color, is about optical flow to color. 
*  int strategic: Required = false. Default 1 - balance. Described at imgVideo of video.h 
*/
float imgStrategic(ImgFunType funtype, IplImage* imgprev, IplImage* imgcurr, IplImage* imgdst, Mat &color, int strategic = 1);

/*
*  Method:     matStrategic
*  Description: Calculating optical flow and using flow to navigation, and the parameter type is cv::Mat.
*               Used video.h, and using common.h & opt*util.h & motioncolor.h
*  Returns:    void. 
*  MatFunType funtype: Required = SF(SimpleFlow)/FB(FarneBack) optical flow.
*  Mat frameprev: Required = true. The first image.
*  Mat framecurr: Required = true. The second image.
*  Mat framedst: Required = true. The image for drawing optical flow etc..
*  Mat & color: Required = true. Motion to color, is about optical flow to color.
*  int strategic: Required = false. Default 1 - balance. Described at imgVideo of video.h 
*  bool issf: Required = false. Default is FB, because SF spend too much time. False is use FB, true is SF.
*             If you want to process SF, issf must be true, otherwise will run error.
*/
float matStrategic(MatFunType funtype, Mat frameprev, Mat framecurr, Mat &framedst,Mat &color, int strategic = 1, bool issf = false);

#endif /* optflow_NAVIGATION_ */



