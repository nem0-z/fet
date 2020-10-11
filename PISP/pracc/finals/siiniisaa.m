function siiniisaa(x,y)
    meni1 = uimenu('Label','Vrsta linije');
    Lajna = plot(x,y,'Tag','Lajna');
    set(Lajna,'Color',[1 0 0]);
    
   cb1 = ['set(findobj(''Tag'',''Lajna''), ''LineStyle'', ''--'')'];
   cb2 = ['set(findobj(''Tag'',''Lajna''), ''LineStyle'', '':'')'];
   cb3 = ['set(findobj(''Tag'',''Lajna''), ''LineStyle'', ''-'')'];
  
   uimenu(meni1,'Label','--','Callback',cb1);
   uimenu(meni1,'Label','.....','Callback',cb2);
   uimenu(meni1,'Label','puna','Callback',cb3);
end