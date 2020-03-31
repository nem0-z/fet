clear all
close all
clc

4*pi;
1/0;
0/0;
4^2;
sqrt(2);
cos(pi);
floor(3.7);
ceil(3.7);

a = [1 2 3];
transpose(a);
a.';
a';

b = [1+i,2+3*i];
transpose(b);
b';
b.';    %pazi na razliku izmedju ' i .' kad imas kompleksne brojeve

a = [1 2 3]*[3 5 4]';
b = [1 2 3].*[3 5 4];
c=log(b);

m = [1 3 2; 2 5 4]
n = [6 3 3; 1 5 2]
m>=n;
m>2;
m~=n;
m>2&n<3;
~(m<3);
m&m>2;
%btw operatori nad matricama ce formirati matricu
%boolova (boolovi ne postoje u matlabu ali ono hehe :) )
%jer oni vracaju 0 ili 1

r = [1 3 -2 5];
x = min(r);
y = max(r);
s = sum(r);
p = prod(r);

A = [1 2 3;10 20 30]
M = min(A);
N = max(A);
S = sum(A);
P = prod(A);
S1 = sum(A,2);
P1 = prod(A,2);
%overload ovih funkcija kojima proslijedis matricu kao argument
%ce uvijek vracati vektor, obicno rade operacije nad kolonama
%help sum && help prod za ovo s dimenzijama
%u sustini druga dimenzija znaci po redovima 
%(po kolonama je prva dim - default)

