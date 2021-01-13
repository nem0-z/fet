use stusluZR;

delimiter /
create procedure s1()
begin
	declare exit handler for sqlexception
		begin
			select 'botino mrs u pm';
        end;
	insert into stud values(1121,null,null,null,null,null,null);
    select 'zdravo';
end/

delimiter ;

select * from stud;
drop procedure if exists s1;
call s1;
