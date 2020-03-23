clear all
close all
clc

t = linspace(-2*pi,2*pi,1000);
plot(t,sin(t));
grid on;
hold on;
plot(t,cos(t),'r');

%toBeContinued