clear all
close all
clc

var = 3.5;
mystr = 'Moje ime je Sinisa';
disp(mystr);
fprintf("%s\n%s\n%s\n",mystr,mystr,mystr);

myRow = [1 2 3];
myColumn = [1; 2; 3];

myMatrix = myRow .* myColumn;

%length vraca skalar
%size vraca "matricu"

save varEx myRow myColumn var
clear myRow myColumn var
load varEx %ucitava sve varijable iz varEx
load varEx myRow myColumn %ocigledno sta radi

time = datestr(clock);
desc = 'Ja cu nauciti MATLAB: ';
fprintf("%s%s\n",desc,time);
disp(['Ja cu nauciti MATLAB: ', time]);
%hehe upravo
%ah da btw disp automatski baca newline

%inputTest = input('Unesi varijablu: ');
%inputTest = input('');

str1 = 'Pozdravio ';
str2 = 'te ';
str3 = 'Sinisa';
magic = [str1 str2 str3];
disp(magic)
%konkatenacija xDDD XDDD Xddd xddd oo Amra
%check size of each str and total-you will be surprised

strBroj = num2str(45.5234)
brojStr = str2num('45.5234')






