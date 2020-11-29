USE stusluZR;

#1
CREATE UNIQUE INDEX ON pred(nazPred, sifOrgjed);

#2
CREATE TEMPORARY TABLE orgjedPred(
sifOrgjed INTEGER,
nazOrgjed CHAR(60),
sifNadorgjed INTEGER
);
CREATE UNIQUE INDEX sifra ON orgjedPred(sifOrgjed);
INSERT INTO orgjedPred
SELECT DISTINCT orgjed.sifOrgjed, nazOrgjed, sifNadorgjed 
FROM orgjed INNER JOIN pred
ON orgjed.sifOrgjed = pred.sifOrgjed;

CREATE TEMPORARY TABLE orgjedNast(
sifOrgjed INTEGER,
nazOrgjed CHAR(60),
sifNadorgjed INTEGER
);
CREATE UNIQUE INDEX sifra ON orgjedNast(sifOrgjed);
INSERT INTO orgjedNast
SELECT DISTINCT orgjed.sifORgjed, nazOrgjed, sifNadorgjed
FROM orgjed INNER JOIN nastavnik
ON orgjed.sifOrgjed = nastavnik.sifOrgjed;

#3
#Duplikat sprijeciti sa kreiranjem unique indexa
CREATE TEMPORARY TABLE foo(
p SERIAL NOT NULL
);
INSERT INTO foo VALUES
(-5);
SELECT * FROM foo;
#Range za SERIAL tip podatka je ocigledno [1,inf)
#Po defaultu SERIAL haman ne dozvoljava duplikate

#4
CREATE TEMPORARY TABLE nastTemp(
sifNastavnik INTEGER NOT NULL,
imeNastavnik CHAR(25),
prezNastavnik CHAR(25),
pbrStan INTEGER NOT NULL,
sifOrgjed INTEGER,
koef DECIMAL(3,2),
rbrNast SERIAL
);

INSERT INTO nastTemp
SELECT nastavnik.*, 0 FROM nastavnik;

SELECT * FROM nastTemp;

###################################################
###################################################

#5
UPDATE predT SET nazPred = CONCAT(kratPred,'-',nazPred);
#Iz nekog razloga oni ovdje koriste TRIM koji uklanja leading i trailing
#whitespaces kojih svakako nema u imenima i kraticama??!?!?

#6
UPDATE nasT SET koef = 0.9*koef
WHERE sifNastavnik IN 
(SELECT sifNastavnik FROM ispit
WHERE ocjena > 1
GROUP BY sifNastavnik
HAVING AVG(ocjena) < 2.2)
OR sifNastavnik IN 
(SELECT sifNastavnik FROM ispit
WHERE ocjena = 1
GROUP BY sifNastavnik
HAVING COUNT(ocjena) > 8);

#7
UPDATE predT SET brojSatiTjedno = brojSatiTjedno + 1
WHERE brojSatiTjedno BETWEEN 1 AND 4
AND sifPred IN
(SELECT sifPred FROM ispitT
WHERE DATE_ADD(datIspit, INTERVAL 35 YEAR) >= CURRENT_DATE
AND ocjena = 1 
AND sifPred = predT.sifPred
GROUP BY sifPred
HAVING COUNT(ocjena) > 10);

#8
UPDATE predT SET brojSatiTjedno = brojSatiTjedno - 1
WHERE sifPred IN
(SELECT sifPred FROM ispit
WHERE ocjena = 5
GROUP BY sifPred
HAVING COUNT(*) >= ALL(
SELECT COUNT(*) FROM ispit
WHERE ocjena = 5
GROUP BY sifPred));
#Mogli ste vala malo vise verbose ovo reci
#Ajd uglavnom oni hoce ovde da updateujemo predmete
#kod kojih ocjena 5 ima najvecu frekvenciju na ispitima et

#9
CREATE TEMPORARY TABLE maticniPostanski(
stariMbr INTEGER NOT NULL,
noviMbr INTEGER NOT NULL,
noviPbrStan INTEGER NOT NULL,
noviPbrRod INTEGER NOT NULL
);

LOAD DATA INFILE '/var/lib/mysql-files/konverzija.unl'
INTO TABLE maticniPostanski
FIELDS TERMINATED BY '#'
LINES TERMINATED BY '\n';

UPDATE studT SET 
mbrStud = (SELECT noviMbr FROM maticniPostanski
WHERE studT.mbrStud = stariMbr),
pbrStan = (SELECT noviPbrStan FROM maticniPostanski
WHERE studT.mbrStud = stariMbr),
pbrRod = (SELECT noviPbrRod FROM maticniPostanski
WHERE studT.mbrStud = stariMbr);

#10
DELETE FROM studT WHERE prezStud RLIKE '^[AEIOU]';

#11
DELETE FROM ispitT WHERE sifNastavnik IN
(SELECT sifNastavnik FROM nastavnik
INNER JOIN orgjed ON nastavnik.sifOrgjed = orgjed.sifOrgjed
WHERE nazOrgjed LIKE '%fiziku%');

DELETE FROM nasT WHERE sifOrgjed IN
(SELECT sifOrgjed FROM orgjed
WHERE nazOrgjed LIKE '%fiziku%');

#12
#inside initRef.sql



