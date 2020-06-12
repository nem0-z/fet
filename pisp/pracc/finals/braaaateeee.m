
    try
        P = eval(get(polinom,'String'));
        x = eval(get(interval,'String'));
    catch
       text(0.35,0.5,'braatee'); 
    end
    
    choice_ = get(choice,'Value');
    
    cla;
    znak=0;
    switch choice_
        case 1
            cla;
        case 2
            znak = 'b+';
        case 3
            znak = 'b*';
        case 4
            znak = 'bo';
        case 5
            znak = 'bx';
    end
    y = polyval(P,x);
    y = y + randn(size(y));
    red = length(P)-1;
    pn = polyfit(x,y,red);
    plot(x,y,znak); hold on; grid on;
    plot(x,polyval(pn,x),'r');
    siiniisaa(x,polyval(pn,x));
