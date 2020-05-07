clear all
close all
clc


p = [1 2 -13 -14 24];
r = roots(p);
s = poly(r);
x = -5:0.1:5;
plot(x,polyval(s,x));

roots = [2 -1 3];
P = poly(roots);
x = [1 5 -2];
y = polyval(P,x);

X = [-1 0 2];
Y = [0 -1 3];
approx = polyfit(X,Y,2);
plot(X,Y,'ko');
hold on;
x = -3:0.1:3;
plot(x,polyval(approx,x),'r--');

clear all
close all

vec = -4:0.1:4;
y = vec.^2;
y = y + randn(size(vec));
plot(vec,y,'.');
hold on;
myPoly = polyfit(vec,y,2);
plot(vec,polyval(myPoly,vec),'r');

clear all
close all

%samostalan rad

%zad2
p1 = [1 0 -3 4];
p2Roots = [1 -2 3];

p1Roots = roots(p1);
x = -4:0.1:4;
p2 = poly(p2Roots);
P = conv(p1,p2);
y = polyval(P,x);

y = y + randn(size(y));
p2 = polyfit(x,y,2);
p3 = polyfit(x,y,3);

figure(1)
plot(x,y,'ko'); hold on;
plot(x,polyval(p2,x),'y--');

figure(2)
plot(x,y,'gr'); hold on;
plot(x,polyval(p3,x),'r');

clear all
close all
clc

%zad3

P1 = [2 5 0 -4];
r2 = [-1 2 6];
P2 = poly(r2);
x = -5:0.1:5;
P = conv(P1,P2);
y = polyval(P,x);
y = y + randn(size(y));
plot(x,y,'d');
hold on;
y2 = polyfit(x,y,2);
y3 = polyfit(x,y,3);
plot(x,polyval(y2,x),'r');
hold on;
plot(x,polyval(y3,x),'b--');
grid on;

clear all
close all
clc

%zad4

% x = input('Unesi char: ');
% z2('b');

% function z2(char)
%     if nargin ~=1
%         error('Error');
%     end
%     if nargout ~=0
%         error('Error');
%     end
%     if char ~=['a' 'b']
%         error('Bad input');
%     end
%     
%     if char=='a'
%         
%     x = -pi:0.1:pi;
%     y = x;
%     [X,Y] = meshgrid(x,y);
%     Z = 3*sin(X).*cos(Y);
%     surf(X,Y,Z);
%     shading interp;
%     colormap gray;
%     
%     else
%     %ne moramo provjeravati jer moze samo b biti
%     P = [2 3 0 -6];
%     x = -4:0.1:4;
%     polinom = polyval(P,x);
%     polinom = polinom + randn(size(polinom));
%     plot(x,polinom,'d');
%     pol2 = polyfit(x,polinom,2);
%     hold on;
%     plot(x,polyval(pol2,x));
%     grid on;
%     end    
% end

clear all
close all
clc

%zad5

P = [2 4 0 -3];
X = -4:0.1:4;
[a,b,c,d,e] = polinomi(P,X);

function [N,red,brreda,znak,brznaka]= polinomi(P,X)
    y = polyval(P,X);
    y = y + randn(size(y));
    N = 0; n = 1; n2 = 0; n3 = 0; z1 = 0; z2 = 0; z3 = 0;
    while(n>0)
        n = input('Unesite red polinoma: ');
        if n~=[2 3]
            disp('Pogresan red polinoma');
            break;
        end
        z = input('Unesite oznaku markera: ');
        if z~=['x' '+' 'o']
            disp('Pogresna oznaka markera');
            break;
        end
        if n == 2 
            n2 = n2 + 1;
        else 
            n3 = n3 + 1;
        end
        if z == 'x'
            z1 = z1 + 1;
        elseif z== '+' 
            z2 = z2 + 1;
        else
            z3 = z3 + 1;
        end
        pn = polyfit(X,y,n);
        figure(N+1);
        plot(X,y,z);
        grid on;
        hold on;
        plot(X,polyval(pn,X));
        N = N + 1;
        red = [0 n2 n3];
        [brreda,red] = max(red);
        znak = [z1 z2 z3];
        [brznaka,ind] = max(znak);
        if ind == 1
            znak = 'x';
        elseif ind == 2 
            znak = '+';
        else
            znak = 'o';
        end
    end
end