%kreira m-u A dimenzija 5x5 koja sadrzi random prirodne brojeve iz [1,10], kreira
%m-u B dimenzija 5x5 ciji su elementi random prirodni brojevi iz [5,15], osim
%elemenata sporedne dijagonale koji su jednaki elementima sporedne
%dijagonale matrice A

clear all
close all
clc

A = round(9*rand(5)+1)
b1 = round(10*rand(5)+5);
b2 = fliplr(diag(diag(fliplr(A))));
b3 = fliplr(diag(diag(fliplr(b1))));
B = b1-b3+b2 
