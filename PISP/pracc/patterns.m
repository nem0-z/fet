%vjezbanje patterna
clear all
close all
clc

%A = zeros(n,2*n) %msm moze a i ne mora
x = [1 2 3 4]; %na osnovu ovoga
n = length(x);
A(1:n,1:n) = diag(x);
A(1:n,n+1:2*n) = fliplr(diag(x));
A(:,2*n+1:3*n) = diag(x)

%znaci kao sto vidis, ti mozes m-u A siriti koliko hoces bez neke prethodne
%alokacije ili slicno

%B = zeros(n,2*n); %nah
B(1,1:n) = x(end:-1:1); % mozes koristiti flip(x)
B(n,1:n) = x;
B(:,n+1:2*n) = diag(x)
B(:,n) = x';
B(:,2*n) = x'
%ove dvije linije bi trebalo da rade kao B(:,[n 2*n]) = x'; al nece
