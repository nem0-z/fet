clear all
close all
clc

E = [1 3 3; 1 2 6;8 3 1]

%a

% A = [2:5;9:-2:3;2.^[2:5];3.^[3:-1:0]];

%b
% C = fliplr(diag(diag(fliplr(B))));

%c
% X = prod(diag(fliplr(D),1))

%d
X = find(mod(E,2) == 0);
Y = E(find(mod(find(mod(E,2) == 0),2)));



%e
%Z = diag(rot90(E,-1).*rot90(E))








