clear all
close all
clc

%a
n = input('Unesi broj-> ');
if n<=4 || mod(n,2) == 0
    error('Pogresan unos');
end

A = (2*n+1)*ones(n+2);
B = round(5*rand(n)+4);
B = B - diag(diag(B)) + diag((n-3)*ones(1,n));
A(2:end-1,2:end-1) = B;

%b
x1 = sum(sum(A(2:end-1,2:end-1)));
x2 = length(find(mod(A,2) & A>n));
x3 = length(find(A([2 3],:) < A(ceil((n+2)^2/2))));
X = [x1 x2 x3]


