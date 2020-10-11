clear all
close all
clc

%7a
sym x
S = solve('x^2+y^2-4=0','-2*x+y-2=0');
y = dsolve('2*D2y-9*y=sin(8*x)','y(0)=0','Dy(0)=1','x');

subplot(2,1,1)
plot(S.x,S.y,'rs');

subplot(2,1,2)
ezplot(y);
axis tight