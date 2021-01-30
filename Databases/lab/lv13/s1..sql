
use stusluZR;
CREATE TABLE uspjeh (
mbrStud CHAR(8) NOT NULL
, bodovi INTEGER NOT NULL
, PRIMARY KEY (mbrStud)
);

delimiter ++++
create function polozeni(mbr int)
returns int
begin
declare b ,polozeni int;
select count(ocjena) into polozeni from ispit where mbr=mbrstud;
if polozeni=0 then set b = 0; 
elseif polozeni=1 then set b = 5;
elseif polozeni=2 then set b = 15;
else set b = 50;
end if;
return b;
end
++++
drop procedure polozeni;++++

create procedure poruka(in p text)
begin
signal sqlstate '45000' set message_text=p;
end
++++


create trigger trig1 after insert on ispit for each row
begin
update uspjeh set bodovi = polozeni(new.mbrstud);
end;
++++

create trigger trig1 after update on ispit for each row
begin
call polozeni(new.mbrstud);
end;
++++

create trigger trig2 before delete on ispit for each row
begin
call poruka('Nedozvoljeno brisanje u ispit');
end;
++++

create trigger trig2 before delete on uspjeh for each row
begin
call poruka('Nedozvoljeno brisanje u uspjeh');
end;
++++

create trigger trig2 before update on ispit for each row
begin
if new.mbrstud<>old.mbrstud then
call poruka('Nedozvoljeno azuriranje u ispit');
end if;
end;
++++

create trigger trig2 before update on uspjeh for each row
begin
if new.mbrstud<>old.mbrstud then
call poruka('Nedozvoljeno azyuriranje u uspjeh');
elseif new.bodovi<>polozeni(mbrstud) then
call poruka('Nedozvoljeno azyuriranje u uspjeh');
end if;
end;
++++

create trigger trig145 before insert on uspjeh for each row
begin
select "braaateeee";
end
++++

