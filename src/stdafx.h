/*
*  FILE stdafx.h
*  AUTHOR Ruijuan Chang
*  TODO: The constants of the program. 
*/
#pragma once

#include <stdio.h>

#define ROWS 350  //ROWS: Memory allocation for optical flow, as to	HEIGHT.
#define COLS 350  //COLS: Memory allocation for optical flow, as to	WIDTH.
#define HEIGHT 180   //After resize, image height.
#define WIDTH 320   //After resize, image width.
#define MAX_CORNERS  150  //Feature number for PyrLK.
#define WINSIZE 5  // Window size.
#define DRAWGAP 15  // Drawing flow gap.
#define UNKNOWN_FLOW_THRESH 1e10  // Threshold for delete the too big flow.
#define LK_K 4 // The threshold of LK. 
#define HS_K 4.2 // The threshold of HS. 
#define BM_K 7.36 // The threshold of BM. 
#define FB_K 4.8 // The threshold of FB. 
#define SF_K 2 // The threshold of SF. 
#define PYRLK_K 2.36 // The threshold of PyrLK. 
#define INT_FLOAT 100.0 // The transformation between int and float. 
#define K_FLAG true  // In the balance strategy, the value of k.
#define EDGE 0 //The edge of image used in calculating the sum of right or left. 
#define EDGE_OBS 0.33  // The edge of image used in function isBigObstacle(). 
#define COLOR_SCALE 20  // The threshold of percentage that the range of same color. 
#define THRESHOLD_TIMER 0.75 // The threshold of percentage that color is same. 
#define THRESHOLD_ZERO 0.8 // The threshold of percentage that optical flow is zero. 
#define FLOW_ZERO 0 // If the optical flow is small then FLOW_ZERO, ignore it. 
#define FB_SCALE 10e8  // The scale of FB
#define IS_WRITE_FILE false   //If write the result to the file.
#define PI 3.1415926 //PI 

