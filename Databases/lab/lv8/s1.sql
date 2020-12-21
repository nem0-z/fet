USE stusluZR;
START TRANSACTION;
SET autocommit = 0;
ALTER TABLE nastavnik MODIFY sifOrgjed INTEGER;
ALTER TABLE nastavnik MODIFY pbrStan INTEGER;
ALTER TABLE nastavnik ADD CONSTRAINT FOREIGN KEY (sifOrgjed) REFERENCES orgjed (sifOrgjed);
ALTER TABLE nastavnik ADD CONSTRAINT FOREIGN KEY (pbrStan) REFERENCES mjesto (pbr);

#1
UPDATE nastavnik SET siforgjed = NULL
WHERE siforgjed IN
(SELECT siforgjed FROM orgjed 
WHERE nazorgjed = 'Zavod za primijenjenu fiziku');

UPDATE pred SET siforgjed = NULL
WHERE siforgjed IN
(SELECT siforgjed FROM orgjed 
WHERE nazorgjed = 'Zavod za primijenjenu fiziku');

UPDATE orgjed SET sifnadorgjed = NULL
WHERE nazorgjed = 'Zavod za primijenjenu fiziku';

DELETE FROM orgjed WHERE
nazorgjed = 'Zavod za primijenjenu fizku';

#2
UPDATE nastavnik SET pbrStan = NULL
WHERE prezNastavnik LIKE 'J%' AND imeNastavnik LIKE 'D%';

#3
SELECT COUNT(*) FROM nastavnik
WHERE pbrStan IS NULL OR sifOrgjed IS NULL;

#4
#a
SELECT COUNT(*) FROM pred
WHERE sifOrgjed = 100002;

#b
SELECT COUNT(*) FROM pred
WHERE sifOrgjed != 100002;

#c
SELECT COUNT(*) FROM pred;
#a+b nije jednako c zato jer count ne uzima u obzir NULL vrijednosti, a imaju dvije

#5
SELECT * FROM pred 
WHERE sifOrgjed IS NOT NULL;

#6
SELECT * FROM pred
WHERE sifOrgjed IS NULL;

#7
SELECT COUNT(*) FROM pred
WHERE sifOrgjed IS NOT NULL;

#8
SELECT COUNT(DISTINCT sifOrgjed) FROM nastavnik;

#9
SELECT brojSatiTjedno, sifOrgjed, COUNT(*) FROM pred
GROUP BY 1, 2;

#10
SELECT * FROM stud
WHERE pbrStan NOT IN
(SELECT pbrRod FROM stud
WHERE pbrRod IS NOT NULL);

#11
SELECT sifNastavnik, prezNastavnik, imeNastavnik,
nastavnik.sifOrgjed, orgjed.nazOrgjed FROM nastavnik
LEFT JOIN orgjed ON nastavnik.sifOrgjed = orgjed.sifOrgjed;

#12
SELECT sifNastavnik, prezNastavnik, imeNastavnik,
nastavnik.sifOrgjed, org.nazOrgjed, nad.nazOrgjed 
FROM nastavnik
LEFT JOIN (orgjed AS org INNER JOIN orgjed AS nad
ON org.sifNadorgjed = nad.sifOrgjed)
ON nastavnik.sifOrgjed = org.sifOrgjed;

#13
SELECT sifNastavnik, prezNastavnik, imeNastavnik,
pbrStan, nazMjesto, nastavnik.sifOrgjed, orgjed.nazOrgjed
FROM nastavnik
LEFT JOIN mjesto ON nastavnik.pbrStan = mjesto.pbr
LEFT JOIN orgjed ON nastavnik.sifOrgjed = orgjed.sifOrgjed
ORDER BY nazMjesto, prezNastavnik;

#14
SELECT sifNastavnik, prezNastavnik, imeNastavnik,
pbrStan, nazMjesto, nazZupanija
FROM nastavnik
LEFT JOIN mjesto ON nastavnik.pbrStan = mjesto.pbr
LEFT JOIN zupanija ON mjesto.sifZupanija = zupanija.sifzupanija;

#15
SELECT kratPred, nazPred, pred.sifOrgjed, nazOrgjed
FROM pred
LEFT JOIN orgjed ON pred.sifOrgjed = orgjed.sifOrgjed
WHERE nazPred LIKE 'F%';

#16
SELECT pred.* FROM pred
LEFT JOIN orgjed ON pred.sifOrgjed = orgjed.sifOrgjed
WHERE nazOrgjed LIKE 'Z%' OR nazOrgjed IS NULL;

ROLLBACK WORK;