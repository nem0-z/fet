clear all
close all
clc

x = [1 2 3 4];
[A,B,C] = z3(x);

function [A,B,C] = z3(x)
     n = length(x);
     
    if n<4
        error('Duzina vektora mora biti minimalno 4');
    end
    if nargin~=1
        error('Samo jedan ulazni arg')
    end
    if nargout ~=3
        error('Samo 3 izlazna arg')
    end
   
    A = zeros(n,3*n);
    A(1:n,1:n) = diag(x);
    A(:,[1 n n+1]) = [x' x' x'];
    A(end,n+1:2*n) = flip(x);
    A(end:-1:1,2*n) = x;
    A(end:-1:1,2*n+1:3*n) = diag(x);
    A([1 end],2*n+1:3*n) = [x; x];
    
    B = ones(2*n-1);
    for i = 1:n
        B(i: 2*n-i,i:2*n-i) = i;
    end
    
    
    C = diag(ones(1,n));
    for i = 1:n-1
        C = C + diag((i+1)*ones(1,n-i),i) + diag((i+1)*ones(1,n-i),-i);
    end
    C = fliplr(C);

end