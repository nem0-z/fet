clear all
close all
clc

% [t,y] = ode23(@diffFun,[0 10],10);
% plot(t,y);
% 
% [t,y] = ode45(@simpleEq,[0,10],1);
% plot(t,y);

solve9()

function z = quickEq(x,y)
    z = x.*(y.^2)./(x.^2+y.^2);
end

function solve9()
    
end

function solve8()
    syms x;
    a = log(x);
    b = x;
    f = a/b;
    ezplot(f,[-1 6 -6 1]);
    hold on; grid on;
    nula = solve(a);
    plot(nula,0,'ko'); hold on;
    ha = limit(f,inf);
    va = solve(x==0);
    limit(f,x,va,'right');
    plot([-1 6],[ha ha],'r'); hold on;
    plot([va va],[-6 1],'g'); hold on;
    
    df = diff(f);
    e = solve(df==0);
    plot(e,subs(f,e),'ks');
end

function solve7()
    syms x y;
    [Sx,Sy] = solve(x^2+y^2-4==0,-2*x+y-2==0);
    dy = dsolve('2*D2y-9*y=sin(8*x)','y(0)=0,Dy(0)=1','x');
%     pretty(dy);
    subplot(2,1,1);
    ezplot('x^2+y^2-4=0');
    hold on;
    ezplot('-2*x+y-2=0');
    hold on;
    plot(Sx,Sy,'rs ');
    subplot(2,1,2);
    ezplot(dy);
    axis tight;
end

function solve6()
    X = -5:0.01:5;
    P = [2 5 0 -3];
    polinomi(P,X);
    function polinomi(P,X)
       y = polyval(P,X);
       y = y + randn(size(y));
       n=1;
       i=0; x=0; plus=0; kruzic = 0;
       drugiRed = 0; treciRed = 0;
       while(n>0)
          n = input('Unesi red polinoma: ');
          if n~=[2 3]
              disp('Pogresan red');
              break;
          end
          z = input('Unesi marker: ');
          if z~=['x' '+' 'o']
              disp('Pogresan marker');
              break;
          end
          if n==2
              drugiRed = drugiRed+1;
          else 
              treciRed = treciRed+1;
          end
          if z == 'x'
              x = x+1;
          elseif z == '+'
              plus = plus+1;
          else
              kruzic = kruzic+1;
          end
          plot(X,y,z);
          grid on; hold on;
          pn = polyfit(X,y,n);
          figure(i+1);
          plot(X,polyval(pn,X));
          i = i+1;
       end
       disp(['Ukupno izvrsenih aproksimacija: ' num2str(i)]);
       maxRed = drugiRed;
       if treciRed > drugiRed
           maxRed = treciRed;
       end
       disp(['Najcesce koristena aproksimacija ' num2str(maxRed) '.redom']);
       maxSign = x;
       if plus > maxSign
           maxSign = '+';
       elseif kruzic > maxSign
           maxSign = 'o';
       else
           maxSign = 'x';
       end
       disp(['Najcesce koristeni znak: ' maxSign]);
    end
end

function solve5()
    z2('b');
    function z2(znak)
        if nargout ~= 0
            error('boris');
        end
        if nargin~=1
            error('boris');
        end
        if znak == 'a'
            x = -pi:0.01:pi;
            y = x;
            [X,Y] = meshgrid(x,y);
            Z = 3*sin(X).*cos(Y);
            surf(X,Y,Z);
            shading interp;
            colormap gray;
            title('naslov');
        elseif znak == 'b'
            P = [2 3 0 -6];
            x = -4:0.1:4;
            y = polyval(P,x);
            y = y + randn(size(y));
            plot(x,y,'cd');
            hold on; grid on;
            p2 = polyfit(x,y,2);
            plot(x,polyval(p2,x),'r');
        else
            error('pogresan znak');
        end
    end
end

function solve4()
    P1 = [2 5 0 -4];
    r2 = [-1 2 6];
    P2 = poly(r2);
    P = conv(P1,P2);
    x = -5:0.1:5;
    y = polyval(P,x);
    y = y + randn(size(y));
    plot(x,y,'bd');
    grid on; hold on;
    p2 = polyfit(x,y,2);
    p3 = polyfit(x,y,3);
    plot(x,polyval(p2,x),'r');
    hold on;
    plot(x,polyval(p3,x),'g--');
    axis tight;
end

function solve3()
    x = -2:0.02:2;
    y = x;
    [X,Y] = meshgrid(x,y);
    Z = X+1j*Y;
    fun = abs(1./(Z.^4+1));
    surf(X,Y,fun);
    colormap jet;
    figure(2)
    contourf(X,Y,fun,10);
end

function solve2(fun)
    x = -1:0.1:3;
    y = 1:0.1:4;
    [X,Y] = meshgrid(x,y);
    Z = feval(fun,X,Y);
    surf(X,Y,Z);
    colormap(jet);
    colorbar;
    grid on;
    shading interp;
end

function solve1()
    P1 = [1 0 -3 4];
    r2 = [1 -2 3];
    r1 = roots(P1);
    P2 = poly(r2);
    P = conv(P1,P2);
    x=-4:0.1:4;
    y = polyval(P,x);
    y = y + randn(size(y));
    p2 = polyfit(x,y,2);
    p3 = polyfit(x,y,3);
    figure(1)
    plot(x,y,'ko','MarkerSize',5);
    grid on; hold on;
    plot(x,polyval(p2,x),'y--');
    figure(2)
    plot(x,y,'gs','MarkerSize',5);
    grid on; hold on;
    plot(x,polyval(p3,x),'r');
end

function dydt = diffFun(t,y)
    dydt = -t*y/10;
end

function dy = simpleEq(t,y)
    dy = sin(y)-sin(t);
end

function dxdt = klatno(t,x)
    L=1;
    theta = x(1);
    gamma = x(2);
    
    dtheta = gamma;
    dgamma = -(9.8/L)*sin(theta);
    
    dxdt = zeros(2,1);
    
    dxdt(1) = dtheta;
    dxdt(2) = dgamma;
end

function izvod(func,x)
    y = feval(func,x);
    plot(x,y,'r');
    grid on; hold on;
    dydx = diff(y)./diff(x);
    plot(x(:,1:length(dydx)),dydx,'b');
end