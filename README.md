# opticalflow

###Optical flow based the balance strategy for obstacles avoidance developed by Matlab mixed with C++. 
--------------------------------------------------------------------------------------------------------------------------------------------------


* src: The source code of Matlab and C++;
* video: It is place where put the video file or the results that are the output of the program. 
* vrlm: The synthetic environments.

--------------------------------------------------------------------------------------------------------------------------------------------------


* VRML (virtual reality modeling language) in MATLAB build the synthetic 3D environment. 
The observation viewpoint is used as a substitute for on-board camera.


* C++ is mainly adopted in the realization of optical flow algorithms, the balance strategy and Munsell Color System. 

>>>
1. Five public optical optical methods are selected in our experiments: Lucas-Kanade (LK), Horn-Schunck (HS), Block Matching (BM),
FarneBack (FB) and Pyramid Lucas-Kanade (PyrLK).

2. The balance strategy: If the sum of the left flow is bigger, the robot will be guided right, and vice versa.  

3. Munsell Color System is to visualize OF.
>>>

* MATLAB is mainly used for capturing the image frames and controlling the motion of the observation viewpoint.


--------------------------------------------------------------------------------------------------------------------------------------------------


Requires Matlab (Windows).


**Note**: First the Matlab wrapper needs to be compiled into a mex file using Matlab by going to the directory containing the library 
and running the following command within Matlab:

``` 
mexall(1) // optical flow methods of LK, HS, BM. 
mexall(2) // optical flow methods of FB. 
mexall(3) // optical flow methods of PyrLK. 
```


Start the robot simulation by typing in Matlab:

```
mainMatlab  // You can comment or uncomment the codes to run the function you want.
```

--------------------------------------------------------------------------------------------------------------------------------------------------


Requires VS (Windows)

In VS, input parameters should include the video path, optical flow function name, strategy. The specific description is in avoidMain() of video.cpp.

The main function in the file named "avoidOptflow.cpp" .


------------------------------------------------------------------------------

Copyright 2016 by Ruijuan Chang (changruij@buaa.edu.cn)


******************************************************************************
