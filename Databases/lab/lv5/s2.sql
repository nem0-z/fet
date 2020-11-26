USE stusluZR;
#1
SELECT * FROM stud
WHERE stud.mbrStud NOT IN
(SELECT mbrStud FROM ispit WHERE ocjena = 1);

#2
SELECT nazMjesto FROM mjesto
WHERE mjesto.pbr IN
(SELECT DISTINCT pbrStan FROM nastavnik)
AND mjesto.pbr NOT IN
(SELECT DISTINCT pbrRod FROM stud);

#3
SELECT DISTINCT nazZupanija FROM zupanija
WHERE sifZupanija NOT IN
(SELECT sifZupanija FROM stud INNER JOIN mjesto ON stud.pbrStan = mjesto.pbr)
AND sifZupanija IN
(SELECT sifZupanija FROM stud INNER JOIN mjesto ON stud.pbrRod = mjesto.pbr);

#4
SELECT sifNastavnik, imeNastavnik, prezNastavnik FROM nastavnik
WHERE sifNastavnik NOT IN
(SELECT sifNastavnik FROM ispit
WHERE ocjena > 1
AND MONTH(datIspit) IN (1,2)
AND YEAR(datIspit) = 2000);

#5
SELECT pred.* FROM pred
WHERE sifOrgjed IN
(SELECT sifOrgjed FROM nastavnik
WHERE prezNastavnik LIKE 'O%');

#7
SELECT * FROM dvorana
WHERE kapacitet > 
(SELECT COUNT(DISTINCT sifPred) FROM rezervacija
WHERE rezervacija.oznDvorana = dvorana.oznDvorana);

#8
SELECT n1.*, m1.nazMjesto FROM nastavnik AS n1
INNER JOIN mjesto AS m1 ON m1.pbr = n1.pbrStan
WHERE koef < 
(SELECT AVG(koef) FROM nastavnik AS n2
INNER JOIN mjesto AS m2 ON m2.pbr = n2.pbrStan
WHERE m2.sifZupanija = m1.sifZupanija
AND n2.sifNastavnik != n1.sifNastavnik);s
