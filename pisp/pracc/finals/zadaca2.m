clear all
close all
clc



solve3();

function solve3()
    
    S = struct('x',{4,3,2,1,9,5},'y',{1,2,3,2,9,8},'oznaka',{'A','B','C','D','E','F'});
    
    c = struktura(S);

    function chelija = struktura(S)
       if nargin~=1
           error('Bad input');
       end
       if nargout~=1
           error('Bad output');
       end
       n = length(S);
       if n<5
           error('Wrong size');
       end
       tx=S(1).x;
       ty=S(1).y;
       d=sqrt(tx^2+ty^2);
       for i = 2:n
          x = S(i).x;
          y = S(i).y;
          D = sqrt(x^2+y^2);
          if D>d
              d = D;
          end
       end
       theta = 0:0.01:2*pi;
       x = d*cos(theta);
       y = d*sin(theta);
       plot(x,y);
       hold on; grid on;
       tx = [S(:).x];
       ty = [S(:).y];
       plot(tx,ty,'bo');
       chelija = 0;
        
    end
end

function solve2()
    
    S = struct('x',{4,3,2,1,9,5},'y',{1,2,3,2,9,8},'oznaka',{'A','B','C','D','E','F'});
    
    c = struktura(S);
    disp(c);

    function chelija = struktura(S)
       if nargin~=1
           error('Bad input');
       end
       if nargout~=1
           error('Bad output');
       end
       n = length(S);
       if n<5
           error('Wrong size');
       end
       maxx = S(1).x;
       maxy = S(1).y;
       miny = S(1).y;
       minx = S(1).x;
       for i = 2:n
           if S(i).x > maxx
               maxx = S(i).x;
           elseif S(i).x < minx
               minx = S(i).x;
           end
           if S(i).y > maxy
               maxy = S(i).y;
           elseif S(i).y < miny
               miny = S(i).y;
           end
       end
       a = maxx-minx;
       b = maxy-miny;
       if a>=b
           s = a;
           diff = a-b;
           maxy = maxy+diff;
       else
           s = b;
           diff = b-a;
           maxx = maxx+diff;
       end
       fprintf("Gornja lijeva tacka: (%d,%d)\n",minx,maxy);
       fprintf("Donja desna tacka: (%d,%d)\n",maxx,miny);
       fprintf("Tacke u pravougaoniku: ");
       for i = 1:n
           if S(i).x<maxx && S(i).x>minx && S(i).y<maxy && S(i).y>miny
               fprintf("%c",S(i).oznaka);
           end
       end
       fprintf("\nTacke na rubu pravougaonika: ");
       for i = 1:n
          x = S(i).x;
          y = S(i).y;
          if (x==maxx||x==minx) && (y~=miny && y~=maxy)...
                  ||(y==maxy || y==miny) && (x~=minx && x~=maxx)
             fprintf("%c",S(i).oznaka); 
          end
       end
       fprintf("\nTacke tjemena pravougaonika: ");
       for i = 1:n
          x = S(i).x;
          y = S(i).y;
          if(x==maxx || x==minx) && (y==miny || y==maxy)...
                  ||(y==maxy || y==miny) && (x==minx || x==maxx)
                fprintf("%c",S(i).oznaka);
          end
       end
      
       chelija{1,1} = 4*s;
       chelija{1,2} = s*s;
       chelija{1,3} = sqrt(a^2+a^2);
       X = [minx maxx maxx minx minx];
       Y = [miny miny maxy maxy miny];
       plot(X,Y,'r--');
       grid on; hold on;
       axis([0 10 0 10]);
       tx = [S(:).x];
       ty = [S(:).y];
       plot(tx,ty,'bo','MarkerSize',8);
    end
end

function bar()
f1 = figure('Tag','figure1','Name','Aproksimacija','menubar','none');
a = axes('Units','normalized','Position',[0.1 0.1 0.8 0.7],'Parent',f1);
uicontrol('Style','text','String','Polinom i interval','Units','normalized',...
    'Position',[0.1 0.82 0.2 0.05]);
uicontrol('Style','text','String','APROKSIMACIJA PODATAKA SUMA','Units','normalized',...
    'Position',[0.32 0.92 0.4 0.06]);
polinom = uicontrol('Style','edit','Units','normalized','Position',[0.32 0.82 0.2 0.06]);
interval = uicontrol('Style','edit','Units','normalized','Position',[0.54 0.82 0.2 0.06]);
choice = uicontrol('Style','popup','String','|+|*|o|x','Units','normalized','Position',[0.76 0.82 0.15 0.06],...
    'Callback','braaaateeee');
end

function foo()
    function math(znak)
       if znak == 'a'
        syms x;
          a = 2+log(x);
          b = 2*sqrt(x);
          f = a/b;
          F = int(f,-4,4);
          pretty(F);
          dy = dsolve('2*D3y-3*Dy=sin(3*x)','y(0)=1,Dy(0)=1','x');
          pretty(dy);
       elseif znak == 'b'
          syms x;
           a = log(x)+2;
           b = sqrt(x);
           f = a/b;
           ezplot(f,[-1 10 -4 4]);
           grid on; hold on;
           nula = solve(a);
           plot(nula,0,'rs'); hold on;
           ha = limit(f,inf);
           va = solve(x==0);
           limit(f,x,va,'right');
           plot([-1 10],[ha ha],'g'); hold on;
           plot([va va],[-4 4],'g'); hold on;
           df = diff(f);
           e = solve(df);
           plot(e,subs(f,e),'ko');
       else
           R = [110 2 0;
               100 3 0;
               90 1 2;
               80 2 3;
               70 3 4];
           I = [2 0 4];
           V = [12 1 0];
           
           kolo.R = R;
           kolo.I = I;
           kolo.V = V;
           kolo.simb = 0;
           
           [g b c d a] = amatrica(kolo);
           z = zmatrica(kolo);
           x = a\z;
           
           disp(x(3)-x(2));
           disp(x(5));
       end
    end
end



function solve1()

P = [3 5 -6 3];
Q = [5 -2 0];

polinomi(P,Q);
%disp(R);
    
    function r = polinomi(P,Q)
        if nargin~=[1 2]
            error('Input bad');
        end
        if nargin==1 && nargout ~=1
            error('Bad output');
        end
        if nargin == 2 && nargout ~=0
            error('Bad output');
        end
        if nargin == 1
            x = -8:0.4:8;
            y = polyval(P,x);
            y = y + randn(size(y));
            plot(x,y,'gs');
            grid on; hold on;
            redPolinoma = length(P)-1;
            pn = polyfit(x,y,redPolinoma);
            plot(x,polyval(pn,x),'r'); hold on;
            r = roots(P);
            r = r(find(imag(r)==0));
            plot(r,0,'ko','MarkerSize',12);
            title(['Aproksimacija polinomom ' num2str(redPolinoma) '. reda']);
        end
        
        if nargin == 2
            z=0;d=0;p=0;k=0;o=0;
            L1 = length(P);
            L2 = length(Q);
            p = conv(P,Q);
            if L1 >= L2
                [k,o] = deconv(Q,P);
                Q = [zeros(1,L1-L2) Q];
                r = P-Q;
            else
                [k,o] = deconv(Q,P);
                P = [zeros(1,L2-L1) P];
                r = Q-P;
            end
            z = P+Q
            disp(r)
            disp(p)
            disp(k)
            disp(o)
        end
    end
end