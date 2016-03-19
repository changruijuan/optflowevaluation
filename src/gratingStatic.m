% When both gratings are static, calculating the offset and oritation of the viewpoint.
% input: 
%       funcname, the function name of optical flow name: LK, HS, BM, FB,
%       PyrLK;
%       fig, the image in current viewpoing; 
%       View1, the viewpoint;
%       varargin, the optional parameters.
% output: 
%        result, the turn, trajectory and the orientation of the viewpoint.

function [ result] = gratingStatic( funcname, fig, View1, varargin )
%   Detailed explanation goes here
    strategic = 7; % 1, the balance strategy£»3 - draw optical flow with 
                   % arrows£»7 - using Munsell Color System to visualize 
                   % optical flow.  
    if nargin == 4
        strategic = varargin{1};
    end
    originX = 2.5; % the initial of the viewpoint in x direction.
    originY = 2; % the initial of the viewpoint in y direction.
    originZ = -5.5; % the initial of the viewpoint in z direction.
    skip = 2; % the step of the viewpoint
    distance = 340; % the distance of go forward.
    width = 10; % the width of the tunnal. 
    ori = 3.14; % 90 degrees. 
    gap = 10; % the scale of offset.
    % Cupturing video
    View1.position=[originX originY originZ];
    View1.orientation = [0 1 0 ori];
    writerflow = VideoWriter('../video/flow.avi');
    writerflow.FrameRate = 10;
    open(writerflow);
    
    writercolor = VideoWriter('../video/color.avi');
    writercolor.FrameRate = 10;
    open(writercolor);
    turn  = 0; % the offset. 
    result = zeros(distance+10, 8); % Storing the turn, trajectory and the orientation of the viewpoint.
    degree = View1.fieldOfView/width;
    for t=0:skip:distance
        if turn == -2 % -2 means stop.
            [ stop, ori] = turneq2(funcname, fig, View1, strategic, ori, t, skip, result);
            if stop == 1
                break;
            else
                View1.orientation = [0 1 0 ori];
            end
        end
        if turn == 0 % 0 means go straight.
            View1.orientation = [0 1 0 ori];
        end
        View1.position = View1.position;
        vrdrawnow;
        ima = capture(fig);
        ima_1 = double(ima);
        turndis = turn/gap;

        if (turn ~= 0 || turn ~= -2)
            View1.orientation = View1.orientation + [0 0 0 turndis*degree];
        end
        multi = floor(mod((ori/1.57), 4));
        switch multi
            case 0
                 View1.position = View1.position + [turndis 0 -0.1*skip];
            case 1 
                 View1.position = View1.position + [-0.1*skip 0 -turndis];
            case 2 
                 View1.position = View1.position + [-turndis 0 0.1*skip];
            case 3 
                 View1.position = View1.position + [0.1*skip 0 turndis];
        end
        result(t/skip + 1, :) = [turn, View1.position,View1.orientation ];
        
        vrdrawnow;
        imb = capture(fig);
        imb_1 = double(imb);
        % Capturing two consecutive frames and then calculates turn. 
        % If turn is negative, the viewpoint will be guided to left, and vice versa. 
        if (strcmp(funcname, 'LK')||strcmp(funcname, 'HS')||strcmp(funcname, 'BM'))
            [imt, color, turn] = mainCvMat(funcname, ima_1, imb_1, strategic);
        elseif (strcmp(funcname, 'FB')||strcmp(funcname, 'SF'))
            [imt, color, turn] = mainMat(funcname, ima_1, imb_1, strategic);
        elseif (strcmp(funcname, 'PyrLK'))
            [imt, color, turn] = mainFeature(funcname, ima_1, imb_1, strategic);
        end
        subplot(2,1,1),imshow(imt), title('flow');
        subplot(2,1,2),imshow(color), title('color');
        writeVideo(writerflow, imt);
        writeVideo(writercolor, color);
    end
    for i=0:1:10
        writeVideo(writerflow, imt);
    end
    close(writerflow);
    close(writercolor);
end
