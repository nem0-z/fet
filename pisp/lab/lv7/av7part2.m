clear all
close all
clc

%z2

% n = z3();

%z3

n = z31();

function Dmax = z31
Dmax = 0; maxx = 0; maxy = 0;
n = input('Koliko tacaka? ');
T = struct([]);
for i = 1:n
   T(i).x = input('x: ');
   T(i).y = input('y: ');
   d = sqrt((T(i).x)^2 + (T(i).y)^2);
   if d>Dmax
      Dmax = d;
      maxx = T(i).x;
      maxy = T(i).y;
   end
end
   tx = [T(1:n).x];
   ty = [T(1:n).y];
   plot(tx,ty,'bo','MarkerSize',10);
   hold on;
   grid on;
   a = [0 maxx];
   b = [0 maxy];
   plot(a,b,'r');
end

function N = z3
n1 = 0; n2 = 0; n3 = 0; n4 = 0;
T = struct([]);
n = input('koliko tacaka? ');
for i = 1:n
   disp(['Unos podataka ' num2str(i) '. tacke" ']);
   T(i).x = input('x koordinata: ');
   T(i).y = input('y koordinata: ');
   if(T(i).x>=0 && T(i).y>=0) n1 = n1+1;
   elseif (T(i).x<0 && T(i).y>=0) n2 = n2+1;
   elseif (T(i).x<0 && T(i).y<0) n3 = n3+1;
   elseif (T(i).x>=0 && T(i).y<0) n4 = n4+1;
   else disp('Pogresan unos!');
       break;
   end
end
disp(n1);
disp(n2);
disp(n3);
disp(n4);
tx = [T(1:n).x];
ty = [T(1:n).y];
plot(tx,ty,'ro','MarkerSize',12);
[maxVal,maxInd] = max([n1 n2 n3 n4]);
N = maxInd;
end

