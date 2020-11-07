USE stusluZR;

#vjezba av4
SELECT stud.imeStud, stud.prezStud, 
nastavnik.imeNastavnik, nastavnik.prezNastavnik,
pred.nazPred, ispit.ocjena
FROM ispit 
INNER JOIN stud ON ispit.mbrStud = stud.mbrStud
INNER JOIN nastavnik ON ispit.sifNastavnik = nastavnik.sifNastavnik
INNER JOIN pred ON ispit.sifPred = pred.sifPred
WHERE ocjena > 1;

SELECT DISTINCT imeNastavnik, prezNastavnik
FROM ispit
INNER JOIN nastavnik ON ispit.sifNastavnik = nastavnik.sifNastavnik
INNER JOIN stud ON ispit.mbrStud = stud.mbrStud
INNER JOIN mjesto ON stud.pbrRod = mjesto.pbr
WHERE ocjena = 1 AND nazMjesto LIKE 'T%' AND nazMjesto RLIKE '[aeiou]$';

SELECT imeStud, prezStud, bornZupanija.nazZupanija, liveZupanija.nazZupanija
FROM stud 
INNER JOIN mjesto AS bornMjesto ON stud.pbrRod = bornMjesto.pbr
INNER JOIN mjesto AS liveMjesto ON stud.pbrStan = liveMjesto.pbr
INNER JOIN zupanija as bornZupanija ON bornMjesto.sifZupanija = bornZupanija.sifZupanija
INNER JOIN zupanija AS liveZupanija ON liveMjesto.sifZupanija = liveZupanija.sifZupanija
WHERE MONTH(datRodStud) = 5 AND YEAR(datRodStud) = 1982;

SELECT imeNastavnik, prezNastavnik, nMjesto.nazMjesto, sMjesto.nazMjesto
FROM nastavnik 
INNER JOIN mjesto AS nMjesto ON nastavnik.pbrStan = nMjesto.pbr
INNER JOIN ispit ON ispit.sifNastavnik = nastavnik.sifNastavnik
INNER JOIN stud ON ispit.mbrStud = stud.mbrStud
INNER JOIN mjesto AS sMjesto ON stud.pbrRod = sMjesto.pbr
WHERE nMjesto.nazMjesto != sMjesto.nazMjesto AND nMjesto.sifZupanija = sMjesto.sifZupanija;

SELECT imeNastavnik, prezNastavnik, koef
FROM nastavnik
INNER JOIN orgjed AS orgJ ON nastavnik.sifOrgjed = orgJ.sifOrgjed
INNER JOIN orgjed AS nadorgJ ON orgJ.sifNadOrgjed = nadorgJ.sifOrgjed
WHERE nadorgJ.nazOrgjed LIKE '%matike%';

SELECT DISTINCT nOrgJed.sifOrgjed, nOrgJed.nazOrgjed
FROM orgjed AS orgJed
INNER JOIN orgjed AS nOrgJed ON orgJed.sifNadorgjed = nOrgJed.sifOrgjed
INNER JOIN pred ON pred.sifOrgjed = nOrgJed.sifOrgjed
INNER JOIN ispit ON ispit.sifPred = pred.sifPred
WHERE upisanoStud > 20 AND ocjena=1;

#1
SELECT CONCAT(SUBSTRING(imeStud,1,1)) AS Inicijal, prezStud,
SUBSTRING(nazPred,1,25) AS Predmet, datIspit
FROM stud
INNER JOIN ispit ON stud.mbrStud = ispit.mbrStud
INNER JOIN pred ON ispit.sifPred = pred.sifPred
WHERE ocjena = 5;

#2 
SELECT podJed.sifOrgjed, podJed.nazOrgjed
FROM orgjed AS nadJed
INNER JOIN orgjed AS podJed ON nadJed.sifNadorgjed = podJed.sifOrgjed
WHERE nadJed.nazOrgjed LIKE '%matem%';

#3
SELECT nazPred, kratPred
FROM pred
INNER JOIN orgjed AS podJed ON pred.sifOrgjed = podJed.sifOrgjed
INNER JOIN orgjed AS nadJed ON podJed.sifNadorgjed = nadJed.sifOrgjed
WHERE nadJed.nazOrgjed LIKE '%tehnike%';

#4 
SELECT nazOrgjed
FROM orgjed
INNER JOIN pred ON orgjed.sifOrgjed = pred.sifOrgjed
INNER JOIN ispit ON ispit.sifPred = pred.sifPred
INNER JOIN nastavnik ON ispit.sifNastavnik = nastavnik.sifNastavnik
INNER JOIN mjesto ON nastavnik.pbrStan = mjesto.pbr
INNER JOIN zupanija ON mjesto.sifZupanija = zupanija.sifZupanija
WHERE MONTH(datIspit) = 5 
AND YEAR(datIspit) = 2000 
AND nazZupanija = 'Dubrovačko-neretvanska';

#5
SELECT DISTINCT stud.*
FROM stud
INNER JOIN ispit ON stud.mbrStud = ispit.mbrStud
INNER JOIN nastavnik ON ispit.sifNastavnik = nastavnik.sifNastavnik
INNER JOIN mjesto ON nastavnik.pbrStan = mjesto.pbr
INNER JOIN zupanija ON mjesto.sifZupanija = zupanija.sifZupanija
WHERE ocjena = 1 AND nazZupanija = 'Osječko-baranjska';

#6
SELECT SUM(upisanoStud) 
FROM pred 
INNER JOIN orgjed AS podJed ON pred.sifOrgjed = podJed.sifOrgjed
INNER JOIN orgjed AS nadJed ON podJed.sifNadorgjed = nadJed.sifOrgjed
WHERE nadJed.nazOrgjed = 'Fakultet elektrotehnike i računarstva';

#7
SELECT imeNastavnik, prezNastavnik, nazOrgjed
FROM nastavnik 
INNER JOIN orgjed ON nastavnik.sifOrgjed = orgjed.sifOrgjed;

#8
SELECT imeStud, prezStud, stanMjesto.nazMjesto, rodMjesto.nazMjesto, rodZupanija.nazZupanija
FROM stud
INNER JOIN mjesto AS stanMjesto ON stud.pbrStan = stanMjesto.pbr
INNER JOIN mjesto AS rodMjesto ON stud.pbrRod = rodMjesto.pbr
INNER JOIN zupanija AS rodZupanija ON rodMjesto.sifZupanija = rodZupanija.sifZupanija;

#9
SELECT COUNT(ocjena)
FROM ispit
INNER JOIN nastavnik ON ispit.sifNastavnik = nastavnik.sifNastavnik
INNER JOIN mjesto ON nastavnik.pbrStan = mjesto.pbr
WHERE ocjena = 1 AND nazMjesto LIKE 'Z%';

#10
SELECT COUNT(DISTINCT nastavnik.sifNastavnik)
FROM nastavnik
INNER JOIN orgjed ON nastavnik.sifOrgjed = orgjed.sifOrgjed
INNER JOIN ispit ON nastavnik.sifNastavnik = ispit.sifNastavnik
WHERE ocjena > 1 AND nazOrgjed = 'Zavod za primijenjenu matematiku';

#11 ????
SELECT dvorana.oznDvorana, dvorana.kapacitet
FROM rezervacija
INNER JOIN dvorana ON rezervacija.oznDvorana = dvorana.oznDvorana
INNER JOIN pred ON rezervacija.sifPred = pred.sifPred
WHERE nazPred = 'Energetska elektronika-izabrana poglavlja'
AND oznVrstaDan IN ('PO', 'SR', 'PE');

#12
SELECT DISTINCT nazOrgjed
FROM orgjed
INNER JOIN nastavnik ON orgjed.sifOrgjed = nastavnik.sifOrgjed;

#13
SELECT COUNT(DISTINCT sifPred)
FROM rezervacija
INNER JOIN dvorana ON rezervacija.oznDvorana = dvorana.oznDvorana
WHERE kapacitet <= 60;

#14
SELECT DISTINCT rodMjesto.nazMjesto
FROM stud 
INNER JOIN mjesto AS rodMjesto ON stud.pbrRod = rodMjesto.pbr
INNER JOIN mjesto AS stanMjesto ON stud.pbrStan = stanMjesto.pbr
WHERE stanMjesto.nazMjesto = rodMjesto.nazMjesto;

#15
SELECT imeStud, prezStud, rodMjesto.nazMjesto, stanMjesto.nazMjesto
FROM stud
INNER JOIN mjesto AS rodMjesto ON stud.pbrRod = rodMjesto.pbr
INNER JOIN mjesto AS stanMjesto ON stud.pbrStan = stanMjesto.pbr
INNER JOIN ispit ON stud.mbrStud = ispit.mbrStud
INNER JOIN pred ON ispit.sifPred = pred.sifPred
WHERE nazPred = 'Elektronički sklopovi' AND ocjena > 1;

#16
SELECT DISTINCT stud.* 
FROM stud
INNER JOIN mjesto AS rodMjesto ON stud.pbrRod = rodMjesto.pbr
INNER JOIN mjesto AS stanMjesto ON stud.pbrStan = stanMjesto.pbr
INNER JOIN zupanija AS rodZupanija ON rodMjesto.sifZupanija = rodZupanija.sifZupanija
INNER JOIN zupanija AS stanZupanija ON stanMjesto.sifZupanija = stanZupanija.sifZupanija
WHERE rodMjesto.pbr!= stanMjesto.pbr
AND rodZupanija.sifZupanija = stanZupanija.sifZupanija;

#17
SELECT nastavnik.*
FROM nastavnik
INNER JOIN ispit ON nastavnik.sifNastavnik = ispit.sifNastavnik
INNER JOIN stud ON ispit.mbrStud = stud.mbrStud
INNER JOIN mjesto AS nMjesto ON nastavnik.pbrStan = nMjesto.pbr
INNER JOIN mjesto AS sMjesto ON stud.pbrStan = sMjesto.pbr
WHERE sMjesto.sifZupanija = nMjesto.sifZupanija;

#18
SELECT S2.imeStud, S2.prezStud, S1.imeStud, S1.prezStud
FROM stud AS S1 JOIN stud AS S2
WHERE S1.imeStud LIKE 'K%' AND S1.prezStud LIKE 'K%'
AND S2.imeStud LIKE 'K%' AND S2.prezStud LIKE 'K%'
AND S1.mbrStud != S2.mbrStud;
