#include "stdafx.h"

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <cv.h>
#include <highgui.h>
#include "opencv2/legacy/legacy.hpp"
#include <math.h>
#include <cstdio>
#include <iostream>

#include "optutil.h"
#include "opticalflow.h"

using namespace cv;
using namespace std;

IplImage* imgResize(IplImage* img){
	IplImage* img_1 = cvCreateImage(cvSize(WIDTH,HEIGHT), img->depth , img->nChannels);
	cvResize(img, img_1);
	IplImage* img_2 = cvCreateImage(cvGetSize(img_1), IPL_DEPTH_8U, 1);
	cvCvtColor(img_1, img_2, CV_BGR2GRAY);
	cvReleaseImage(&img_1);
	return img_2;
}

//LK
float Lucaskanade(IplImage* imgprev, IplImage* imgcurr, CvMat* velx, CvMat* vely){
	CvSize winSize = cvSize(WINSIZE, WINSIZE);
	float start = (float)getTickCount();
	cvCalcOpticalFlowLK (imgprev, imgcurr, winSize, velx, vely);
	printf("cvCalcOpticalFlowLK : %lf sec\n", (getTickCount() - start) / getTickFrequency());
	return LK_K;
}
//HS
float HornSchunck(IplImage* imgprev, IplImage* imgcurr, CvMat* velx, CvMat* vely){
	CvTermCriteria criteria = cvTermCriteria (CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, 20, 0.1);
	float start = (float)getTickCount();
	cvCalcOpticalFlowHS (imgprev, imgcurr, 0, velx, vely, 100.0, criteria);
	printf("cvCalcOpticalFlowHS : %lf sec\n", (getTickCount() - start) / getTickFrequency());
	return HS_K;
}

//BM
float BlockMatch(IplImage* imgprev, IplImage* imgcurr, CvMat* velx, CvMat* vely){

	float start = (float)getTickCount();
	cvCalcOpticalFlowBM(imgprev, imgcurr, cvSize(1, 1), cvSize(1, 1), cvSize(12, 12), 0, velx, vely);
	printf("cvCalcOpticalFlowBM : %lf sec\n", (getTickCount() - start) / getTickFrequency());
	return BM_K;
}

Mat matResize(Mat frame){
	Mat frame_1, frame_2;
	resize(frame,frame_1,Size(WIDTH,HEIGHT),0,0,1);
	cvtColor(frame_1, frame_2, CV_BGR2GRAY);
	frame_1.release();
	return frame_2;
}

Mat matColorResize(Mat frame){
	Mat frame_1;
	resize(frame,frame_1,Size(WIDTH,HEIGHT),0,0,1);
	return frame_1;
}

Mat SimpleFlow(Mat frameprev, Mat framecurr, Mat flow){
	float start = (float)getTickCount();
	calcOpticalFlowSF(frameprev, framecurr,
		flow,
		3, 2, 4, 4.1, 25.5, 18, 55.0, 25.5, 0.35, 18, 55.0, 25.5, 10);
	printf("calcOpticalFlowSF : %lf sec\n", (getTickCount() - start) / getTickFrequency());
	return flow;
}

Mat FarneBack(Mat frameprev, Mat framecurr, Mat flow){
	float start = (float)getTickCount();
	calcOpticalFlowFarneback(frameprev, framecurr, flow, 0.5, 3, 15, 3, 5, 1.2, 0);
	printf("calcOpticalFlowFarneback : %lf sec\n", (getTickCount() - start) / getTickFrequency());
	return flow;
}

float PyrLK(IplImage* imgprev, IplImage* imgcurr,CvPoint2D32f* cornersprev,CvPoint2D32f* cornerscurr){
	IplImage* pyrA = cvCreateImage( cvSize(WIDTH+8, HEIGHT/3), IPL_DEPTH_32F, 1 );
	IplImage* pyrB = cvCreateImage( cvSize(WIDTH+8, HEIGHT/3), IPL_DEPTH_32F, 1 );
	float start = (float)getTickCount();
	cvCalcOpticalFlowPyrLK(
		imgprev,
		imgcurr,
		pyrA,
		pyrB,
		cornersprev,
		cornerscurr,
		MAX_CORNERS,
		cvSize(WINSIZE, WINSIZE),
		5,
		NULL,
		NULL,
		cvTermCriteria( CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, 20, .3 ),
		0
		);
	printf("cvCalcOpticalFlowPyrLK : %lf sec\n", (getTickCount() - start) / getTickFrequency());

	cvReleaseImage(&pyrA);
	cvReleaseImage(&pyrB);
	return PYRLK_K;
}