clear all
close all
clc


T = struct('Oznaka',{'A','B','C','D','E','F'},...
            'x',{-1,3,1,0,5,-2},'y',{2,3,4,-2,6,0});
        
c = struktura(T)

%treci zadatak
function rez = struktura(S)
    if nargin ~= 1
        error('Funkcija ima samo 1 ulazni argument');
    end
    if nargout ~= 1
        error('Funkcija ima samo 1 izlazni argument');
    end
    if length(S)<5
        error('Radim sa minimalno 5 tacaka');
    end
    minx = S(1).x;
    maxx = S(1).x;
    miny = S(1).y;
    maxy = S(1).y;
    for i = 1 : length(S)
       if S(i).x < minx
           minx = S(i).x;
       elseif S(i).x > maxx
           maxx = S(i).x;
       end
       if S(i).y < miny
           miny = S(i).y;
       elseif S(i).y > maxy
           maxy = S(i).y;
       end
    end
    fprintf("Gornja lijeva tacka: (%d,%d)\n",minx,maxy);
    fprintf("Donja desna tacka: (%d,%d)\n",maxx,miny);
    fprintf("Tacke u pravougaoniku: ");
    for i = 1 : length(S)
        if S(i).x < maxx && S(i).x > minx && S(i).y < maxy && S(i).y > miny
            fprintf("%c",S(i).Oznaka);
        end
    end
    fprintf("\nTacke na rubu pravougaonika: ");
    for i = 1 : length(S)
        if (S(i).x == minx && S(i).y ~= miny && S(i).y ~= maxy)...
                || (S(i).x == maxx && S(i).y ~= miny && S(i).y ~= maxy)...
                || (S(i).y == miny && S(i).x ~= minx && S(i).x ~= maxx)...
                || (S(i).y == maxy && S(i).x ~= minx && S(i).x ~= maxx)
           fprintf("%c",S(i).Oznaka);
        end
    end
    fprintf("\nTacke tjemena pravougaonika: ");
    for i = 1 : length(S)
        if S(i).x == minx && (S(i).y == miny || S(i).y == maxy)...
                || S(i).x == maxx && (S(i).y == miny || S(i).y == maxy)
           fprintf("%c",S(i).Oznaka);
        end
    end
    fprintf("\n");
    X = [minx maxx maxx minx minx];
    Y = [miny miny maxy maxy miny];
    plot(X,Y,'r--','LineWidth',2);
    hold on; grid on;
    axis([0 6 0 6]);
    for i = 1:length(S)
       plot(S(i).x,S(i).y,'bo'); 
       hold on;
    end
    a = maxx - minx;
    b = maxy - miny;
    povrsina = a*b;
    obim = 2*a + 2*b;
    dijagonala = sqrt(a^2 + b^2);
    rez = cell(1,3);
    rez = {obim,povrsina,dijagonala};
end