clear all
close all
clc

x = -2:0.1:2;
y = sqrt(4-x.^2);
plot(x,y);
hold on;
y = -sqrt(4-x.^2);
plot(x,y);
