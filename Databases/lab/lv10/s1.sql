USE stusluZR;


#1
SELECT mbrstud, datprijava, ocjObrane(mbrstud, datprijava) from diplom;

SELECT mbrstud, prezstud, imestud , ocjObrane(mbrstud, datprijava) from stud
INNER JOIN diplom ON diplom.mbrstud=stud.mbrstud
WHERE ocjObrane(mbrstud, datprijava)>1;

SELECT avg(ocjObrane(mbrstud, datprijava)) FROM diplom
WHERE ocjObrane(mbrstud, datprijava)>1;


#2

DELIMITER ++++
CREATE FUNCTION prosjekOcjena()
RETURNS DECIMAL(3,2)
DETERMINISTIC
BEGIN
    DECLARE ret DECIMAL(3,2);
	SET @p1 = @p1 + 1;
	IF @p1 > 1 THEN
		RETURN NULL;
	END IF;
    SELECT AVG(ocjena) INTO ret FROM ispit WHERE ocjena > 1;
    RETURN ret;
END 
++++

CREATE FUNCTION brojNepristup()
RETURNS INTEGER
DETERMINISTIC
BEGIN
	DECLARE ret INTEGER;
    SET @p2 = @p2 + 1;
    IF @p2 > 1 THEN
		RETURN NULL;
	END IF;
    SELECT COUNT(stud.mbrStud) INTO ret FROM stud
    WHERE stud.mbrStud NOT IN (SELECT mbrStud FROM ispit);
	RETURN ret;
END
++++

CREATE FUNCTION vrijemePrvogPoziva()
RETURNS DATETIME
DETERMINISTIC
BEGIN
	DECLARE ret DATETIME DEFAULT NULL;
    IF @p3 IS NULL THEN
		SELECT SYSDATE() INTO ret;
        SET @p3 = ret;
	ELSE 
		SET ret = SYSDATE();
	END IF;
    RETURN ret;
END
++++

#3
CREATE PROCEDURE najboljih_n(IN n INTEGER)
BEGIN
	SELECT ispit.mbrStud, prezStud, imeStud, AVG(ocjena) FROM ispit
    INNER JOIN stud ON stud.mbrStud = ispit.mbrStud 
	GROUP BY 1, 2, 3
    ORDER BY 4 DESC, 2, 3
    LIMIT n;
END
++++

DELIMITER ;
DROP FUNCTION IF EXISTS vrijemePrvogPoziva;
DROP PROCEDURE IF EXISTS najboljih_n;
SET @p1 = 0;
SET @p2 = 0;
SET @p3 = NULL;

SELECT prosjekOcjena(), brojNepristup();
SELECT vrijemePrvogPoziva();
CALL najboljih_n(150);