USE stusluZR;

CREATE TABLE diplom (
	mbrStud INTEGER NOT NULL,
    datPrijava DATE NOT NULL,
    sifMentor INTEGER,
    ocjenaRad SMALLINT,
    datObrana DATE,
    ukupOcjena SMALLINT,
    PRIMARY KEY (mbrStud, datPrijava), 
    FOREIGN KEY (mbrStud) REFERENCES stud (mbrStud),
    FOREIGN KEY (sifMentor) REFERENCES nastavnik (sifNastavnik)
);

CREATE TABLE dipkom (
	mbrStud INTEGER NOT NULL,
    datPrijava DATE NOT NULL,
    sifNastavnik INTEGER NOT NULL,
    oznUloga CHAR(1),
    ocjenaUsm SMALLINT,
    PRIMARY KEY (mbrStud, datPrijava, sifNastavnik),
    FOREIGN KEY (mbrStud, datPrijava) REFERENCES diplom (mbrStud, datPrijava),
    FOREIGN KEY (mbrStud) REFERENCES stud (mbrStud),
    FOREIGN KEY (sifNastavnik) REFERENCES nastavnik (sifNastavnik)
);

LOAD DATA INFILE '/var/lib/mysql-files/tmp/diplom.unl' INTO TABLE diplom 
FIELDS TERMINATED BY '#'
LINES STARTING BY '\n' TERMINATED BY '#\r';

LOAD DATA INFILE '/var/lib/mysql-files/tmp/dipkom.unl' INTO TABLE dipkom
FIELDS TERMINATED BY '#'
LINES STARTING BY '\n' TERMINATED BY '#\r';

#1
DELIMITER ++++
CREATE PROCEDURE orgjedNast(IN sifNast INTEGER)
BEGIN
	SELECT CONCAT(imeNastavnik, ' ', prezNastavnik, ': ', p.nazOrgjed, ', ', n.nazOrgjed)
	FROM nastavnik
	INNER JOIN orgjed AS p ON p.sifOrgjed = nastavnik.sifOrgjed
    INNER JOIN orgjed AS n ON p.sifNadorgjed = n.sifOrgjed
    WHERE sifNastavnik = sifNast;
END 
++++

#2
CREATE FUNCTION noviKoef(sifNast INTEGER)
RETURNS DECIMAL(3,2)
DETERMINISTIC
BEGIN
	DECLARE pozIspiti, negIspiti INTEGER;
    DECLARE avgPass, avgTotal, noviKoef DECIMAL(3,2); 
    
		SELECT COUNT(ocjena) INTO pozIspiti
		FROM ispit WHERE ocjena > 1 AND sifNastavnik = sifNast;
        
        SELECT COUNT(ocjena) INTO negIspiti
		FROM ispit WHERE ocjena = 1 AND sifNastavnik = sifNast;
        
        SELECT AVG(ocjena) INTO avgPass
		FROM ispit WHERE ocjena > 1 AND sifNastavnik = sifNast;
        
        SELECT AVG(ocjena) INTO avgTotal
		FROM ispit WHERE ocjena > 1;
    
    SELECT koef INTO noviKoef FROM nastavnik
    WHERE sifNastavnik = sifNast;
    
	IF pozIspiti > negIspiti AND avgPass > avgTotal THEN
		SET noviKoef = noviKoef * 1.1;
    ELSEIF negIspiti > pozIspiti AND avgPass < avgTotal THEN
		SET noviKoef = noviKoef * 0.9;
    END IF;
    RETURN noviKoef;
END
++++

#3
CREATE FUNCTION ocjObrane (matBrStud INT, datumPrijave DATE)
RETURNS INTEGER
DETERMINISTIC
BEGIN
	DECLARE tmp, ocjenaNull, ocjenaJedan, tmp2, total INTEGER;
    
	SELECT COUNT(mbrStud) INTO tmp FROM diplom
    WHERE mbrStud = matBrStud AND datPrijava = datumPrijave;
    
    CREATE TEMPORARY TABLE ocjene AS
    SELECT ocjenaRad, ocjenaUsm FROM diplom
    RIGHT JOIN dipkom ON diplom.mbrStud = dipkom.mbrStud
    AND dipkom.datPrijava = diplom.datPrijava
    WHERE diplom.mbrStud = matBrStud
    AND diplom.datPrijava = datumPrijave;
    
    SELECT 1 INTO tmp2 FROM ocjene
    WHERE ocjenaRad = 1 OR ocjenaUsm = 1
    AND ocjenaRad IS NOT NULL AND ocjenaUsm IS NOT NULL;
    
    SELECT 1 INTO ocjenaNull FROM ocjene
    WHERE ocjenaRad IS NULL OR ocjenaUsm IS NULL;    
    
    IF tmp != 0 THEN #nema unosa
		SET total = NULL; 
	ELSEIF ocjenaNull = 1 AND tmp2 != 1 THEN
		SET total = 0;
	ELSEIF ocjenaNull = 1 THEN
		SET total = 1;
	ELSE 
		SET total = (SELECT ROUND(AVG(ocjenaUsm)) FROM ocjene);
    END IF;
    RETURN total;
END;
++++

DELIMITER ;
DROP PROCEDURE ocjObrane;
DROP FUNCTION ocjObrane;
DROP TABLE ocjene;
CALL orgjedNast(244);

SELECT noviKoef(277); -- stari 3.50, novi 3.85
SELECT noviKoef(289); -- stari 4.70, novi 4.70
SELECT noviKoef(460); -- stari 3.90, novi 3.51

call ocjObrane(1127, '2045-01-21', @total);
select @total;
select ocjObrane(1127, '2045-01-21');

SELECT *, ocjObrane(mbrStud, datPrijava) FROM diplom
ORDER BY mbrStud, datPrijava;
