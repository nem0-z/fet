use stusluZR;
SET GLOBAL log_bin_trust_function_creators = 1;

delimiter /
create procedure p1(inout a integer)
begin
	set a = a + 1;
end/

create function p1f(a integer)
returns integer
begin
	set a = a + 1;
    return a;
end/

create procedure p3()
begin
	declare t integer;
    select count(mbrStud) from stud into t;
    select t;
end/

create procedure p4(in n integer)
begin
	case n
		when 1 then select 11;
        when 2 then select 12;
        else select 333;
    end case;
end/

create procedure p5(in n integer)
begin
	declare a integer default 0;
    declare counter integer;
    set counter = n;
    petlja: loop
		if counter <= 0 then 
			leave petlja;
		end if;
		set a = a + 2;
        set counter = counter - 1;
    end loop;
    select a;
end/

create procedure p6()
begin
    declare t1 integer default null;
    declare cnt, limiter integer;
	declare c1 cursor for select mbrStud from stud;
    set cnt = 0, limiter = (select count(mbrStud) from stud);
    open c1;
    petljica: loop
		if cnt >= limiter then 
			leave petljica;
		end if;
		fetch c1 into t1;
        select t1;
        set cnt = cnt + 1;
	end loop;
    close c1;
end/

delimiter ;
call p6; #WTF HAHAHA
drop procedure p5;
set @s = 2;
select @s;
call p1(@s);
select p1f(@s);
select @s;
call p3;
select version();
set @s5 = (select count(*) from ispit);
select @s5;
set @t1 = 1, @t2 = 2, @t3 := 4;
select @t1, @t2, @t3, @t4 := @t1 + @t2 + @t3; #7
select @t1, @t2, @t3, @t4 = @t1 + @t2 + @t3; #1
call p4(12);
call p5(8);
