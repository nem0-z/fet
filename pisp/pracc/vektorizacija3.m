clear all
close all
clc

m = 10*rand(5)+5;
tmp = find(m>10);
greaterThan10 = length(tmp);
m(tmp) = sqrt(m(tmp));
m(~tmp) = m(~tmp).^2;
m;
sum(m);
