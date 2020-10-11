clear all
close all
clc

syms x t r m n d;
a = 3*x^3-x^2-3*x+1;
b = x^2+4*x+4;
f = a/b;
nule = solve(a);
prekid = solve(b);


f = t.^2.*sin(2*t);
ezplot(f);
int(f,-1,4);

close all
r = dsolve('2*D2y+3*Dy+4*y=cos(5*x)','y(0)=0','Dy(0)=1');
ezplot(r);

% close all
% S = solve(m^2+d^2-5==0,-2*m+d-2==0);
% ezplot('m^2+d^2-5=0');
% hold on;
% ezplot('-2*m+d-2=0');
% plot(S.x,S.y,'yr');

clear all
close all
clc

syms x;
y = 2*x^3+3*x^2-36*x-10;

%prvi izvod
y1 = diff(y);
x0 = solve(y1);
y0 = subs(y,{x},x0);

%drugi izvod
y2 = diff(y1);
s = subs(y2,{x},x0);

%nadji min i max
a = find(s<0);
b = find(s>0);
max = [x0(a)',y0(a)'];
min = [x0(b)',y0(b)'];

ezplot(y);
hold on;
plot(x0,y0,'ro');

clear all
close all
clc

syms x;
f = log(x)/x;
fig = figure;
ezplot(f,[-1,6,-6,1],fig);
grid on;
hold on;


nula = solve(log(x));
plot(nula,0,'ko');

%asimptote
ha = limit(f,inf);
va = solve(x==0);
limit(f,x,va,'right');
plot([-1 6],[ha ha],'r');
plot([va va],[-6 1],'g');

%ekstrem
f1 = diff(f);
f1 = simplify(f1);
T = solve(f1==0);
plot(double(T),double(subs(f,T)),'ks');

grid on;

clear all
close all
clc

%zad4

x = sym('x','positive');
y = sym('y','positive');
f = 8/x+x/y+y;

fx = diff(f,x);
fy = diff(f,y);
[a,b] = solve(fx,fy);

fxx = diff(fx,x);
fyy = diff(fy,y);
fxy = diff(fx,y);

D = fxx*fyy-fxy*fxy;
eks = subs(D,[x,y],[double(a),double(b)]);
A = subs(fxx,[x,y],[double(a),double(b)]);
ekstrem = subs(f,[x,y],[double(a),double(b)]);

if eks<0
    disp('Nema ekstrema');
else
    if A>0
        disp('Minimum: ');
        [a,b],ekstrem
    else disp('Maksimum: ');
        [a,b],ekstrem
    end
end

