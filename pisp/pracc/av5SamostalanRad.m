clear all
close all
clc


% function z(n,m)
%     
% if nargin~=[1 2]
%     error('Foo');
% end
% if nargout ~=0
%     error('Bar');
% end
% 
% if nargin == 1
%    x = 0:0.1:2*pi;
%    z = sin(n*x);
%    plot(x,z,'b--');
%    axis tight
%    grid on
% end
% 
% if nargin == 2
%     x = -pi:0.1:pi;
%     y = x;
%     [X Y] = meshgrid(x,y);
%     Z = sin(n*X)+sin(m*Y);
%     surf(X,Y,Z);
%     shading interp
%     colormap gray
% end

% fun(1:5,2)
% 
% function fun(x,n)
%     disp('Originalni vektor')
%     disp(x)
%     y = x+rand(size(x))*n;
%     disp('Vektor sa sumom')
%     disp(y)
%     
%     figure(1)
%     plot(x,'b');
%     
%     figure(2)
%     plot(y,'r');
%     
% end

% x = -pi:0.1:pi;
% y = x;
% grafik(x,y,'f');
% 
% %kao u datoteci f.m
% function z = f(x,y)
% z = 2*sin(x).*cos(y);
% end
% 
% function grafik(x,y,func)
%     z = feval(func,x,y);
%     [X,Y] = meshgrid(x,y);
%     Z = feval(func,X,Y);
%     
%     subplot(2,1,1)
%     plot3(x,y,z,'r');
%     grid on
%     
%     subplot(2,1,2)
%     surf(X,Y,Z);
%     colormap hot
%     colorbar
%     
% end

% x = -pi:0.01:pi;
% y = x;
% test(x,y,'fun');
% 
% function z = fun(x,y)
%     z = cos(x).*sin(y);
% end
% 
% function test(x,y,predicate)
%     z = feval(predicate,x,y);
%     [X,Y] = meshgrid(x,y);
%     Z = feval(predicate,X,Y);
%     
%     subplot(2,2,1)
%     plot3(x,y,z);
%     axis tight
%     
%     subplot(2,2,2)
%     imagesc(Z);
%     colormap hot
%     colorbar
%     
%     subplot(2,2,3)
%     surf(X,Y,Z);
%     
%     subplot(2,2,4)
%     contourNum = 8;
%     contour(X,Y,Z,contourNum);
% end

x = [1:100];
y = x;
povrsina(x,'foo',y);

function z = foo(x,y)
    z = x^3 + y^3;
end

function povrsina(x,fun,y)
    [X,Y] = meshgrid(x,y);
    Z = feval(fun,X,Y);
    subplot(1,2,1)
    surf(X,Y,Z);
    colormap jet
    
    subplot(1,2,2)
    surf(X,Y,sqrt(Z));
    colormap hot
end