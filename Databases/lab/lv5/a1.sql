#VJEZBA
USE stusluZR;

SELECT * FROM pred WHERE upisanoStud <= ALL(SELECT kapacitet FROM dvorana);
SELECT * FROM pred WHERE upisanoStud <= ANY(SELECT kapacitet FROM dvorana);
SELECT * FROM pred WHERE upisanoStud > ALL(SELECT kapacitet FROM dvorana);
SELECT * FROM dvorana WHERE kapacitet > (SELECT AVG(kapacitet) FROM dvorana);
SELECT * FROM dvorana WHERE kapacitet = (SELECT MAX(kapacitet) FROM dvorana);
SELECT * FROM dvorana WHERE oznDvorana NOT IN (SELECT oznDvorana FROM rezervacija);
SELECT * FROM dvorana WHERE NOT EXISTS (SELECT * FROM ispit WHERE datIspit = CURRENT_DATE);
SELECT pred.* FROM pred WHERE brojSatiTjedno > (SELECT COUNT(DISTINCT oznVrstaDan) FROM rezervacija WHERE rezervacija.sifPred = pred.sifPred);
SELECT pred.* FROM pred WHERE NOT EXISTS(SELECT * FROM rezervacija WHERE rezervacija.sifPred = pred.sifPred);
SELECT D1.* FROM dvorana AS D1 WHERE kapacitet NOT IN(SELECT kapacitet FROM dvorana AS D2 WHERE D1.oznDvorana!= D2.oznDvorana);
SELECT stud.* FROM stud WHERE mbrStud NOT IN (SELECT DISTINCT mbrStud FROM ispit WHERE ocjena >= (SELECT AVG(ocjena) FROM ispit WHERE ocjena > 1));
SELECT mjesto.nazMjesto FROM mjesto WHERE pbr NOT IN (SELECT DISTINCT pbrRod FROM stud) AND pbr NOT IN (SELECT DISTINCT pbrStan FROM stud);
SELECT stud.* FROM stud
WHERE mbrStud NOT IN 
(SELECT mbrStud FROM ispit
INNER JOIN pred ON ispit.sifPred = pred.sifPred
INNER JOIN orgjed ON pred.sifOrgjed = orgjed.sifOrgjed
WHERE OCJENA > 1 AND nazOrgjed = 'Zavod za primijenjeno računarstvo');
SELECT kratPred, nazPred FROM pred
WHERE upisanoStud > 
(SELECT COUNT(*) FROM ispit 
WHERE ocjena > 1 
AND MONTH(datIspit) IN (1,2,3) 
AND YEAR(datIspit) = YEAR(CURRENT_DATE));
SELECT kratPred, nazPred FROM pred AS pred1
WHERE upisanoStud > 
(SELECT COUNT(*) FROM ispit
INNER JOIN pred AS pred2 ON pred2.sifPred = ispit.sifPred
WHERE ocjena > 1
AND pred2.sifOrgjed = pred1.sifOrgjed
AND pred2.sifPred != pred1.sifPred); #Ovaj zadnji red malo redundant no?

