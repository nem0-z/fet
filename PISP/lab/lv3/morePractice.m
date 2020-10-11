clear all
close all
clc

x = linspace(0,2*pi,1000);
y = sin(x);
y(55);
y(100:110);
[minVal,minInd] = min(y);
[maxVal,maxInd] = max(y);
indexes = find(y>-0.001 & y<0.001);

mat = zeros(3,100);
x = linspace(0,10,100);
mat(1,:) = cos(x);
mat(2,:) = log((x+2).^2);
mat(3,:) = rand(1,100);
rs = sum(mat,2);
cs = sum(mat);

%iz matrice A ekstrahovati elemente podvucene linijom
%pogledaj zadatak 9 u materijalu da vidis sta je podvuceno

A = [1 6 7 8 2;1 5 6 7 3;1 8 9 2 3;0 5 2 9 9];
r = [1 1 2 2 3 3 4 4];
k = [1 2 2 3 3 4 4 5];
inds = sub2ind(size(A),r,k);
elems = A(inds);