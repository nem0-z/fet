#testing


delimiter ++++
create function rasporedi(sifra int, n int)
returns int
begin
	-- defaultni handler
	declare exit handler for sqlexception
	begin
	rollback;
	signal sqlstate '45000' set MESSAGE_TEXT='greskica';
	end;
	-- zato sto ne smiju bit phantom rows
	set transaction isolation level serializable;
	start transaction;
	begin
    
    declare tmp_sifra int;
    declare novo_stanje int;
    -- kursor da bi mogli dojavit koja je sifra posjeda
    declare cur cursor for select sifposjed from posjed
		where sifKanton=sifra order by povrsina desc limit n;
        -- taj handler pojedinacni
    declare exit handler for sqlstate '45000'
    rollback;
    set message_text=substring('greska u sifri ', tmp_sifra);
    end;
    
    open cur;
    l:loop
    fetch cur into tmp_sifra;
    update posjed set iznosSubv = iznosSubv+1000
    where sifKanton = sifra;
    end loop;
	close cur;
    
    update kanton set stanje=stanje-1000*n;
	if stanje < 0 then 
		rollback;
        return -1;
	else 
		commit;
        return 1;
	end if;
        
	
	end;
end;++++