USE stusluZR;

#1
DELIMITER /
CREATE PROCEDURE orgjedNast(IN sifra INTEGER)
BEGIN
	SELECT CONCAT(imeNastavnik,' ',prezNastavnik,': ',
				  p.nazOrgjed,', ',n.nazOrgjed) AS data FROM nastavnik
	INNER JOIN orgjed AS p ON nastavnik.sifOrgjed = p.sifOrgjed
    INNER JOIN orgjed AS n ON p.sifNadorgjed = n.sifOrgjed
    WHERE sifNastavnik = sifra;
END/

#2
CREATE FUNCTION noviKoef(sifra INTEGER)
RETURNS DECIMAL(3,2)
BEGIN
	DECLARE koef DECIMAL(3,2);
    DECLARE brojPoz, brojNeg INTEGER;
    DECLARE prosjecnaPozitivni, ukupnaProsjecna DECIMAL(3,2);
    SELECT COUNT(*) INTO brojPoz FROM ispit
    WHERE ocjena > 1 AND sifNastavnik = sifra;
    SELECT COUNT(*) INTO brojNeg FROM ispit
    WHERE ocjena = 1 AND sifNastavnik = sifra;
    SELECT AVG(ocjena) INTO prosjecnaPozitivni FROM ispit
    WHERE ocjena > 1 AND sifNastavnik = sifra;
    SELECT AVG(ocjena) INTO ukupnaProsjecna FROM ispit
    WHERE ocjena >  1;
    SET koef = (SELECT koef FROM nastavnik WHERE sifNastavnik = sifra);
	IF brojPoz > brojNeg AND prosjecnaPozitivni > ukupnaProsjecna THEN
		SET koef = koef*1.1;
	ELSEIF brojNeg > brojPoz AND prosjecnaPozitivni < ukupnaProsjecna THEN
		SET koef = koef*0.9;
	END IF;
    RETURN koef;
END/

#3
CREATE FUNCTION ocjObrane(matBroj INTEGER, datum DATE)
RETURNS INTEGER
BEGIN
	DECLARE tmp, tmp1, ocjena INTEGER;
    SELECT mbrStud INTO tmp FROM diplom
    WHERE mbrStud = matBroj AND datum = datPrijava;
    IF tmp IS NULL THEN
		RETURN NULL;
	END IF; #Ako nema prijave
    SELECT ocjenaRad INTO tmp FROM diplom
    WHERE mbrStud = matBroj AND datum = datPrijava;
    IF tmp = 1 THEN 
		RETURN 1;
	END IF; #Ako je dobio 1 od mentora
    DROP TEMPORARY TABLE IF EXISTS usmeni;
    CREATE TEMPORARY TABLE usmeni AS
    SELECT ocjenaUsm FROM dipkom
    WHERE mbrStud = matBroj AND datum = datPrijava;
    SELECT 1 INTO tmp FROM usmeni
    WHERE ocjenaUsm = 1 LIMIT 1;
    IF tmp = 1 THEN
		RETURN 1;
	END IF; #Ako je dobio 1 na usmenom od komisije
    SELECT 1 INTO tmp FROM usmeni
    WHERE ocjenaUsm IS NULL;
    SELECT 1 INTO tmp1 FROM diplom
    WHERE mbrStud = matBroj AND datPrijava = datum AND ocjenaRad IS NULL;
    IF tmp = 1 OR tmp1 = 1 THEN
		RETURN 0;
	END IF; #Ako nisu upisane sve ocjene
    SELECT ROUND(AVG(ocjenaUsm)) INTO ocjena FROM usmeni;
    RETURN ocjena;
END/

DELIMITER ; 
DROP TABLE IF EXISTS usmeni;
DROP PROCEDURE IF EXISTS orgjedNast;
DROP FUNCTION IF EXISTS ocjObrane;
CALL orgjedNast(244);
SELECT *, ocjObrane(mbrStud, datPrijava) FROM diplom
ORDER BY mbrStud, datPrijava;
