clear all
close all
clc

math('c');

function math(znak)
if nargin~=1
    error('Funkcija ima samo 1 ulazni argument');
end
if nargout~=0
    error('Funkcija nema izlaznih argumenata');
end
if(znak ~= 'a' && znak~= 'b' && znak~='c')
    error('Pogresan karakter');
end
if znak == 'a'
    syms x;
    a = 2 + log(x);
    b = 2*sqrt(x);
    f = a/b;
    i = int(f,[-4 4]);
    pretty(i)
    eq = dsolve('2*D3y-3*Dy=sin(3*x)','y(0)=1','Dy(0)=1','x');
    pretty(eq);
elseif znak == 'b'
    syms x;
    a = log(x)+2;
    b = sqrt(x);
    f = a/b;
    fig = figure;
    ezplot(f,[-1 10 -4 4],fig);   
    hold on;
    
    null = solve(a);
    has = limit(f,inf);
    vas = solve(x==0);
    limit(f,x,vas,'right');
    
    plot(null,0,'rs');
    hold on;
    plot([-1 10],[has has],'g');
    hold on;
    plot([vas vas],[-4 4],'g');
    hold on;
    
    fdiff = diff(f);
    x0 = solve(fdiff);
    y0 = subs(f,{x},x0);
    plot(x0,y0,'ko');
    
else
    disp('c');
end

end