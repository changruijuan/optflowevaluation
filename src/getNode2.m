% get the synthetic world
%   input: wrlFile, the path of wrlFile;
%          nodeName*, the node name in wrl file.
%   output: world, the synthetic world;
%           fig, the image in current viewpoing; 
%           node*, the node

function [ world, fig, node1, node2 ] = getNode2( wrlFile, nodeName1, nodeName2 )

    world = vrworld(wrlFile);
    open(world);
    fig = view(world, '-internal');
    get(world);
    nodes(world);
    node1 = vrnode(world, nodeName1);
    node2 = vrnode(world, nodeName2);
end
