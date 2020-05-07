clear all
close all
clc

[t,y] = ode45(@odefun,[0 10],[10]);
plot(t,y);

[m,n] = ode45(@fun,[0,10],1);
plot(m,n);

[p1,r1] = ode45(@testfun,[0:0.01:5],1);
plot(p1,r1,'k');
figure(2)
[p2,r2] = ode23(@testfun,[0:0.01:5], 1);
plot(p2,r2,'r');

function dydt = odefun(t,y)
dydt = -t*y/10;
end

function dy = fun(t,y)
   dy = sin(y) - sin(t);
end

function yprim = testfun(t,y)
yprim = -t*y/sqrt(2-y^2);
end
