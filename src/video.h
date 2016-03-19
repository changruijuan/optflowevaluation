/*
*  FILE video.h
*  AUTHOR Ruijuan Chang
*  TODO: Use different optical flow algorithm to process video and frame.
*/
#pragma once

#include "stdafx.h"
#include <cv.h>
#include "navigation.h"

using namespace cv;
using namespace std;

#ifndef util_VIDEO_
#define util_VIDEO_

/*
*  Method:     imgVideo
*  Description: Processing video with dense optical flow, and the parameter type is IplImage.
*               Press ESC to exit.
*  Returns:    void.  flow_video on ../video/flow_img.avi, and color_video on ../video/color_img.avi.
*  ImgFunType funtype:  Required = true. LK(Lucaskanade)/HS(HornSchunck)/BM(BlockMatch) optical flow.
*  int strategic: Required = true. Default is 1. binary_to_int. a means that the binary a' position is 1. 
*                 1-balance, 2-draw flow, 3-motionToColor. e.g. If strategic is 5, stand for balance and motionToColor.
*  String inputfile: Required = false. Default video get from ARDrone and you can pass parameters with other video file.
*/
void imgVideo(ImgFunType funtype, int strategic = 1, String inputfile = "tcp://192.168.1.1:5555");

/*
*  Method:     matVideo
*  Description: Processing video with dence optical flow, and the parameter type is cv::Mat.
*               Press ESC to exit.
*  Returns:    void. flow_video on ../video/flow_mat.avi, and color_video on ../video/color_mat.avi.
*  MatFunType funtype: Required = true. SF(SimpleFlow)/FB(FarneBack) optical flow.
*  int strategic: Required = false. The same to the imgVideo.
*  String inputfile: Required = false. Default video get from ARDrone and you can pass parameters with other video file.
*  bool issf: Required = true. Default is FB, because SF spend too much time. False is use FB, true is SF.
*             If you want to process SF, issf must be true, otherwise will run error.
*/
void matVideo(MatFunType funtype, bool issf =false, int strategic = 1,String inputfile = "tcp://192.168.1.1:5555");

/*
*  Method:     imgFeatureVideo 
*  Description: Processing video with thin optical flow, and the parameter type is IplImage.
*               Press ESC to exit.
*  Returns:    void  flow_video on ../video/flow_feature.avi, and color_video on ../video/color_feature.avi.
*  ImgFeatureFunType funtype: Required = true. PyrLK optical flow.
*  int strategic: Required = false. The same to the imgVideo.
*  String inputfile: Required = false. Default video get from ARDrone and you can pass parameters with other video file.
*/
void imgFeatureVideo(ImgFeatureFunType funtype, int strategic = 1, String inputfile = "tcp://192.168.1.1:5555");

/*
*  Method:     imgFlow
*  Description: Processing frame with dense optical flow, and the parameter type is IplImage.
*  Returns:    void. The function is balance and draw optical flow.
*  ImgFunType funtype: Required = true. LK/HS/BM optical flow.
*  String imgprev:  Required = true. The previous image.
*  String imgcurr: Required = true. The current image.
*/
void imgFlow(ImgFunType funtype,String imgprev, String imgcurr);

/*
*  Method:     matFlow
*  Description: Processing frame with dense optical flow, and the parameter type is cv::Mat.
*  Returns:    void. The function is balance and draw optical flow.
*  MatFunType funtype: Required = true. SF/FB optical flow.
*  String frameprev: Required = true. The previous image.
*  String framecurr: Required = true. The current image.
*  bool issf: Required = false. Default is FB, because SF spend too much time. False is use FB, true is SF.
*             If you want to process SF, issf must be true, otherwise will run error.
*/
void matFlow(MatFunType funtype, String frameprev, String framecurr, bool issf = false);

/*
*  Method:     imgFeatureFlow
*  Description: Processing frame with thin optical flow, and the parameter type is IplImage.
*  Returns:    void. The function is balance and draw optical flow.
*  ImgFeatureFunType funtype: Required = true. PyrLK optical flow.
*  String imgprev: Required = true. The previous image. 
*  String imgcurr: Required = true. The current image.
*/
void imgFeatureFlow(ImgFeatureFunType funtype, String imgprev, String imgcurr);

/*
*  Method:     avoidMain
*  Description: The entrance of function main. The difference of parameters will execute difference optical flow methods and strategies. 
*  Returns:    void. 
*  int argc： Required = true. The nunber of main function. 
*  char* argv[]: Required = true. It is same to main function. Format(optical flow methods, strategies, the video path]).
*                optical flow methods: LK、HS、BM、PyrLK、FB、SF. 
*				 strategies: 1 - the balance strategy; 2 - draw optical flow; 4 - draw MCS(MMunsell Color System). 
*				 			If you want to execute the balance strategy and MSC, the strategies = 1+4=7. 
*							The strategies you want to execute should plus them. Default strategies are only the balance strategy. 
*				 video path: Default is captured from ARDrone. 
*                argc = 1： optical flow methods* 
*                argc = 2： optical flow methods*，strategies*
*                argc = 3： optical flow methods*，strategies*，the video path*
*                光流计算方法：LK、HS、BM、PyrLK、FB、SF
*/
void avoidMain(int argc, char* argv[]);

#endif /* util_VIDEO_ */


