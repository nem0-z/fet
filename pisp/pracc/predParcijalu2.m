clear all
close all
clc


fun(1:10,1:10,'calc');

function z = calc(x,y)
z = sin(x) + cos(y);
end

function fun(a,b,c)
  [A B] = meshgrid(a,b);
  Z = feval(c,A,B);
  subplot(1,2,1)
  surf(A,B,Z);
  colormap hot;
  axis tight
  
  subplot(1,2,2)
  surf(A,B,sqrt(abs(Z)));
  colormap hot;
  axis tight
end