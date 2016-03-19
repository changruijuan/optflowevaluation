% the main function of programe

clear;clc

%% gratings are static when the viewpoint is moving.  
 [ world, fig, View1 ] = getNode( '../vrlm/gratings_same.wrl', 'VPfollow' );  % gratings' periods are same. 
% [ world, fig, View1 ] = getNode( '../vrlm/gratings_diff.wrl', 'VPfollow');  % gratings' periods are variational
%  [ result] = gratingStatic( 'LK', fig, View1, 7);
% [ result] = gratingStatic( 'HS', fig, View1, 7);
% [ result] = gratingStatic( 'BM', fig, View1, 7);
% [ result] = gratingStatic( 'FB', fig, View1, 7);
[ result] = gratingStatic( 'PyrLK', fig, View1, 7);


%%  gratings are movint with the viewpoint. 
%  [ world, fig, View1, Wall ] = getNode2( '../vrlm/gratings_same.wrl', 'VPfollow' ,'Left');
% [ world, fig, View1, Wall ] = getNode2( '../vrlm/gratings_diff.wrl', 'VPfollow' ,'Left');
% [ result] = gratingMove( 'LK', fig, View1,Wall, 7);
% [ result] = gratingMove( 'HS', fig, View1, Wall, 7);
% [ result] = gratingMove( 'BM', fig, View1, Wall, 7);
% [ result] = gratingMove( 'FB', fig, View1, 7);
% [ result] = gratingMove( 'PyrLK', fig, View1, 7);


