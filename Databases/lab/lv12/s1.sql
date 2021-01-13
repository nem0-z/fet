USE stusluZR;

DELIMITER //
CREATE PROCEDURE test1 ()
BEGIN
	DECLARE kod CHAR(5);
	DECLARE poruka TEXT;
	DECLARE rezultat TEXT;
	DECLARE EXIT HANDLER FOR SQLEXCEPTION
	BEGIN
		GET DIAGNOSTICS CONDITION 1
		kod = RETURNED_SQLSTATE, poruka = MESSAGE_TEXT;
		SET rezultat = CONCAT('greska = ',kod,', poruka = ',poruka);
	END;
	BEGIN
		SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Pogreska 1000',
		MYSQL_ERRNO = 1000;
		SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Pogreska 1001',
		MYSQL_ERRNO = 1001;
	END;
	SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Pogreska 1002',
	MYSQL_ERRNO = 1002;
	SELECT rezultat;
END//

DELIMITER ;
DROP PROCEDURE IF EXISTS test1;

CALL test1;

#Tema 2

#Z1
#a
GRANT SELECT ON mjesto TO 'haso'@'%'; #...

#b
GRANT SELECT(imeStud, prezStud, jmbgStud) ON stud TO 'haso'@'%';

#c
CREATE VIEW pozIspiti AS
SELECT * FROM ispit
WHERE ocjena > 1;

GRANT SELECT ON pozIspiti TO 'haso'@'%';

#d
CREATE VIEW negIspiti AS
SELECT COUNT(*) FROM ispit
WHERE ocjena = 1 
GROUP BY sifPred;

GRANT SELECT ON negIspiti TO 'haso'@'%';

#e
GRANT EXECUTE ON FUNCTION ocjObrane TO 'haso'@'%';

#f
GRANT INSERT, UPDATE, DELETE ON mjesto TO 'haso'@'%';

#g
GRANT UPDATE(nazZupanija) ON zupanija TO 'haso'@'%';

#h
CREATE VIEW nastavnik100006 AS
SELECT * FROM nastavnik
WHERE sifOrgjed = 100006;

GRANT INSERT, UPDATE, DELETE ON nastavnik100006 TO 'haso'@'%';

#Z2
DELIMITER //
CREATE DEFINER=`nem0-z`@`localhost` PROCEDURE `boljaAzurDiplom`()
BEGIN
	DECLARE tempMbr, tempOcjena INTEGER;
    DECLARE tempDatum DATE;
    DECLARE kod CHAR(5);
    DECLARE poruka TEXT;
    DECLARE done BOOL DEFAULT FALSE;
    DECLARE c CURSOR FOR SELECT mbrStud, datPrijava FROM diplom;
	DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;
    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
			GET DIAGNOSTICS CONDITION 1
            kod = RETURNED_SQLSTATE;
            ROLLBACK;
            IF kod = '45000' THEN 
				SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = poruka;
			ELSE 
				RESIGNAL;
			END IF;
    END;
    SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;
    START TRANSACTION;
    BEGIN
		DECLARE EXIT HANDLER FOR 1027, 1099, 1205, 1213, 1223, 1614, 1689
        BEGIN
			SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = poruka;
        END;
		OPEN c;
		petlja: LOOP
			FETCH c INTO tempMbr, tempDatum;
			IF done = TRUE THEN 
				LEAVE petlja;
			END IF;
            SET poruka = "READ LOCK";
			SET tempOcjena = ocjObrane(tempMbr, tempDatum);
            SET poruka = "WRITE LOCK";
			UPDATE diplom SET ukupOcjena = tempOcjena
			WHERE mbrStud = tempMbr AND datPrijava = tempDatum;
		END LOOP;
		CLOSE c;
    END;
    COMMIT;
END//

DELIMITER ;
