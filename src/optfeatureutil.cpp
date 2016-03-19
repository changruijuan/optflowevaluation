#include "stdafx.h"
#include <cv.h>

#include "optutil.h"
#include "optfeatureutil.h"
#include "opticalflow.h"
#include "optcvmatutil.h"

using namespace cv;
using namespace std;

float balanceForFeatureCvPoint(CvPoint2D32f* cornersprev_11, CvPoint2D32f* cornerscurr_11, IplImage* imgdst, float k){
	Vec2i leftSumFlow = Vec2i(0, 0),rightSumFlow = Vec2i(0, 0);
    int left = 0;;
    int right = 0;
    float LS = 0;
    float RS = 0;
	for (int i = 0; i < MAX_CORNERS; i++)
	{
        int dx = abs((int) cornerscurr_11[i].x - (int) cornersprev_11[i].x);
        int dy = abs((int) cornerscurr_11[i].y - (int) cornersprev_11[i].y);
        if(dx <  WIDTH/2 && dy < HEIGHT/2){
             if(cornersprev_11[i].x < WIDTH/2){
                leftSumFlow[0] += dx;
                leftSumFlow[1] += dy;
                LS += sqrt((float)(dx*dx + dy*dy));
                left++;
            }else{
                rightSumFlow[0] += dx;
                rightSumFlow[1] += dy;
                RS += sqrt((float)(dx*dx + dy*dy));
                right++;
            }	
        }
	}

    float result = balanceControlLR(false, abs(LS*10/left), abs(RS*10/right), k); 
    
	return result;
}

void drawFlowForFeatureCvPoint(CvPoint2D32f* cornersprev, CvPoint2D32f* cornerscurr, IplImage* imgdst){
	for (int i =0; i < MAX_CORNERS; i++)
	{
		CvPoint p,q;
		p.x = (int) cornersprev[i].x;
		p.y = (int) cornersprev[i].y;
		q.x = (int) cornerscurr[i].x;
		q.y = (int) cornerscurr[i].y;
        cvCircle(imgdst,q,2,CV_RGB(0,255,0),1,8,3);
		drawFlow(p, q, imgdst);
	}
}



