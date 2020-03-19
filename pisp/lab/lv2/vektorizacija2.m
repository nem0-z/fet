clear all
close all
clc

x = [4 5 6];
y = [1 2 3;4 5 6; 7 8 9];
diag(x);
diag(y);
%znaci ako diag pozoves nad matricom, vraca ti elemente s dijagonale
%a ako pozoves nad vektorom, on te elemente stavi na dijagonalu matrice
%pazi na offset, npr diag(x,1) - podere vektor x na dijagonalu
%prvu iznad glavne, taj tamo argument moze ici (-inf,inf)
diag(x,1);
%fliplr zamijeni mjesta lijeve i desne kolone
%posljedica toga je da su se flipale i glavna i sporedna dijagonala
%flipud isto samo mijenja gornji i donji red

%4.zadatak - kreiraj nxn matricu 
% ima elemente jednake 3*m^2 osim dijagonale,
% tu su jednaki 2*n
m = input('unesite m: ');
n = input('unesite n: ');
v(1:n) = 2*n; 
t = diag(v)
t(find(t==0)) = 3*m^2;
t = fliplr(t);
s = diag(t);

%probaj jos malo obrtanje matrica, dijagonale, itd itd