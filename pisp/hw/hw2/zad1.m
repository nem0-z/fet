clear all
close all
clc


P = [3 5 -6];
Q = [5 -2 0 4];
S = [1 0 0];
J = [1 2 2 3];
polinomi(P);

%prvi zadatak
function rez = polinomi(P1,P2)
    if nargin ~=[1 2]
        error('Funkcija ima 1 ili 2 ulazna argumenta');
    end
    if nargout ~=[0 1]
        error('Funkcija ima 0 ili 1 izlaz');
    end
    s1 = size(P1);
    if nargin == 1
        if s1(1)>1
            error('Ja radim samo sa polinomima');
        end
     x = -8:0.4:8;
     y = polyval(P1,x);
     y = y + randn(size(y));
     plot(x,y,'gs');
     grid on; hold on;
     p = polyfit(x,y,length(P1)-1);
     plot(x,polyval(p,x),'r');
     hold on;
     rez = roots(P1);
     rez = rez(find(imag(rez)==0));
     plot(rez,0,'ko','MarkerSize',12);
     title(['Aproksimacija polinomom ' num2str(length(P1)-1) '.reda']);
     xlabel('x-osa');
     ylabel('y-osa');
    elseif nargin == 2
        s2 = size(P2);
        if s1(1)>1 || s2(1)>1
            error('Ja radim samo sa polinomima');
        end
        proizvod = conv(P1,P2);
        [kolicnik,ostatak] = deconv(P2,P1);
        red1 = length(P1)-1;
        red2 = length(P2)-1;
        if red1 == red2
            razlika = P1 - P2;
        elseif red1 < red2
           diff = red2-red1; 
           P1 = [zeros(1,diff) P1];
           razlika = P2 - P1;
        elseif red2 < red1
            diff = red1-red2;
            P2 = [zeros(1,diff) P2];
            razlika = P1 - P2;
        end
        zbir = P1 + P2;
        disp(['Zbir = ' num2str(zbir)]);
        disp(['Razlika = ' num2str(razlika)]);
        disp(['Proizvod = ' num2str(proizvod)]);
        disp(['Kolicnik = ' num2str(kolicnik)]);
        disp(['Ostatak = ' num2str(ostatak)]);
        rez = NaN;
    end
end