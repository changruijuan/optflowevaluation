/*
*  FILE mcext.h
*  AUTHOR Ruijuan Chang
*  TODO: The transformation of image format between Matlab and C++. 
*/
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cxcore.h>

#include "mex.h"

using namespace cv;

// Transforming image format from Matlab to IpllImage in C++. 
IplImage* mxArray2IplImage8U3(const mxArray* mx);

// Transforming image format from IpllImage in C++ to Matlab. 
mxArray* IplImage2mxArray8U3(IplImage* im);

// Transforming image format from Matlab to Mat in C++. 
Mat mxArray2cvMat8U3(const mxArray* mx);

// Transforming image format from Mat in C++ to Matlab. 
mxArray* cvMat2mxArray8U3(Mat mat);

