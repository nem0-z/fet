clear all
close all
clc


cellArr = {'sinisa',[1 2 3]; eye(5),4};
cellArr(3);
cellArr{3} = randn(3); 
%() -> pristup informacijama o tipu podatka na tom spotu
%{} -> dereferenciraj to na tom spotu

B{1,2} = 'test';
B{2,1} = 245;

% C = cat(2,cellArr,B);
% 
% % s = struct([]);
% s.ime = 'sinisa';
% s.smjer = 'tk';
% s.zanimanje = 'brat';
% s.ocjene = 10*ones(1,6);
% 
% fet = struct('profesori',['amer ','pjano ','toka '],...
%     'smjerovi',['ri','tk'],'ulica',87941,'matrica',rand(5));
% 
% sentGen();
% 
% function sentGen
% c = cell(2,3);
%    c{1,1} = 'amer';c{1,2} = 'pjano';c{1,3}= 'toka';
%    c{2,1} = 'ljep';c{2,2} = 'brat';c{2,3}='tata svima';
%    r1 = ceil(rand*3);r2 = ceil(rand*3);
%    disp([c{1,r1} ' ' c{2,r2}]);
% end

a = sym('1/3');
b = sym('2/3');
mat = sym([1 2;3 4]);

x = a + b;
expand(a+x*b*b*b);
factor(ans);
pretty(ans);

clear all
close all
clc

syms x y z;
[x,y,z] = solve(2*x-3*y+4*z==5,y+4*z+x==10,-2*z+3*x+4*y==0,x,y,z)

syms t;
f = t*exp(-t);
F = int(f);
pretty(F);
