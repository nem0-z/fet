USE stusluZR;

#1
SELECT sifNastavnik, imeNastavnik, prezNastavnik, koef FROM nastavnik;

#2
SELECT * FROM pred;

#3
SELECT DISTINCT imeStud FROM stud;

#4
SELECT DISTINCT sifNastavnik FROM ispit WHERE ocjena=1 AND sifPred=146;

#5
SELECT mbrStud FROM ispit where ocjena>1 AND sifPred=262;

#6
SELECT prezNastavnik, imeNastavnik, (800*(koef+0.4)) AS plata FROM nastavnik;

#7
SELECT prezNastavnik FROM nastavnik 
WHERE (800*(koef+0.4)) BETWEEN 3500 AND 8000;

#8
SELECT prezNastavnik, SUBSTRING(imeNastavnik,1,1) AS Ime FROM nastavnik;

#9
SELECT prezStud, imeStud, 
CONCAT(SUBSTRING(imeStud,1,1),'.',SUBSTRING(prezStud,1,1),'.') AS Inicijali
FROM stud;

#10
SELECT * FROM ispit WHERE MONTH(datIspit)=7;

#11
SELECT * FROM ispit WHERE WEEKDAY(datIspit)=2 AND MONTH(datIspit)=8;

#12
SELECT mbrStud, ocjena, datIspit, CURRENT_DATE(), DATEDIFF(CURRENT_DATE(),datIspit) FROM ispit;

#13
SELECT * FROM stud WHERE datRodStud=DATE_SUB(CURRENT_DATE(),INTERVAL 25 YEAR);

#14
SELECT sifNastavnik, mbrStud, ocjena, DATEDIFF('2009-01-01',datIspit) FROM ispit;

#15
SELECT mbrStud, sifPred, ocjena, DATE_ADD(datIspit,INTERVAL 3800 DAY) AS Datum FROM ispit
WHERE CURRENT_DATE() < DATE_ADD(datIspit,INTERVAL 3800 DAY);

#16
#SELECT mbrStud, sifPred, ocjena, datIspit, DATE_ADD(datIspit, INTERVAL 3 YEAR) FROM ispit;
SELECT mbrStud, sifPred, ocjena, datIspit, DATE_ADD(datIspit, INTERVAL 3 YEAR) FROM ispit
WHERE datIspit='1980-02-29';

#17
SELECT oznDvorana, oznVrstaDan, sat, sifPred as predmet FROM rezervacija;

#18
SELECT DISTINCT pbrRod, pbrStan FROM stud;