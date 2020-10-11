clear all
close all
clc

load varEx
m = round(a.*b)

[minVal,minInd] = min(b);
[maxVal,maxInd] = max(b);

ind = find(m<=500 & m>250);

x = linspace(10,20,5)
%x(16) = NaN; %od kraja do 16.elementa ce sve 0 stavit

p = linspace(0,2*pi,1000);
y = sin(p);
y(55);
y(100:110);
i1 = find(y>-0.001 & y<0.001);
i2 = min(y);
i3 = max(y);

mat = zeros(3,100);
w = linspace(0,10,100);
mat(1,:) = cos(w);
mat(2,:) = log((w+2).^2);
mat(3,:) = rand(1,100);
matSum = sum(mat,2); %ne kontam

a = 'zlatan';
if a==flip(a)
    disp('Palindrom')
else disp('Nije palindrom')
end

A = [1 6 7 8 2; 1 5 6 7 3; 1 8 9 2 3;0 5 2 9 9];
r = [1 1 2 2 3 3 4 4 ];
k = [1 2 2 3 3 4 4 5 ];
indeksi = sub2ind(size(A), r, k);
res = A(indeksi);


