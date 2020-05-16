%padajuci meni callback

function menus(x,y)
meni1 = uimenu('Label','Vrsta linije');
linija = plot(x,y,'Tag','linija');
set(linija,'Color',[1 0 0]);

cb1 = ['set(findobj(''Tag'',''linija''), ''LineStyle'', ''--'')'];
cb2 = ['set(findobj(''Tag'',''linija''), ''LineStyle'', '':'')'];
cb3 = ['set(findobj(''Tag'',''linija''), ''LineStyle'', ''-'')'];

opcija1 = uimenu(meni1,'Label','isprekidana','Callback',cb1);
opcija1 = uimenu(meni1,'Label','tackasta','Callback',cb2);
opcija1 = uimenu(meni1,'Label','puna','Callback',cb3,'separator','on');
end