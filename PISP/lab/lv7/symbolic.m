clear all
close all
clc

syms x y
S = solve(x^2+y^2-1==0,y == 4*sqrt(3)*x^3==0);
% ezplot(x^2+y^2-1==0);
hold on;
% ezplot(4*sqrt(3)*x^3-y==0);

sym t
jed = 'D2y + 8*Dy + 2*y = cos(t)';
uslovi = 'y(0) = 0, Dy(0) = 1';
r = dsolve(jed,uslovi,'t');
% ezplot(r)

clear all
close all
syms x a b;
Q = int(x*exp(x),a,b);
subs(Q,{a,b},{0,2});

sym x;
a = 3*x^3-x^2-3*x+1;
b = x^2+3*x;
f = a/b;
nule = solve(a);
prekid = solve(b);

clear all
close all

sym x;
y = dsolve('4*D2y+3*y=cos(2*x)','y(0)=0','Dy(0)=1','x');
ezplot(y);
