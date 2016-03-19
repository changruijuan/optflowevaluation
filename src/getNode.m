% get the synthetic world
%   input: wrlFile, the path of wrlFile;
%          nodeName, the viewpoint name in wrl file.
%   output: world, the synthetic world;
%           fig, the image in current viewpoing; 
%           node, the viewpoint

function [ world, fig, node ] = getNode( wrlFile, nodeName)
%GET Summary of this function goes here
%   Detailed explanation goes here
    world = vrworld(wrlFile);
    open(world);
    fig = view(world, '-internal');
    get(world);
    nodes(world);
    node = vrnode(world, nodeName);
end

