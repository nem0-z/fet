%plotting callback

try
    P = eval(get(unos1,'string'));
    x = eval(get(unos2,'string'));
catch
    disp('Greska u unosu');
end

y = polyval(P,x);
y = y + randn(size(y));

mojIzbor = get(izbor,'value');

cla;
switch mojIzbor
    case 1
        cla;
    case 2
        plot(x,y,'b*');
    case 3
        plot(x,y,'b+');
    case 4
       plot(x,y,'bo');
    case 5
       plot(x,y,'bx');
end

axis tight;
hold on; grid on;
P1 = polyfit(x,y,length(P)-1);
menus(x,polyval(P1,x));