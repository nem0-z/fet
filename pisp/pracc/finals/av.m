clear all
close all
clc

solve12()

function solve12()
    
end

function solve11()
    f1 = figure('Tag','figure1','name','ODE solveri','menubar','none',...
        'Position',[200 200 500 500]);
    ax = axes('Units','normalized','Position',[0.1 0.1 0.8 0.70],'parent',f1);
    
    uicontrol('Style','text','String',"y'=",'Units','normalized','Position',[0.1 0.84 0.05 0.05],'parent',f1);
    inputfun = uicontrol('Style','edit','Units','normalized','Position',[0.16 0.84 0.25 0.05],'parent',f1);
    uicontrol('Style','text','String',"t=",'Units','normalized','Position',[0.43 0.84 0.05 0.05],'parent',f1);
    inputt = uicontrol('Style','edit','Units','normalized','Position',[0.49 0.84 0.25 0.05],'parent',f1);
    popaga = uicontrol('Style','popup','String','|ode23|ode45|ode15s','Units','normalized','Position',[0.76 0.84 0.16 0.05],'parent',f1,'Callback',@cb);
    
    function cb()
        disp(1)
       try
           eq = get(inputfun,'string');
           interval = eval(get(inputt,'string'));
       catch
           error('eror');
       end
       
       izbor = get(popaga,'value');
       disp(2)
       cla;
       switch izbor
           case 1
               cla;
           case 2
               [t,y] = ode23(@(t,y) eval(eq),interval,1);
           case 3
               [t,y] = ode45(@(t,y) eval(eq),interval,1);
           case 4
               [t,y] = ode15s(@(t,y) eval(eq),interval,1);
       end
       plot(t,y);
       axis tight;
       grid on;
    end
    
    

end
function solve10()
    
a = z3();
disp(a);

    function Dmax = z3()
        T = struct([]);
        n = input('Broj tacaka: ');
        Dmax = -1;
        maxx = -1;
        maxy = -1;
        for i=1:n
           T(i).x = input('Unesi x koordinatu: ');
           T(i).y = input('Unesi y koordinatu: ');
           d = sqrt(T(i).x^2+T(i).y^2);
           if d>Dmax
               Dmax = d;
               maxx = T(i).x;
               maxy = T(i).y;
           end
        end
        plot([T(:).x],[T(:).y],'bo','MarkerSize',10);
        hold on; grid on;
        plot([0 maxx],[0 maxy],'r');
    end
end

function solve9()
    
    r = z3();
    fprintf("Najvise tacaka u %d. kvadrantu",r);
    
    function kvadrant = z3()
       T = struct([]);
       k1=0;k2=0;k3=0;k4=0;
       n = input('Broj tacaka: ');
       
       for i=1:n
           x = input('Unesi x koordinatu: ');
           T(i).x = x;
           y = input('Unesi y koordinatu: ');
           T(i).y = y;
           if x>=0 && y>=0
               k1 = k1+1;
           elseif x<0 && y>=0
               k2 = k2+1;
           elseif x<0 && y<0
               k3 = k3+1;
           else 
               k4 = k4+1;
           end
           plot(x,y,'ro','MarkerSize',12); hold on; grid on;
           kvadranti = [k1 k2 k3 k4];
       end
       fprintf("%d\n%d\n%d\n%d\n",k1,k2,k3,k4);
       [foo,kvadrant] = max(kvadranti);
    end
end

function solve8()
    A = {rand(3),'utorak',rand(3,1)};
    C{1,1} = A;
    B = {4-7*j;rand(2,2,2);'petak'};
    C{1,2} = B;
    C{2,1} = strvcat('Januar','Februar','Mart','April');
    S = struct('name',{'John','Mary','Leo'},'age',{32,27,18},'childAge',{[2;4],1,[]});
    C{2,2} = S;
    cellplot(C);
end

function solve7()
    syms x y positive;
    f = 8/x+x/y+y;
    
    fx = diff(f,x);
    fy = diff(f,y);
    [a b] = solve(fx,fy);
    
    fxx = diff(fx,x);
    fyy = diff(fy,y);
    fxy = diff(fx,y);
    
    D = fxx*fyy-fxy*fxy;
    
    eks = subs(D,[x y],[a b]);
    A = subs(fyy,[x y],[a b]);
    ekstrem = subs(f,[x y],[a b]);
    
    if eks<0
        disp('Nema ekstrema mrs');
    else
        if A>0
           disp('Minimum funkcije: ');
        else
            disp('Maksimum funkcije: ');
        end
        [a,b],ekstrem
    end
end

function solve6()
    syms x;
    a = log(x);
    b = x;
    f = a/b;
    ezplot(f,[-1 6 -6 1]);
    grid on; hold on;
    nula = solve(a);
    plot(nula,0,'ko'); hold on;
    
    ha = limit(f,inf);
    va = solve(x==0);
%     limit(f,x,va,'right');
    plot([-1 6],[ha ha],'r'); hold on;
    plot([va va],[-6 1],'g'); hold on;
    
    df = diff(f);
    eks = solve(df);
    plot(eks,subs(f,eks),'ks');
end

function solve5()
    syms x;
    y = 2*x^3+3*x^2-36*x+10;
    ezplot(y);
    grid on; hold on;
    
    y1 = diff(y);
    x0 = solve(y1);
    y0 = subs(y,{x},x0);
    
    y2 = diff(y1);
    s = subs(y2,{x},x0);
    
    a = find(s<0)
    max = [x0(a)' y0(a)'];
    
    b = find(s>0)
    min = [x0(b)' y0(b)'];
    plot(x0,y0,'ro');
end

function solve4()
    syms x y;
    a = 3*x^3-x^2-3*x+1;
    b = x^2+4*x+4;
    nule = solve(a);
    prekidi = solve(b);
    fun = x.^2.*sin(2*x);
    F = int(fun,-1,4);
    ezplot(fun); hold on; grid on;
    diffy = dsolve('2*D2y+3*Dy+4*y=cos(5*x)','y(0)=0,Dy(0)=1','x');
    figure(2)
    ezplot(diffy);
    [Sx,Sy] = solve(x^2+y^2-5==0,-2*x+y-2==0);
    figure(3)
    ezplot('x^2+y^2-5=0');
    grid on; hold on;
    ezplot('2*x+y-2=0');
    hold on;
    plot(Sx,Sy,'yd');
end

function solve2()
    P1 = [2 5 0 -4];
    r2 = [-1 2 6];
    x=-5:0.1:5;
    P2 = poly(r2);
    P = conv(P1,P2);
    y = polyval(P,x);
    y = y + randn(size(y));
    plot(x,y,'d');
    grid on; hold on;
    p2 = polyfit(x,y,2);
    p3 = polyfit(x,y,3);
    plot(x,polyval(p2,x),'r'); hold on;
    plot(x,polyval(p3,x),'b--');
    xlabel('x-osa');
    ylabel('y-osa');
    title('Aproksimacija polinomima');
end

function solve1()
    P1 = [1 0 -2 4];
    r2 = [1 -2 3];
    r1 = roots(P1);
    P2 = poly(r2);
    x = -4:0.1:4;
    P = conv(P1,P2);
    y = polyval(P,x);
    y = y + randn(size(y));
    p2 = polyfit(x,y,2);
    p3 = polyfit(x,y,3);
    figure(1)
    plot(x,y,'ko');
    hold on; grid on; axis tight;
    plot(x,polyval(p2,x),'y--');
    title('Aproksimacija polinomom 2.reda');
    figure(2)
    plot(x,y,'gd');
    hold on; grid on; axis tight;
    plot(x,polyval(p3,x),'r');
    title('Aproksimacija polinomom 3.reda');
end

