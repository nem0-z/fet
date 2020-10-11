clear all
close all
clc

%zadatak 1
%figure
%plot(0:pi/8:4*pi,sin(0:pi/8:4*pi),'rs--',...
%    'LineWidth',2,'MarkerFaceColor','k');

%zadatak 2
%x = linspace(-5,5,500);
%y = x.*exp(-x.^2);
%plot(x,y);
%title('Grafik f-je');
%xlabel('x-osa');
%ylabel('y-osa');
%grid on
%axis tight

%zadatak 3
%x = linspace(-5,5,500);
%y = x.*exp(-x.^2);
%figure(1)
%plot(x,y);
%axis([-2 2 -0.5 0.5]);
%figure(2)
%bar(x,y);

%zadatak 4
%t = 1:5;
%s1 = [60 72 48 84 61];
%s2 = [83 91 64 48 52];
%s3 = [10 20 30 40 50];
%plot(t,s1,t,s2,t,s3);
%legend('Student1','Student2','Student3');

%drugi nacin
%plot(s1) %proslijedjeni argument je y osa, a x osa ce bit popunjena 
%indeksima vektora s1 (ovo se poklapalo kod nas jer su nam i indeksi 1:5)
%ne praktikuj ako ne moras nije ti se bas svidjelo
%hold on
%plot(s2)
%grid on

%treci nacin
%subplot(1,2,1)
%plot(t,s1)
%subplot(1,2,2)
%plot(t,s2)
%grid on i sta vec sve ide dalje naslovi gridovi blabla

%zadatak 5
%beze

%zadatak 7
%A = [1 2 3;4 5 6;7 8 9];
%imagesc(A);
%colormap(jet);
%colorbar

%check surf fun

%zadatak 8
%x = -pi:0.1:pi;
%y = -pi:0.1:pi;
%[X,Y]=meshgrid(x,y);
%Z = sin(X).*cos(Y);
%surf(X,Y,Z);
%title('3D Grafik');
%shading interp
%colormap jet

%zadatak 12
%check meshgrid fun bogati

[X Y] = meshgrid(linspace(-2,2,20), linspace(-2,2,20));
Z = X+i*Y;
f = abs(1./(Z.^4+1));
%fuck
