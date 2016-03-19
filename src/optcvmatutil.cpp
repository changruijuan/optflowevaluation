#include "stdafx.h"
#include <cv.h>

#include "optutil.h"
#include "optcvmatutil.h"
#include <math.h>

using namespace cv;
using namespace std;

float balanceForDenseCvMat(CvMat* velx, CvMat* vely, IplImage* imgdst,  float k, int px, int py){
	Vec2i leftSumFlow = Vec2i(0, 0);
    float up = EDGE*HEIGHT;
    float down = (1-EDGE)*HEIGHT;
	for (int i = 0; i < px; i++)
	{
		for (int j = up; j < down; j++)
		{
            int dx = (int) cvGetReal2D(velx, j, i);
            int dy = (int) cvGetReal2D(vely, j, i);
            leftSumFlow[0] += dx;
            leftSumFlow[1] += dy;
		}
	}
	Vec2i rightSumFlow = Vec2i(0, 0);
	for (int i = px; i < WIDTH; i++)
	{
		for(int j = up; j < down; j++){
            int dx = (int) cvGetReal2D(velx, j, i);
            int dy = (int) cvGetReal2D(vely, j, i);
            rightSumFlow[0] += dx;
            rightSumFlow[1] += dy;
		}
	}
	//printf("pre left :%d,%d  right:%d,%d\n", leftSumFlow[0], leftSumFlow[1], rightSumFlow[0], rightSumFlow[1]);
    
	leftSumFlow[0] = abs(leftSumFlow[0] / px);
	leftSumFlow[1] = abs(leftSumFlow[1] / px);
	rightSumFlow[0] = abs(rightSumFlow[0] / (WIDTH - px));
	rightSumFlow[1] = abs(rightSumFlow[1] / (WIDTH - px));

	if(IS_WRITE_FILE){
		char buffer[50];
		sprintf(buffer, "%d	%d\n", leftSumFlow[0], rightSumFlow[0]);
		writeFile(buffer);
	}

    bool isBig = isBigObstacle(imgdst, velx);
    float result  = balanceControlLR(isBig, leftSumFlow[0], rightSumFlow[0], k);
    
    Vec2i diffFlow = Vec2i(leftSumFlow[0] - rightSumFlow[0], rightSumFlow[1] - leftSumFlow[1]);

	cvLine(imgdst, cvPoint(px, py), cvPoint(px+diffFlow[0], py), CV_RGB (0, 255, 0), 3, CV_AA, 0);
	
	CvFont font;
	cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX|CV_FONT_ITALIC, 1, 1, 0, 2);

	if (result == -2*INT_FLOAT)
	{
		cvPutText(imgdst, "S", cvPoint(20, 20), &font, CV_RGB(255, 0, 0));
	}else if (result  == 0)
	{
		cvPutText(imgdst, "F", cvPoint(20, 20), &font, CV_RGB(255, 0, 0));
 	}else if (result < 0)
	{
		cvPutText(imgdst, "L", cvPoint(20, 20), &font, CV_RGB(255, 0, 0));
	}else if (result > 0)
	{
		cvPutText(imgdst, "R", cvPoint(20, 20), &font, CV_RGB(255, 0, 0));
	}
    return  result;
}

void drawFlowForDenseCvMat(CvMat* velx, CvMat* vely, IplImage* imgdst){
	 for (int i = 0; i < HEIGHT; i += 1)
	 {
		 for(int j = 0; j < WIDTH; j += 1){
             if((int) cvGetReal2D(velx, i, j)==0|| (int) cvGetReal2D(vely, i, j) ==0)
                 continue;
			 CvPoint p, q;
			 p.x = (int) cvGetReal2D(velx, i, j) + j;
			 p.y = (int) cvGetReal2D(vely, i, j) + i;
			 q.x = j;
			 q.y = i;
			 drawFlow(p, q, imgdst);
		 }
	 }
}

void drawFlow(CvPoint p, CvPoint q, IplImage* imgdst){
	double angle; 
	angle = atan2((double) p.y - q.y, (double) p.x - q.x);
	double hypotenuse; 
	hypotenuse = sqrt(((p.y - q.y)*(p.y - q.y) +(p.x - q.x)*(p.x - q.x))*1.0);
	
	q.x = (int) (p.x - 3 * hypotenuse * cos(angle));
	q.y = (int) (p.y - 3 * hypotenuse * sin(angle));
	cvLine(imgdst, p, q, CV_RGB(0,0,255),1);

	p.x = (int) (q.x + 2 * hypotenuse * cos(angle + CV_PI / 4));
	p.y = (int) (q.y + 2 * hypotenuse * sin(angle + CV_PI / 4));
	cvLine(imgdst, p, q, CV_RGB(0,0,255),1 );
	p.x = (int) (q.x + 2 * hypotenuse * cos(angle - CV_PI / 4));
	p.y = (int) (q.y + 2 * hypotenuse * sin(angle - CV_PI / 4));
	cvLine(imgdst, p, q, CV_RGB(0,0,255),1 );
}
bool isBigObstacle(IplImage* imgdst, CvMat* velx){
   uchar *data = (uchar*)imgdst->imageData;
	int step = imgdst->widthStep / sizeof(uchar);
	int channels = imgdst->nChannels;
	int sumR = 0, sumG = 0, sumB = 0;
	int count = 0;
	for(int i = EDGE_OBS*HEIGHT; i < (1-EDGE_OBS)*HEIGHT; i++){
		for(int j = EDGE_OBS*WIDTH; j < (1-EDGE_OBS)*WIDTH; j++ ){
			sumB += (int)data[i*step+j*channels+0];
			sumG += (int)data[i*step+j*channels+1];
			sumR += (int)data[i*step+j*channels+2];
			count ++ ;
		}
	}
	int avgB = sumB / count;
	int avgG = sumG / count;
	int avgR = sumR / count;
	int timers;
	int timerCount = 0;
	int flowZeroCount = 0;
	for(int i = EDGE_OBS*HEIGHT; i < (1-EDGE_OBS)*HEIGHT; i++){
		for(int j = EDGE_OBS*WIDTH; j < (1-EDGE_OBS)*WIDTH; j++ ){
			timers = 0;
			if(abs((int)data[i*step+j*channels+0] - avgB) < COLOR_SCALE){
				timers += 1;
			}
			if(abs((int)data[i*step+j*channels+1] - avgG) < COLOR_SCALE){
				timers += 1;
			}
			if(abs((int)data[i*step+j*channels+2] - avgR) < COLOR_SCALE){
				timers += 1;
			}
			if (timers == 3)
			{
				timerCount ++;
				if (abs(((int) cvGetReal2D(velx, i, j))) <= FLOW_ZERO)
				{
					flowZeroCount ++;
				}
			}
		}
	}
	float timerPro = (timerCount*1.0)/count;
	float flowZeroPro = (flowZeroCount*1.0)/timerCount;
	if (timerPro > THRESHOLD_TIMER && flowZeroPro > THRESHOLD_ZERO)
	{
		return true;
	}else{
		return false;
	}
}

