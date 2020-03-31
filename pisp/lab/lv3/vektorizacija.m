%skripta vektorizacija.m
%kreira i ispisuje matricu A 5x5 random brojevima E[5,15]
% a)koliko elemenata A je >10
% b)drugi red m-e A
% c)zamijeni trecu kolonu sa vektorom 5 vrijednosti [5,15]
% d)izbrisi treci red i drugu kolonu
% e)pronadji indekse elemenata manjih od 10
clear all
close all
clc

A = 10*rand(5)+5
greaterThan10 = length(find(A>10));
secondRow = A(2,:);
A(:,3) = linspace(5,15,5);
A(3,:) = []; 
A(:,2) = [];
lessThan10Index = find(A<10);
