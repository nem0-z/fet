clear all
close all
clc

A = [1 2 3;4 5 6]

S = sum(diag(A,1)) + sum(diag(fliplr(A),-1));

V =[prod(A(find(A<7))), max(A(:,1)), length(find(mod(A,2)==0))]';
% 
 B = [8:-3:2;3.^(0:2);2.^(5:-2:1)];

