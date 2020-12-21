use stusluZR;

select * from stud
where  adddate(datrodstud, interval 25 year) = current_date;

select ispit.*, abs(datediff(datispit, '2009-01-01')) from ispit;

#Ispis svih studenata koji su rođeni između 1.5. i 1.9.1982 i prezime im počinje slovom "R" ili
#slovom "P" ili slovom "S" ili slovom "V". Koristiti operator RLIKE
select * from stud
where datrodstud between '1982-05-01' and '1982-09-01' and
prezstud rlike '^[PRSV]';

#Ispis svih mjesta kojima naziv počinje i završava samoglasnikom. Koristiti operator LIKE
select * from mjesto
where nazmjesto rlike '^[AEIOU]' AND nazmjesto rlike '[aeiou]$';

#Ispis svih mjesta kojima naziv počinje i završava bilo kojim znakom osim samoglasnikom.
#Koristiti operator RLIKE

select avg(ocjena) from ispit
where year(datispit) = 1999
and ocjena > 1;

select count(ocjena), avg(ocjena) from ispit
where sifpred = 146;

select abs(datediff(datrodstud, current_date)) from stud
where pbrRod = 10000 and imestud rlike '^[AEIOU]' or imestud rlike '[aeiou]$';

select concat(substring(imestud, 1, 1), '.', substring(prezstud, 1, 1)), 
substring(nazPred, 1, 25), datIspit 
from ispit 
inner join pred using(sifpred) 
inner join stud using(mbrstud)
where ocjena = 5;

#Ispisati nazive i kratice predemta koji pripadaju 
#organizacijskim jedinicama čija neposredno nadređena
#organizacijska jedinica ima naziv koji sadrži riječ "tehnike" (182 zapisa)

select nazpred, kratpred from pred
inner join orgjed p1 on pred.siforgjed = p1.siforgjed
inner join orgjed p2 on p1.sifNadorgjed = p2.siforgjed
where p2.nazOrgjed like '%tehnike%';

select distinct stud.* from stud
inner join ispit on stud.mbrstud = ispit.mbrstud
inner join nastavnik on ispit.sifnastavnik = nastavnik.sifnastavnik
inner join mjesto on nastavnik.pbrStan = mjesto.pbr
inner join zupanija on mjesto.sifZupanija = zupanija.sifZupanija
where ocjena = 1 
and zupanija.nazzupanija = 'Osjecko-baranjska';

select count(ocjena) from ispit
inner join nastavnik on nastavnik.sifnastavnik = ispit.sifnastavnik
inner join mjesto on nastavnik.pbrStan = mjesto.pbr
where ocjena = 1 and nazmjesto like 'Z%';

select ozndvorana, kapacitet from dvorana
inner join rezervacija using (ozndvorana)
inner join pred using(sifpred)
where nazpred = "Energetska elektronika-izabrana poglavlja"
and oznvrstadan in ('PO','SR','PE');

select count(distinct sifpred) from rezervacija
inner join dvorana using(ozndvorana)
where kapacitet <= 60;

select distinct nastavnik.* from nastavnik
inner join ispit using(sifnastavnik)
inner join mjesto as mjestoN on mjestoN.pbr = nastavnik.pbrStan
inner join stud on ispit.mbrstud = stud.mbrstud
inner join mjesto as mjestoS on mjestoS.pbr = stud.pbrStan
where mjestoS.sifZupanija = mjestoN.sifZupanija;

select stud.* from stud
where mbrstud not in
(select mbrstud from ispit where ocjena = 1);

select nazmjesto from mjesto
inner join nastavnik on mjesto.pbr = nastavnik.pbrstan
where pbr not in (select pbrrod from stud);

select distinct nazzupanija from zupanija
where sifzupanija not in
(select sifzupanija from stud
inner join mjesto on stud.pbrstan = mjesto.pbr)
and sifzupanija in 
(select sifzupanija from stud
inner join mjesto on stud.pbrrod = mjesto.pbr);

select * from zupanija;
select * from mjesto;
select * from zupanija inner join mjesto using(sifZupanija);

SELECT nastavnik.sifNastavnik, imeNastavnik, prezNastavnik FROM nastavnik
WHERE sifNastavnik NOT IN
(SELECT sifNastavnik FROM ispit
WHERE YEAR(datIspit) = 2000
AND MONTH(datIspit) IN (1,2)
AND ocjena > 1); 

select imestud, prezstud, datrodstud from stud
where adddate(datrodstud, interval 200 day) <= (select max(datrodstud) from stud);

select ozndvorana, kapacitet from dvorana
where kapacitet > (select count(distinct sifPred) from rezervacija
where rezervacija.oznDvorana = dvorana.oznDvorana);

select nastavnik.* from nastavnik
inner join mjesto on nastavnik.pbrStan = mjesto.pbr
where koef < (select avg(koef) from nastavnik n1
inner join mjesto m1 on n1.pbrStan = m1.pbr
where n1.sifnastavnik != nastavnik.sifnastavnik
and m1.sifzupanija = mjesto.sifzupanija);

select stud.* from stud
where mbrstud not in
(select mbrstud from ispit
where weekday(datispit) = weekday(stud.datrodstud));

select stud.mbrstud, imestud, prezstud from stud
inner join ispit using(mbrStud)
inner join nastavnik using(sifNastavnik)
where ocjena > 1
and sifnastavnik not in
(select sifnastavnik from ispit
where ispit.mbrStud != stud.mbrStud
and ocjena > 1);

select kratpred, nazpred, avg(ocjena) from pred
inner join ispit on ispit.sifpred = pred.sifpred
where ocjena > 1
group by 1, 2, pred.sifPred;

select sifzupanija, count(ocjena) from mjesto
inner join nastavnik on mjesto.pbr = nastavnik.pbrStan
inner join ispit on ispit.sifnastavnik = nastavnik.sifnastavnik
where ocjena = 1
group by 1;

select imeNastavnik, count(ocjena) from nastavnik
inner join ispit on nastavnik.sifnastavnik = ispit.sifnastavnik
where ocjena > 1
group by nastavnik.sifNastavnik, 1;

select n1.siforgjed, n1.nazorgjed, count(p1.siforgjed) 
from orgjed as n1
inner join orgjed as p1 on p1.sifNadorgjed = n1.siforgjed
group by 1, 2;

select stud.mbrstud, avg(ocjena) from ispit
inner join stud on ispit.mbrstud = stud.mbrstud
where ocjena > 1
group by 1
having avg(ocjena) > 3;

select mjesto.pbr, count(mbrStud) from mjesto
inner join stud on mjesto.pbr = stud.pbrRod
group by 1
having count(mbrStud) > 5;

select stud.mbrStud from stud
inner join ispit on stud.mbrstud = ispit.mbrstud
where ocjena = 1
group by 1, sifPred
having count(ocjena) >= 3;

create temporary table mjestoTmp as
select mjesto.*, count(sifNastavnik) AS brojNast
FROM mjesto INNER JOIN nastavnik on mjesto.pbr = nastavnik.pbrStan
group by 1, 2, 3;

select month(datRodStud), count(mbrStud) as c from stud
group by 1
order by c desc;

select stud.* from stud
inner join ispit using(mbrStud)
where ocjena > 1
group by 1, 2, 3, 4, 5, 6, 7
having avg(ocjena) > 
(select avg(ocjena) from ispit
where ispit.mbrStud != stud.mbrStud)
or count(ocjena) > 
(select count(ocjena) from ispit
where ispit.mbrStud != stud.mbrStud);

create unique index sinisa on pred(sifOrgjed);

create temporary table t1(
ind SERIAL 
);

insert into t1 values(null);
select * from t1;

select sifnastavnik, preznastavnik, imenastavnik,
orgjed.siforgjed, IF(nastavnik.sifOrgjed IS NULL, 'AAAAAAAAAAA', orgjed.nazorgjed) 
from nastavnik
left join orgjed on orgjed.siforgjed = nastavnik.siforgjed;

SELECT nastavnik.* FROM nastavnik
left join orgjed using(siforgjed)
inner join nadredjenu; #ovo bi trebalo u left

select nastavnik.*, nazmjesto, nazzupanija from nastavnik
left join mjesto on nastavnik.pbrstan = mjesto.pbr
left join zupanija on mjesto.sifzupanija = zupanija.sifzupanija;

select * from dvorana
where kapacitet > (select avg(kapacitet) from dvorana);

create temporary table nastTmp as
select nastavnik.*, count(ocjena) polIspit, avg(ocjena) prosjek from nastavnik
inner join ispit using (sifNastavnik) 
where ocjena > 1
group by 1, 2, 3, 4, 5, 6
having count(ocjena) > 
(select count(mbrstud) from stud
where stud.pbrrod = nastavnik.pbrstan);

delimiter ++++
create function boris()
returns integer
deterministic
begin
	declare ret integer;
	select count(*) into ret from stud;
	#set ret = 1;
    begin
     select 1;
    end;
    return ret;
end;
++++

create procedure ajla()
select * from stud;
++++

CREATE PROCEDURE scope()
BEGIN
DECLARE x,y,z INT;
SET x = 5;
SET y = 10;
SET z = x + y;
BEGIN
DECLARE x, q INT;
DECLARE z CHAR(5);
SET x = 100;
SET q = x + y; -- q = 110
SET z = 'silly'; -- z dobija karakter vrijednost
END;
SET y = x; -- y je sada 5
SET x = z; -- z je sada 15, a ne 'silly'
END;
++++

create procedure foo(in broj int)

deterministic
begin
declare total INT;
	case broj
    when 5 then select 1;
    when 6 then select 1;
    else select 2;
    end case;
    select 2 into total;
    return total;
end;
++++


create function compare(s1 varchar(20), s2 varchar(20))
returns integer
deterministic
begin
	declare ret integer;
    declare str1, str2 integer;
    set str1 = length(s1), str2 = length(s2);
    #set str2 = length(s2);
    if str1 > str2 then
		set ret = 1;
	elseif str2 > str1 then
		set ret = -1;
	else
		set ret = 0;
	end if;
    return ret;
end
++++

create procedure amer(out a1 int, inout a2 int, in a3 int)
begin
	select a1,a2, a3;
	set a2 = 450;
    #set a1 = a2 + 5;
end
++++

delimiter ;
drop procedure amer;
set @zlatan = 10;
call amer(@ahmelina, @almina, @domagoj);
select @ahmed, @arijan;

prepare fun from 'call amer(?, ?, ?)';
execute fun using @karlo, @mateo, @vildana;

select boris();
drop function boris;
drop function compare;
call ajla();
select (length('sinisa') < length('zoris'));
select compare('borisaaaaa', 'sinisa');

set @i = 0;

loop
if @i=10 leave;
@i = @i+1;
select "sinisa";
end loop





