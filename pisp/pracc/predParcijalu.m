clear all
close all
clc

x = [1 2 3 4];

n = length(x);

C = diag(ones(1,n));
c1 = diag(2*ones(1,n-1),1);
c2 = diag(2*ones(1,n-1),-1);
C = C+c1+c2;
c1 = diag(3*ones(1,n-2),2);
c2 = diag(3*ones(1,n-2),-2);
C = C+c1+c2;
c1 = diag(4*ones(1,n-3),3);
c2 = diag(4*ones(1,n-3),-3);
C = C+c1+c2;

