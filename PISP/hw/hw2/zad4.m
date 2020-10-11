clear all
close all
clc

%zadatak4
f1 = figure('Tag','figure1','menubar','none');
grafik = axes('Position',[0.1 0.1 0.8 0.7],'parent',f1);

izbor = uicontrol('Style','popup','Units','normalized',...
    'Position',[0.74 0.82 0.17 0.05],'String',' |*|+|o|x',...
    'parent',f1,'Callback','plotting');

decor = uicontrol('Style','text','Units','normalized',...
    'Position',[0.07 0.82 0.23 0.05],'String','Polinom i interval',...
    'parent',f1,'FontSize',12);

naslov = uicontrol('Style','text','Units','normalized',...
    'parent',f1,'FontSize',12,'String','APROKSIMACIJA PODATAKA SUMOM',...
    'Position',[0.1 0.9 0.8 0.05]);

unos1 = uicontrol('Style','edit','Units','normalized',...
    'Position',[0.3 0.82 0.2 0.05],'parent',f1);

unos2 = uicontrol('Style','edit','Units','normalized',...
    'Position',[0.52 0.82 0.2 0.05],'parent',f1);


