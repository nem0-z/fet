clear all
close all
clc

% Vjerovatnoca 1 = p, binarni izvor
% a) p = 0.1
% Od 0-0.1 se generise 1, a 0.1-1 se generise 0
% b) p = 0.5

x = rand(1,100);
pa = 0.1;
pb = 0.5;
x1 = zeros(1,100);
x2 = zeros(1,100);

for i=1:length(x)
    if x(i) < pa
        x1(i) = 1;
    else
        x1(i) = 0;
    end
    if x(i) < pb
        x2(i) = 1;
    else
        x2(i) = 0;
    end
end

subplot(2,1,1)
stem(1:100,x1)

subplot(2,1,2)
stem(1:100,x2)

