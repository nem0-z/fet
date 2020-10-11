clear all
close all
clc

%ones(m,n) - jedinice
%zeros(m,n) - nule
%rand(m,n) - randoms between 0 and 1
%eye(n) - jedinicna m-a reda n

%za ove prve 3 mozes proslijediti i jedan
%argument pa ce vratiti kvadratnu matricu

%ako hocemo rand matricu u [a,b] intervalu:
%koristimo (b-a)*rand(m,n)+a

a = rand(3)*10+5