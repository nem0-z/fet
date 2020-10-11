%zadaci za samostalan rad AV 2 I guess
clear all
close all
clc

m = 2:4:22;
n = linspace(5,20,6);
t = m([2 4]);
s = n([1,3:5]);
a = [m;n;m];
a(2,:);
a(:,2:5);
a(3,3) = 55;

b = [1 4 7;9 2 6;3 1 4];
b(5);
b(end);
b(2,end);
b([1 2],[2 3]);

c = [1 2 3;4 5 6;7 8 9];
fliplr(c);
flipud(c);
diag(c,1);
diag(c,-2);
diag(fliplr(c)); %pogledaj size(ans) - spremi ga kao vektor kolonu hmm

