use stusluZR;

update mjesto set nazmjesto = concat('grad-', nazmjesto),
pbr = pbr + 10
where pbr > 30000;

update nastavnik set
koef = koef*(1 - 0.01*(select avg(ocjena) from ispit
where ocjena > 1 and ispit.sifnastavnik = nastavnik.sifnastavnik))
where sifnastavnik in (
select sifnastavnik from ispit
where ocjena > 1
group by sifnastavnik
having count(ocjena) > 1);

