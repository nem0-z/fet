clear all
close all
clc

T = struct('oznaka',{'A' 'B' 'C' 'D' 'E'},'x',{4 3 2 1 5},'y',{1 2 3 2 5});

c = struktura(T);


function res = struktura(T)
sLen = length(T);
if sLen < 5
    error('Minimalno 5 tacaka');
end
if nargin ~= 1
    error('Funkcija ima 1 ulazni argument');
end
if nargout ~= 1
    error('Funkcija ima 1 izlazni argument');
end
maxx = T(1).x;
minx = T(1).x;
maxy = T(1).y;
miny = T(1).y;
for i = 1:sLen
    if T(i).x < minx
        minx = T(i).x;
    elseif T(i).x > maxx
        maxx = T(i).x;
    end
    if T(i).y < miny
        miny = T(i).y;
    elseif T(i).y > maxy
        maxy = T(i).y;
    end
end
fprintf("Gornja lijeva tacka: (%d,%d)\n",minx,maxy);
fprintf("Donja desna tacka: (%d,%d)\n",maxx,miny);
fprintf("Tacke u pravougaoniku: ");
for i = 1:sLen
   if T(i).x<maxx && T(i).x>minx && T(i).y<maxy && T(i).y>miny
      fprintf("%c",T(i).oznaka); 
   end
end
fprintf("\nTacke na rubu pravougaonika: ");
for i = 1:sLen
   if ((T(i).x == maxx || T(i).x == minx) && (T(i).y ~= miny && T(i).y ~= maxy))...
        || ((T(i).y == maxy || T(i).y == miny) && (T(i).x ~= minx && T(i).x ~= maxx))
   fprintf("%c",T(i).oznaka); 
   end
end
X = [minx maxx maxx minx minx];
Y = [miny miny maxy maxy miny];
plot(X,Y,'r--','LineWidth',2);
grid on;
hold on;
axis([0 6 0 6]);
fprintf("\nTacke tjemena pravougaonika: ");
for i = 1:sLen
   if T(i).x == maxx && T(i).y == maxy || T(i).x == maxx && T(i).y == miny...
           || T(i).x == minx && T(i).y == maxy || T(i).x == minx && T(i).y == miny
      fprintf("%c",T(i).oznaka); 
   end
   plot(T(i).x,T(i).y,'bo','MarkerSize',7);
   hold on;
end
fprintf("\n");
% ovo je uradjeno gore cisto da ne bi pravili dodatnu petlju
a = maxx - minx;
b = maxy - miny;
dijagonala = sqrt(a^2+b^2);
obim = 2*a+2*b;
povrsina = a*b;
res = cell(1,3);
res = {obim povrsina dijagonala};
end