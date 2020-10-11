%Uspjeh na ispitima
clear all
close all
clc

rez = rand(1,3)*100;
ispiti = [0.2 0.3 0.5];
ukupno = rez*ispiti';
str1 = ['Bodovi ostvareni po ispitima: '];
str2 = ['Ukupan uspjeh ovog studenta je '];
disp(str1),rez
disp(str2),ukupno

