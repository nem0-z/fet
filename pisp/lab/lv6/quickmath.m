clear all
close all
clc

A = [1 2 -3;-3 -1 1;1 -1 1];
B = [5;8;0];

x = A\B;

[V,D] = eig(A);

a = [3 -2; 5 3];
b = [17;3];
solution = a\b;
%alternativno
%solution = inv(a)*b;
% A x = B, x = A^-1 * B

a1 = [2 -2;-1 1;3 4];
b1 = [4;3;2];
solution2 = a1\b1;
%ofc ovde inv ne radi jer nije square matrix


s = -4:0.1:4;
t = s.^2;
% plot(s,t);
% hold on;
t = t + randn(size(s));
plot(s,t,'r.');
hold on;
val = polyfit(s,t,2);
%polyfit aproksimira podatke o t polinomom 2.reda
myPoly = polyval(val,s);
%polyval evaluira taj polinom na nekom vektoru
plot(s,myPoly);




