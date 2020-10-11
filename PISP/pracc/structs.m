clear all
close all
clc

A = {rand(2,2,2), 'Februar', 10.28};
B{1,1} = 1:8;
B{1,2} = strvcat('Ponedeljak','Utorak','Srijeda','Cetvrtak');
B{2,2} =  A;
% cellplot(B)

L = plot(1:10,rand(1,10));
