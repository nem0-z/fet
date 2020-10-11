clear all
close all
clc

%index = find(uslov)
x = rand(1,100);
inds = find(x>0.4 & x<0.6);

y = sin(linspace(0,10*pi,100));
%koliko elemenata vektora x je pozitivno
s = length(find(y>0));

z = [5 6 2 4 5];
find(z<5) %ovo nam vrati indekse gdje su elementi
% iz z manji od 5
z(find(z<5)) % ovako "dereferenciramo"

str = '----------------------------';
disp(str);

A = 20*rand(5) + 10 % 5x5 m-a, svi random, interval [10,30]
length(find(A>20)) %broj elemenata vecih od 20
A(3,:) %ispisi treci red
A(:,2) = linspace(5,15,5) %zamijeni drugu kolonu sa vektorom
% koji ima 5 vrijednosti [5,15]
A(5,:) = [] % obrisi peti red
A(:,1) = [] % obrisi prvu kolonu
find(A<15) %indeksi elemenata manjih od 15
