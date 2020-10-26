clear all
close all
clc

%Realnih brojeva iz intervala (0,1) prema unfirmnoj raspodjeli.

%Realnih brojeva iz intervala (-5,5) prema unfirmnoj raspodjeli.

%Cijelih brojeva iz intervala (0,1) prema unfirmnoj raspodjeli.

%Realnih brojeva sa srednjom vrijednoscu 1 i standardnom devijacijom 2
%prema normalnoj raspodjeli

%Cijelih brojeva sa srednjom vrijednoscu 0 i standardnom devijacijom 1
%prema normalnoj raspodjeli

N = 100;
x = rand(1,N);
n = 1:length(x);
subplot(5,1,1)
stem(n,x);

x1 = 10*rand(1,N)-5;
subplot(5,1,2)
stem(n,x1);

x2 = round(rand(1,N));
subplot(5,1,3)
stem(n,x2);

x3 = 1 + 2*randn(1,N); %inace je srednja vrijednost u 0, pa ga pomjeramo za 1, devijaciju mijenjamo mnozenjem
subplot(5,1,4)
stem(n,x3);

x4 = round(randn(1,N));
subplot(5,1,5)
stem(n,x4);