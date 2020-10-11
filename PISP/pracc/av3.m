clear all
close all
clc

y = zeros(4);
y(:,1) = 10*rand(1,4);
y(:,2) = linspace(5,14,4);
y(:,3) = y(:,1).*y(:,2);
y(:,4) = sum(y,2)
det(y);
rank(y);
inv(y);

x = [3 4 2 6];
m = ones(length(x)+2);
%gore plus dva jer hocemo da matrica napravljena od x-a bude u sredini sto
%znaci da nam trebaju jos po jedan ovaj hepek sa strana, thus +2
m(end-1:-1:2,2:end-1) = diag(x);



