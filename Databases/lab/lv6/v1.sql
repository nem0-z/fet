use stusluZR;
select *
from rezervacija inner join dvorana
on rezervacija.ozndvorana = dvorana.ozndvorana
group by 1,2,3,4,6;

select * from rezervacija;
select * from dvorana;
select * from rezervacija group by 1,2,3,4;

select ocjena, count(*) from ispit
group by 1;
select count(*) from ispit where ocjena IN
(select ocjena from ispit where ocjena = 1);

select mbrstud, datispit from ispit
group by 1,2
having count(sifpred) > 1;

select pbrstan from stud
order by imestud desc, prezstud asc;

select pbr, nazmjesto from mjesto as mjestorod
union all
select pbr, nazmjesto from mjesto as mjestostan;

#vjezbaaa braaateeee

select nazorgjed ,count(ocjena)from orgjed
	inner join pred on pred.siforgjed=orgjed.siforgjed
	inner join ispit on ispit.sifpred=pred.sifpred
    where ocjena>1
    group by nazorgjed
    order by count(ocjena) desc, 1 ;
    
select nazmjesto, avg(ocjena) from mjesto
	inner join stud on stud.pbrstan=mjesto.pbr
    inner join ispit on ispit.mbrstud=stud.mbrstud
    where ocjena >1 and year(datispit)=1999
    group by nazmjesto
    order by 2, nazmjesto desc;
    
select nazpred, kratpred, avg(ocjena)
from pred as p1
inner join ispit on ispit.sifpred = p1.sifpred
where ocjena > 1
group by 1,2,p1.sifpred
having avg(ocjena) > (select avg(ocjena) from ispit
inner join pred as p2 on p2.sifpred=ispit.sifpred where
p1.siforgjed = p2.siforgjed and ocjena > 1);
    
    select datispit from ispit;
drop table nastTmp;
create temporary table nastTmp as
select nastavnik.*, count(ocjena) as polispit, avg(ocjena) as prosjek
from nastavnik inner join ispit on nastavnik.sifnastavnik=ispit.sifnastavnik
where ocjena > 1
group by 1,2,3,4,5,6
having count(ocjena) > (select count(mbrstud) from stud
where stud.pbrrod=nastavnik.pbrstan);
