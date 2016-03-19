% The c++ file is compiled to the function that can be called for Matlab.

function [ ] = mexall(func)
%GET Summary of this function goes here
%   Detailed explanation goes here
    switch func
        case 1 % For the optical flow  methods of LK/HS/BM. 
            mex mainCvMat.cpp mcext.cpp navigation.cpp motioncolor.cpp optcvmatutil.cpp optfeatureutil.cpp optmatutil.cpp opticalflow.cpp optutil.cpp stdafx.cpp
        case 2 % For the optical flow  methods of FB. 
            mex mainMat.cpp mcext.cpp navigation.cpp motioncolor.cpp optmatutil.cpp optcvmatutil.cpp optfeatureutil.cpp opticalflow.cpp optutil.cpp stdafx.cpp
        case 3 % For the optical flow  methods of PyrLK. 
            mex mainFeature.cpp mcext.cpp navigation.cpp motioncolor.cpp optcvmatutil.cpp optfeatureutil.cpp optmatutil.cpp opticalflow.cpp optutil.cpp stdafx.cpp
    end
end