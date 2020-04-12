%zad2.m
clear all
close all
clc

x = input('Unesite vektor red-> ');

l = length(x);
myMax = max(x);

subm = round(10*rand(l)+5);
subm = subm - diag(diag(subm)) + diag(x);
subm = fliplr(subm);

A = myMax.*ones(l+2);
A(2:end-1,2:end-1) = subm