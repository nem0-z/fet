clear all
close all
clc

A = [2 3 3;5 1 3;5 2 2];

x1 = prod(diag(fliplr(A),1))*prod(diag(fliplr(A),-1));
x2 = sum(sum(A));
x3 = max(A([1 3],2));

X = [x1 x2 x3]

y1 = length(find(A<3));
y2 = min(diag(A));
y3 = sum(A(2,:));

Y = [y1 y2 y3]

Z = X.*Y;

skalarniProizvod = X*Y';
B = ones(length(Z)+2).*skalarniProizvod;
B(end-1:-1:2,2:end-1) = diag(Z)

S1 = sparse(B);
full(S1);
spy(S1);

x=-4:0.1:4;
y = x.^2;
plot(x,y,'r');
hold on; grid on;
y = y+randn(size(y));
% plot(x,y,'b.'); hold on;
P = polyfit(x,y,2);
plot(x,polyval(P,x),'k--');





