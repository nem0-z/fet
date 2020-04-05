clear all
close all
clc


% x = -pi:1e-2:pi;
% y = x;
% [X Y] = meshgrid(x,y);
% Z = sin(X).*cos(Y);
% surf (X,Y,Z);
% axis tight
% colormap jet
% shading interp
% grid on

% x = -2*pi:0.1:2*pi;
% y = x;
% [X,Y] = meshgrid(x,y);
% Z = exp(-1/10*(X.^2+Y.^2)).*sin(X.*Y);
% surf(X,Y,Z);
% colormap jet
% colorbar
% shading interp
% grid on

% x = linspace(-2,2,20);
% y = x;
% [X Y] = meshgrid(x,y);
% Z = X+j*Y;
% f = abs(1 ./ (Z.^4 + 1));
% surf(X,Y,f);
% colormap hot;
% shading interp;
% 
% plotSin(3,4);
% 
% function plotSin(f1,f2)
%     if nargin == 2
%        x = linspace(0,2*pi,round(16*f1)+1);
%        y = linspace(0,2*pi,round(16*f2)+1);
%        [X Y] = meshgrid(x,y);
%        Z = sin(f1*X)+sin(f2*Y);
%        subplot(2,1,1)
%        imagesc(Z);
%        colorbar;
%        colormap hot;
%        axis xy;
%        subplot(2,1,2)
%        surf(X,Y,Z);
%     end
% end


