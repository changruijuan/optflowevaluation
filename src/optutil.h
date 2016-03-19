/*
*  FILE optutil.h
*  AUTHOR Ruijuan Chang
*  TODO: The six optical flow algorithm common(all them can use those) function. 
*/
#pragma once

#include "stdafx.h"
#include <cv.h>

using namespace cv;
using namespace std;

#ifndef util_FOE_TTC_
#define util_FOE_TTC_

/*
*  Method:     balanceControlLR
*  Description: Realizing the balance strategy.   
*  Returns:    float.  The translation of robots. 
*  bool isBig:   Required = true. If it is true, it is a big obstacle, and vice versa. 
*  int leftSumFlow:   Required = true. The sum of optical flow in the left side. 
*  int rightSumFlow: Required = true. The sum of optical flow in the right side.
*  float k: It is a threshold value. 
*/
float balanceControlLR(bool isBig, int leftSumFlow, int rightSumFlow, float k);

/*
*  Method:     turnLRScale
*  Description: If not a big obstacle, using the balance strategy. 
*  Returns:    float.  The translation of robots. 
*  int leftSumFlow:   Required = true. The sum of optical flow in the left side. 
*  int rightSumFlow: Required = true. The sum of optical flow in the right side.
*  float k: It is a threshold value. 
*/
float turnLRScale(float leftSumFlow, float rightSumFlow, float k);

/*
*  Method:     writeFile
*  Description: Writing the string "lineStr" to the file. 
*  Returns:    void
*  const char* lineStr:   The string write to the file. 
*/
void writeFile(const char* lineStr);

#endif /* util_FOE_TTC_ */