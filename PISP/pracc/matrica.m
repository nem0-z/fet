%unos prirodnog broja n(n>2) i ispisuje m-u X dimenzija nxn, m-a X ima
%elemente 3n^2 osim elemenata dijagonale iznad glavne dijagonale matrice i
%elemenata dijagonale ispod glavne dijagonale koji su = 2n-3
clear all
close all
clc

n = input('Unesi broj n: ');
if (n<3)
    error('n mora biti >2');
end
a(1:n-1) = 2*n-3;
x1 = diag(a,1);
x2 = diag(a,-1);
X = x1+x2;
X(find(X==0)) = 3*n^2

