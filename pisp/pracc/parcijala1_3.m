clear all
close all
clc

x = [1 2 3 4];
[A B] = z3(x);

%u datoteci z3.m
function [A,B] = z3(x)
    l = length(x);
    if l<3
        error('Vektor sadrzi minimalno 3 elementa');
    end
    if nargin ~=1
        error('Fja ima jedan ulaz');
    end
    if nargout ~=2
        error('Fja ima dva izlaza');
    end
    
    A = zeros(l,3*l);
    A(:,1) = x';
    A(end,1:l) = flip(x);
    A(end:-1:1,l+1:2*l) = diag(x);
    A([1,end],l+1:2*l) = [x;x];
    A(1:end,2*l+1:3*l) = diag(x);
    A(:,[2*l+1,3*l]) = [x', x'];
    A
    
    for i = 1:l
        B(i:2*l-i,i:2*l-i) = l+1-i;
    end
    B
end