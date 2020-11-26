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

SELECT mbrStud, imeStud, prezStud FROM stud
WHERE NOT EXISTS
(SELECT 1 FROM ispit WHERE ispit.mbrStud = stud.mbrStud
AND WEEKDAY(datIspit) = WEEKDAY(datRodStud)) #stavimo 1 jer nas u sustini boli briga *sta* je vratio
                                             #bitno nam je da li postoji ikakav red
                                             #mozemo na kraju dodati i 'limit 1' sto znaci cim nadjes 1 red bjezi
                                             #dovoljan nam je 1 red da skontamo jel ima ista ili nema nikako

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
CREATE TEMPORARY TABLE A1 AS
SELECT DISTINCT r12, r13 FROM r1;
CREATE TEMPORARY TABLE A2 AS
SELECT DISTINCT r31, r32 FROM r3;
SELECT A1.* FROM A1
INNER JOIN A2 ON A1.r12 = A2.r31
AND A1.r13 = A2.r32;

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

CREATE TEMPORARY TABLE D1 AS
SELECT * FROM r1 JOIN r2;

CREATE TEMPORARY TABLE D2 AS
SELECT * FROM r1 INNER JOIN r3
ON r1.r12 = r3.r31 AND r1.r13 = r3.r32;

SELECT * FROM D1
WHERE NOT EXISTS
(SELECT * FROM D2
WHERE D1.r11 = D2.r11
AND D1.r12 = D2.r12
AND D1.r13 = D2.r13
AND D1.r21 = D2.r33);


#e) m k

CREATE TEMPORARY TABLE r1(
r11 char,
r12 char,
r13 char
);
CREATE TEMPORARY TABLE r2(
r21 integer,
r22 char
);
CREATE TEMPORARY TABLE r3(
r31 char,
r32 char,
r33 integer,
r34 char
);

INSERT INTO r1 VALUES
('a','b','c'),
('a','d','k'),
('a','e','m'),
('a','m','k');

INSERT INTO r2 VALUES
(5,'f'),
(7,'g'),
(11,'e'),
(11,'g');

INSERT INTO r3 VALUES
('b','c',5,'f'),
('m','k',7,'g'),
('m','n',9,'e'),
('m','k',11,'g');








