clear all
close all
clc

z4(1:10,1:10,'c');

function res = c(a,b)
    res = 3.*a + 5.*b; 
end

function z4(a,b,fun)
    d = feval(fun,a,b);
    [A B] = meshgrid(a,b);
    D = feval(fun,A,B);
    
    figure(1)
    plot3(a,b,d,'k');
    grid on
    axis tight
    legend('y = 3*a+5*b');
    title('Grafik 1');
    xlabel('X-osa');
    ylabel('Y-osa');
   
    figure(2)
    subplot(1,2,1)
    surf(A,B,D);
    colormap hot;
    shading faceted;
    title('Grafik 2.1');
    xlabel('X-osa');
    ylabel('Y-osa');
    subplot(1,2,2)
    surf(A,B,D);
    colormap hot;
    shading interp;
    title('Grafik 2.2');
    xlabel('X-osa');
    ylabel('Y-osa');
end
