clear all
close all
clc

math('c');

%drugi zadatak
function math(znak)
    if nargout~=0
        error('Funkcija ne vraca nista');
    end
    if nargin~=1
        error('Funkcija ima samo 1 ulazni argument');
    end
    if znak ~= ['a' 'b' 'c']
        error('Pogresan unos');
    end
    if znak == 'a'
        syms x;
       brojnik = 2 + log(x);
       nazivnik = 2 * sqrt(x);
       fun = brojnik/nazivnik;
       f = int(fun,-4,4);
       pretty(f);
       y = dsolve('2*D3y - 3*Dy = sin(3*x)','y(0)=1','Dy(0)=1','x');
       pretty(y);
    elseif znak == 'b'
        syms x;
        brojnik = log(x)+2;
        nazivnik = sqrt(x);
        f = brojnik/nazivnik;
        fig = figure;
        ezplot(f,[-1 10 -4 4],fig);
        hold on;
        
        nule = solve(brojnik);
        plot(nule,0,'rs'); 
        hold on;
        
        ha = limit(f,inf);
        va = solve(x==0);
        limit(f,x,va,'right');
        plot([-1 10],[ha ha],'g'); hold on;
        plot([va va],[-4 4],'g'); hold on;
        
        f1 = diff(f);
        f1 = simplify(f1);
        x0 = solve(f1);
        y0 = subs(f,{x},x0);
        plot(x0,y0,'ko');
    else
        R = [110 2 0;
             100 3 0;
             90 1 2;
             80 2 3;
             70 3 4];
         V = [12 1 0];
         I = [2 0 4];
         kolo.R = R;
         kolo.V = V;
         kolo.I = I;
         kolo.simb = 0;
         
         [G,B,C,D,A] = amatrica(kolo);
         Z = zmatrica(kolo);
         x = A\Z;
         disp(['Vrijednost napona na krajevima R4 = ' num2str(x(3)-x(2)) 'V']);
         disp(['Vrijednost struje kroz V1 = ' num2str(x(5)) 'A']);
    end
end