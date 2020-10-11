clear all
close all
clc

%zadatak1.m

%test1 = zadatak1(3,4);

%zadatak2.m 

test2 = zadatak2(5);

function y = zadatak1(n,m)

    if nargin ~=[1 2]
        error('Funkcija ima 1 ili 2 ulazna argumenta');
    end
    if nargout ~= 1
        error('Funkcija ima jedan izlazni argument');
    end

    if nargin == 1
       y = round(10*rand(4)+10);
       inds = find(mod(y,2));
       y(inds) = y(inds) + 2*n^2;
       greaterThan20 = length(y>20)
       sumSecondRow = sum(y(2,:))
       transposed = transpose(inv(y))
    end
    
    if nargin == 2
        y = round(10*rand(4)+10);
        y = diag(diag(y));
        y(find(y == 0)) = n*m;
        prodThirdColumn = prod(y(:,3))
        rang = rank(y)
    end
        
end

function y = zadatak2(n)
    if nargin ~= 1
        error('Vec me ovo umorilo');
    end
    
    if n<=3
        error('Ovaj broj kao mora biti veci od 3');
    end
    
    y = zeros(5);
    y(1,:) = n*rand(1,5)
    y(2,:) = linspace(1,n,5)
    y(3,:) = n/3 * ones(1,5)
    y(4,:) = (n^2) * ones(1,5)
    y(5,:) = sum(y)
    length(find(y<5*n))
    prod(prod(y))
    A = y([1 3 5],[2 4])
    transpose(A)
end