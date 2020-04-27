clear all
close all
clc

x = 0:0.01:2*pi;
y = sin(x);
plot(x,y,'r');
hold on;
dydx = diff(y)./diff(x);
plot(x,dydx(1:length(x)),'k');

function y = myfun(x)
    y = cos(exp(x)) + x.^2-1;
end
