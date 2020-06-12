clear all
close all
clc


solve9();

function solve9()

a = [2 3 1; 1 2 4;2 7 9];
b = [2 7 8; 1 2 5;9 2 0];

c = proizvod(a,b);
c;
y = logaritam(100:1000);
x = -2*pi:0.1:2*pi;
d = x;

boris(x,d);

    function boris(x,y)
        [X Y] = meshgrid(x,y);
        f = exp(-.1*(X.^2+Y.^2)).*sin(X.*Y);
        surf(X,Y,real(f));
        shading interp;
        colormap hot;
    end
    function y = logaritam(x)
       if isempty(find(x==0))
       y = log(x);
       plot(x,y,'r.');
       else
           error('eror');
       end
    end
    
    function c = proizvod(a,b)
       s1 = size(a);
       s2 = size(b);
       if s1(1)*s1(2)<9 || s2(1)*s2(2)<9 || s1(2)~=s2(1)
           error('eror');
       end
       a;
       b;
       c = a*b;
       c(1,:) = [];
       c(end,:) = [];
       c(:,1) = [];
       c(:,end) = [];
    end
end

function solve8()
    a = [1 2 3; 4 5 6; 2 5 0];
    b = [4 7 9; 2 4 1; 2 2 4];
%     mat = mnozi(a,b);
%     crtaj('racun',1:50,1:50);

    x = mat(2,3,4);
    x
    function y = mat(n,m,k)
       y = rand(n,m)
       k
       y = y.^k
       
       inds = find(y~=0);
       y==eye(size(y))
       if mod(n,2)==0
           y(n/2,:)=[];
       end
       y(ceil(n/2),:)=[];
    end

    function crtaj(func,x,y)
        subplot(2,1,1)
        z = feval(func,x,y);
        plot(z);
        subplot(2,1,2)
        [X Y] = meshgrid(x,y);
        Z = feval(func,X,Y);
        surf(X,Y,abs(Z));
        axis tight;
        colormap gray;
        legend('povrsina');
    end

    function mat = mnozi(a,b)
        mat = a*b;
        mat = mat';
        rank(mat);
        det(mat);
        mat = sparse(mat);
        spy(mat);
    end
end

function solve7()

    m = mat(4,3);
%     crtaj(1:5,2);
   
    function crtaj(x,coefficient)
       disp('Originalni vektor');
       disp(x);
       y = x + coefficient*randn(size(x));
       disp('Vektor sa sumom');
       disp(y);
       figure(1)
       plot(x,'b');
       figure(2)
       plot(y,'r');
    end
    
    function y = mat(n,m)
       y = diag(ones(1,n).*m);
       y(find(y==0)) = n^3;
       y = transpose(y);
       y = log(y);
       rank(y);
    end
end

function solve6()
    
y = mat(7,2);
% d('sin',-2*pi:0.5:2*pi);


    function y = mat(n,m)
        if m>n/2 || mod(n,2)==0
            error('eror');
        end
        y = zeros(n);
        o = ones(n-2*m);
        y(m+1:n-m,m+1:n-m) = o;
    end

    function d(fun,x)
        y = feval(fun,x);
        plot(x,y,'b');
        grid on; hold on;
        dy = diff(y);
        size(x)
        size(dy)
        plot(x(1:length(dy)),dy,'r--');
    end
end


function solve5()
    x = z3([2 5 5 ;7 4 6; 1 8 22]);
    x

    function out = z3(in)
       s = size(in);
       if s(1)==1 && s(2)==1
          %skalar 
          out = zeros(5);
          for i = 1:3
             out(i:end-i+1,i:end-1+1) = in;
             in = in+2;
          end
       elseif s(1)==1 && s(2)>1
           %vektor
           n = s(2);
           out = round(9*rand(n)+6);
           pom = fliplr(diag(in));
           remove = fliplr(diag(diag(fliplr(out))));
           out = out - remove + pom;
       else
           %matrica
           x1 = prod(diag(fliplr(in),1));
           parni = in(find(mod(in,2)==0));
           x2 = sum(parni);
           x3 = length(find(in>10));
           out = [x1 x2 x3];
       end
    end
end

% syms x y t;
% 
% [Sx Sy] = solve(x^2+y^2-3==0,sqrt(2)*x^3-y==0);
% 
% dy = dsolve('Dy=y+cos(t)','y(0)=-1','t');
% pretty(dy);

function solve4()
    t = struct('a',{3,6},'b',{4,8},'c',{5,10});
    c = NajmanjiTrougao(t);
    c{1,1}
    c{1,2}
    c{1,3}
    
    function c = NajmanjiTrougao(s)
        n = length(s);
        min = s(1);
        minPovrsina = min.a*min.b/2;
        
        for i=1:n
            trougao = s(i);
            if trougao.a^2+trougao.b^2~=trougao.c^2
                error('eror');
            end
            povrsina = trougao.a*trougao.b/2;
            if povrsina < minPovrsina
                minPovrsina = povrsina;
                min = trougao;
            end
        end
       
        c{1,1} = min;
        c{1,2} = min.a*min.b/2;
        if min.a == min.b
            c{1,3} = 1;
        else
            c{1,3} = 0;
        end
    end
end

function solve3()
    P = [1 0 -3 7 -14];
    r = roots(P);
    x = -5:0.1:5;
    plot(x,polyval(P,x));
    grid on;
end

function solve2()

    st = struct('ime',{'Ajla','Soke','Zlatan'},'prezime',{1,2,3},'bodovi',{95,100,65},'ocjena',{6,8,5});
    celija = ProsjekPISP(st);
    celija{1,1}
    celija{1,2}
    celija{1,3}
    function C = ProsjekPISP(S)
        n = length(S);
        sum=0;
        bestStudent = S(1);
        bestBodovi = S(1).bodovi;
        fail = 0;
        for i = 1:n
           if S(i).ocjena == 5
               fail = fail+1;
           end
           sum = sum + S(i).ocjena;
           if S(i).bodovi > bestBodovi
              bestBodovi = S(i).bodovi;
              bestStudent = S(i);
           end
        end
        C{1,1} = sum/n;
        C{1,2} = bestStudent;
        C{1,3} = fail;
    end
end

function solve1()
%     s = fun(3,4,2);
        x = 1:100;
        y = x;
        foo(x,y,'sin(X)+cos(Y)');

    function y = fun(n,m,k)
        y=rand(n,m)
        k
        y=y.^k
    end

    function foo(x,y,func)
       [X,Y] = meshgrid(x,y);
       Z = eval(func);
       fun2 = ['sqrt(' func ')'];
       Z2 = eval(fun2);
       subplot(1,2,1);
       surf(X,Y,abs(Z));
       subplot(1,2,2);
       surf(X,Y,abs(sqrt(Z)));
       colormap hot;
    end
end
