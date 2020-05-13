clear all
close all
clc

P = [3 5 -6];
Q = [5 -2 0 4];
x = polinomi(Q);

function r = polinomi(P1,P2)
    if nargin~=[1 2]
        error('Funkcija ima 1/2 ulazna arg.');
    end
    if nargout ~=[0 1]
        error('Funkcija ima 0/1 izlaznu vrijednost.');
    end
    
    if nargin==1
        s1 = size(P1);
        if s1(1)>1
            error('Primam samo polinome');
        end
        x = -8:0.4:8;
        y = polyval(P1,x);
        y = y + randn(size(y));
        plot(x,y,'gs');
        hold on;
        grid on;
        red = length(P1)-1;
        pfit = polyfit(x,y,red);
        title(['Aproksimacija polinomom ' int2str(red) '.reda ']);
        xlabel('x-osa');
        ylabel('y-osa');
        plot(x,polyval(pfit,x),'r');
        r = roots(P1);
        plot(r(find(imag(r)==0)),0,'ko','MarkerSize',12);
    else
        s2 = size(P2);
        if s2(1)>1
            error('Primam samo polinome');
        end
        proizvod = conv(P1,P2);   
        
        red1 = length(P1)-1;
        red2 = length(P2)-1;
        
        if red1<red2
            [kolicnik,ostatak] = deconv(P2,P1);
            diff = red2-red1;
            P1 = [zeros(diff),P1];
            razlika = P2-P1;
        else 
            [kolicnik,ostatak] = deconv(P1,P2);
            diff = red1-red2;
            P2 = [zeros(diff),P2];
            razlika = P1-P2; 
        end
        disp(['Zbir = ' num2str(P1+P2)]);
        disp(['Razlika = ' num2str(razlika)]);
        disp(['Proizvod = ' num2str(proizvod)]);
        disp(['Kolicnik = ' num2str(kolicnik)]);
        disp(['Ostatak = ' num2str(ostatak)]);
        r = 'Vracam nesto';
         
   end
end

