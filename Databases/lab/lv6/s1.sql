#1
SELECT kratPred, nazPred, AVG(ocjena)
FROM pred INNER JOIN ispit ON pred.sifpred = ispit.sifpred
WHERE ocjena > 1
GROUP BY ispit.sifPred, 2, 1;

#2
SELECT zupanija.sifZupanija, COUNT(ocjena)
FROM zupanija INNER JOIN mjesto ON zupanija.sifZupanija = mjesto.sifZupanija
INNER JOIN nastavnik ON nastavnik.pbrStan = mjesto.pbr
INNER JOIN ispit ON nastavnik.sifNastavnik = ispit.sifNastavnik
WHERE ocjena = 1
GROUP BY sifZupanija;

#3
SELECT imeNastavnik, COUNT(ocjena)
FROM nastavnik INNER JOIN ispit ON nastavnik.sifNastavnik = ispit.sifNastavnik
WHERE ocjena > 1
GROUP BY nastavnik.sifNastavnik, 1;

#4
SELECT nadredjena.sifOrgjed, nadredjena.nazOrgjed, COUNT(podredjena.sifOrgjed)
FROM orgjed AS nadredjena INNER JOIN 
orgjed AS podredjena ON podredjena.sifNadorgjed = nadredjena.sifOrgjed 
GROUP BY 1,2;

#5
SELECT stud.*, AVG(ocjena) FROM stud
INNER JOIN ispit ON stud.mbrStud = ispit.mbrStud
WHERE ocjena > 1
GROUP BY 1,2,3,4,5,6,7
HAVING AVG(ocjena) > 3;

#6
SELECT pbr, nazMjesto, COUNT(stud.mbrStud)
FROM mjesto INNER JOIN stud ON stud.pbrRod = mjesto.pbr
GROUP BY 1, 2
HAVING COUNT(stud.mbrStud) > 5;
  
#7
SELECT stud.mbrStud, stud.prezStud,
CONCAT(SUBSTRING(imeStud, 1, 1), '.', SUBSTRING(prezStud, 1, 1), '.') AS Inicijali
FROM stud INNER JOIN ispit ON stud.mbrStud = ispit.mbrStud
WHERE ocjena = 1
GROUP BY 1, 2, ispit.sifPred
HAVING COUNT(ocjena) >= 3;

#8

#a
SELECT mbrStud, ocjena FROM ispit
GROUP BY mbrStud, ocjena
HAVING COUNT(DISTINCT datIspit) > 1;

#b
SELECT pbr, sifZupanija FROM mjesto
GROUP BY pbr, sifZupanija
HAVING COUNT(DISTINCT nazMjesto) > 1;

#c ma isto sve

#d
SELECT sifPred, datIspit, ocjena FROM ispit
GROUP BY 1, 2, 3
HAVING COUNT(DISTINCT mbrStud) > 1 AND COUNT(DISTINCT sifNastavnik) > 1;

#9
SELECT mjesto.pbr, mjesto.nazMjesto, COUNT(ocjena)
FROM mjesto INNER JOIN stud ON mjesto.pbr = stud.pbrStan
INNER JOIN ispit ON ispit.mbrStud = stud.mbrStud
WHERE ocjena > 1
GROUP BY 1, 2
ORDER BY mjesto.nazMjesto;

#10
SELECT prezStud, imeStud, COUNT(ocjena) AS polozeni FROM stud
INNER JOIN ispit ON stud.mbrStud = ispit.mbrStud
WHERE ocjena > 1
GROUP BY 1, 2, ispit.mbrStud
ORDER BY polozeni DESC, prezStud, imeStud;

#11
CREATE TEMPORARY TABLE mjestoTmp AS
SELECT mjesto.*, COUNT(nastavnik.sifNastavnik) as brojNast
FROM mjesto INNER JOIN nastavnik ON mjesto.pbr = nastavnik.pbrStan
GROUP BY 1, 2, 3;

SELECT * FROM mjestoTmp;

#12
SELECT MONTH(datRodStud) as Mjesec, COUNT(stud.mbrStud) AS broj FROM stud
GROUP BY 1
ORDER BY broj DESC;

#13
SELECT s1.* FROM stud AS s1
INNER JOIN ispit ON s1.mbrStud = ispit.mbrStud
WHERE ocjena > 1
GROUP BY 1, 2, 3, 4, 5, 6, 7
HAVING AVG(ocjena) > 
(SELECT AVG(ocjena) FROM ispit 
WHERE ispit.mbrStud != s1.mbrStud)
OR COUNT(ocjena) >
(SELECT COUNT(ocjena) FROM stud
INNER JOIN ispit ON stud.mbrStud = ispit.mbrStud
WHERE ocjena > 1 AND stud.mbrStud != s1.mbrStud)
/
(SELECT COUNT(*) FROM stud
WHERE stud.mbrStud != s1.mbrStud); #check this


