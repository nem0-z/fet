use stusluZR;

#1
SELECT mbrStud, datPrijava, ocjObrane(mbrStud, datPrijava) FROM diplom;
SELECT diplom.mbrStud, prezStud, imeStud, ocjObrane(diplom.mbrStud, datPrijava) FROM diplom
INNER JOIN stud ON stud.mbrStud = diplom.mbrStud
WHERE ocjObrane(diplom.mbrStud, datPrijava) = 1;
SELECT AVG(ocjObrane(mbrStud, datPrijava)) FROM diplom
WHERE ocjObrane(mbrStud, datPrijava) > 1;

#2
DELIMITER /
CREATE FUNCTION prosjekOcjena()
RETURNS DECIMAL(3,2)
BEGIN
	DECLARE ret DECIMAL(3,2);
    SELECT AVG(ocjena) INTO ret FROM ispit
    WHERE ocjena > 1;
    RETURN ret;
END/

CREATE FUNCTION brojNepristup()
RETURNS INTEGER
BEGIN
	DECLARE ret INTEGER;
    IF @counter IS NULL THEN
		SET @counter = 0;
	END IF;
    IF @counter > 0 THEN
		RETURN NULL;
	END IF;
    SELECT COUNT(*) INTO ret FROM stud
    WHERE mbrStud NOT IN (SELECT mbrStud FROM ispit);
    SET @counter = @counter + 1;
    RETURN ret;
END/

CREATE FUNCTION vrijemePrvogPoziva()
RETURNS VARCHAR(100)
BEGIN
	DECLARE ret CHAR(100);
    DECLARE cur DATETIME;
    IF @firstTime IS NULL THEN
		SET @firstTime = SYSDATE();
	END IF;
    SET cur = SYSDATE();
    SET ret = CONCAT(@firstTime, '   ', cur);
    RETURN ret;
END/

#3
CREATE PROCEDURE najboljih_n(IN n INTEGER)
BEGIN
	SELECT stud.mbrStud, prezStud, imeStud, AVG(ocjena) FROM stud
    INNER JOIN ispit ON stud.mbrStud = ispit.mbrStud
    GROUP BY 1, 2, 3
    ORDER BY 4 DESC, 2, 3
    LIMIT n;
END/

DELIMITER ;
DROP PROCEDURE IF EXISTS najboljih_n;
SELECT prosjekOcjena();
SELECT brojNepristup();
SELECT vrijemePrvogPoziva();
CALL najboljih_n(10);