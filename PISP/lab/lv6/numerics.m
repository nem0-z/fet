clear all
close all
clc

x = 0:0.01:2*pi;
y = sin(x);
dydx = diff(y)./diff(x);

mat = [1 3 5; 4 6 8];
dmat = diff(mat,1,2);

%1 - prvi izvod matrice mat duz 2 - druge dimenzije

[diffx,diffy] = gradient(mat);

% [t,y] = ode45(@hem,[0 0.2],[0 1]);
% plot(t,y(:,1),'k','LineWidth',1.5);
% hold on;
% plot(t,y(:,2),'r','LineWidth',1.5);

[m,n] = ode45(@pendulum,[0 10],[0.9*pi 0]);
plot(m,n(:,1));
hold on;
plot(m,n(:,2),'r');


function dxdt = pendulum(t,x)
L = 1;
theta = x(1);
gamma = x(2);

dtheta = gamma;
dgamma = -(9.8/L)*sin(theta);

dxdt = zeros(2,1);

dxdt(1) = dtheta;
dxdt(2) = dgamma;
end

function dydt = hem(t,y)
dydt = zeros(2,1);
dydt(1) = -10*y(1) + 50*y(2);
dydt(2) = 10*y(1) - 50*y(2);
end


