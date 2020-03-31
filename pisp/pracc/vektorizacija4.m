%kreira matricu A dimenzija 3x3 ciji su elementi nasumicno kreirani
%prirodni brojevi iy intervala [1,5] a zatim pogledaj 4.zadatak av3 lol
clear all
close all
clc

%A = round(4*rand(3)+1);
A = [2 3 3;5 1 3;5 2 2];
X(1) = prod(diag(fliplr(A),1))*prod(diag(fliplr(A),-1));
X(2) = sum(sum(A));
X(3) = max(A([1 3],2));

Y(1) = length(find(A<3));
Y(2) = min(diag(A));
Y(3) = sum(A(2,:));

Z = X.*Y;

B = (X*Y') * ones(length(Z)+2);
B(end-1:-1:2,2:end-1) = diag(Z);

