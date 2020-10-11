clear all
close all
clc

a = linspace(0,10,5)
b = 0:2:10
c = 1:5

a = [2 6 10 14 18 22;
     5 8 11 14 17 20;
     2 6 10 14 18 22];
 
a(2,:)

a(:,2:5)

b = a([1 3],[2 5]) %sve sto se presjeca 
% u 1. i 3.redu sa 2. i 5.kolonom

a(16) %indeksira po kolonama



 
    