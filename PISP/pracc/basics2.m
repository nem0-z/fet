clear all
close all
clc

a = 10;
b = a + 10;
c = a - 25;
d = a * 4.5;
f = a / 256;
f1 = round(a/256);

%zadatak sa coding game hahaha
%nadji najblizi stepen takav da 2^stepen <= input
%base = 2;
%limit = input('');
%res = round(log2(limit))

x = 10*pi;
m = exp(i*x);
n = cos(x) + i*sin(x);
true = m-n;
if true==0
    disp('Tacan identitet')
else if true>1
        disp('Glup si')
    else disp('Glup si itekako')
    end
end

secPerDay = 60*60*24;
tau = 1.5*secPerDay;
endOfClass = 5*secPerDay;
%knowledge = 1-e^(i-t/tau)
k = 1 - exp(-endOfClass/tau);
disp(['Na kraju PISPa ja cu znati ' num2str(100*k) ' % MATLABA!'])

r = [1+3.6i 2+2.5i 3+pi*i];
transpose(r);
r';
r.';
% ' uz transponovanje radi i konjugovanje
% .' radi samo transponovanje

%provjeri ako je iracionalna matrica, da ne radi konjugovanje
if isreal(r)==0
    r.';
else r';
end

r1 = [5 6 7 8];
r2 = [1 2 3 4];
p1 = sum(r1) + sum(r2);
p2 = prod(r1);
p3 = r1+r2;
p4 = r1-r2;
p5 = r1.*r2;
p6 = r1*r2';
test = sum(p5) - p6; % ;)

row = [1 2 3];
column = [2; 3; 4;];
matrix = row .* column;


s = 100*rand(5);
s = 100*rand(1,5);
s = 100*rand(5,1);

w = linspace(1,10);
w1 = linspace(0,10,5);
w2 = 0:2:10;

vec = linspace(0,10,1000);
vecFun = exp(-vec).*cos(vec);

h1 = [13 5 9 10];
h2 = [15 7 8 9];
h3 = [h1(1) h1(2);h2(3) h2(4)];
h1(2:3);
h1(end:-1:1);
fliplr(h1);
flip(h1);
h = h1 .* h2'
h(14); %isto sto i h(2,4)

%let's extract
eh = h([1 2],end:-1:1);
eh1 = h([1 3],[2 4]);
h([2,3],:) = zeros;
h([2,3],:) = NaN;




