USE stusluZR;

#1
SELECT * FROM stud 
WHERE mbrStud NOT IN (SELECT mbrStud FROM ispit WHERE ocjena = 1);

#2
SELECT nazMjesto FROM mjesto
WHERE mjesto.pbr IN (SELECT DISTINCT pbrStan FROM nastavnik)
AND mjesto.pbr NOT IN (SELECT DISTINCT pbrRod FROM stud);

#3
SELECT nazZupanija FROM zupanija
WHERE sifZupanija IN (SELECT sifZupanija FROM mjesto INNER JOIN stud ON mjesto.pbr = stud.pbrRod)
AND sifZupanija NOT IN (SELECT sifZupanija FROM mjesto INNER JOIN stud ON mjesto.pbr = stud.pbrStan);

#4
SELECT sifNastavnik, imeNastavnik, prezNastavnik FROM nastavnik
WHERE sifNastavnik NOT IN 
(SELECT sifNastavnik FROM ispit 
WHERE ocjena > 1 
AND MONTH(datIspit) IN (1,2) 
AND YEAR(datIspit) = 2000);

#5
SELECT imeStud, prezStud, datRodStud FROM stud
WHERE DATEDIFF((SELECT MAX(datRodStud) FROM stud), datRodStud) >= 200;

#6
SELECT pred.* FROM pred
WHERE sifOrgjed IN 
(SELECT sifOrgjed FROM nastavnik
WHERE prezNastavnik LIKE 'O%');

#7
SELECT * FROM dvorana
WHERE kapacitet > 
(SELECT COUNT(DISTINCT sifPred) FROM rezervacija
WHERE dvorana.oznDvorana = rezervacija.oznDvorana);

#8
SELECT sifNastavnik, imeNastavnik, prezNastavnik, koef, m1.nazMjesto 
FROM nastavnik AS n1
INNER JOIN mjesto AS m1 ON m1.pbr = n1.pbrStan
WHERE koef < (SELECT AVG(koef) FROM nastavnik AS n2 
INNER JOIN mjesto AS m2 ON m2.pbr = n2.pbrStan
WHERE m2.sifZupanija = m1.sifZupanija
AND n1.sifNastavnik != n2.sifNastavnik);

#9
SELECT mbrStud, imeStud, prezStud FROM stud
WHERE mbrStud NOT IN (SELECT mbrStud FROM ispit
WHERE WEEKDAY(datIspit) = WEEKDAY(datRodStud));

#10
SELECT sifNastavnik, imeNastavnik, prezNastavnik FROM nastavnik
INNER JOIN mjesto ON nastavnik.pbrStan = mjesto.pbr
INNER JOIN zupanija ON mjesto.sifZupanija = zupanija.sifZupanija
WHERE nazZupanija = 'Dubrovačko-neretvanska'
AND koef > ANY(SELECT koef FROM nastavnik
INNER JOIN mjesto ON nastavnik.pbrStan = mjesto.pbr
INNER JOIN zupanija ON mjesto.sifZupanija = zupanija.sifZupanija
WHERE nazZupanija = 'Splitsko-dalmatinska');

#11
SELECT mbrStud, imeStud, prezStud FROM stud
WHERE mbrStud IN 
(SELECT mbrStud FROM ispit 
WHERE ocjena > 1
AND sifNastavnik NOT IN 
(SELECT sifNastavnik FROM ispit 
WHERE ocjena > 1
AND mbrStud != stud.mbrStud));

#12

#a) b c, m k

#b) d e

#c) f

#d)
# a b c 7 g
# a b c 11 e
# a b c 11 g
# a d k 5 f
# a d k 7 g
# a d k 11 e
# a d k 11 g
# a e m 5 f
# a e m 7 g
# a e m 11 e
# a e m 11 g
# a m k 5 f
# a m k 11 e

#e) m k






