clear all
close all
clc

x = -pi:0.1:pi;
y = x;
z4(x,y,'calc');

%calc.m
function z = calc(x,y)
    z = sin(x).*cos(y);
end

%z4.m
function z4(x,y,func)
    z = feval(func,x,y);
    [X Y] = meshgrid(x,y);
    Z = feval(func,X,Y);
    
    figure(1)
    subplot(3,1,1)
    surf(X,Y,Z);
    xlabel('X-osa');
    ylabel('Y-osa');
    zlabel('Z-osa');
    title('Grafik 1');
    
    subplot(3,1,2)
    plot3(x,y,z,'kd--');
    title('Grafik 2');
    axis tight
    
    subplot(3,1,3)
    imagesc(Z);
    colormap gray;
    colorbar;
    title('Grafik 3');
    
end