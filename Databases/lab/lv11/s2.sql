USE stusluZR;

#Tema 2
DELIMITER /
CREATE PROCEDURE azurDiplom()
BEGIN
	DECLARE tempMbr, tempOcjena INTEGER;
    DECLARE tempDatum DATE;
    DECLARE done BOOL DEFAULT FALSE;
    DECLARE c CURSOR FOR SELECT mbrStud, datPrijava FROM diplom;
	DECLARE CONTINUE HANDLER FOR SQLEXCEPTION SET done = TRUE;
    START TRANSACTION;
    OPEN c;
	petlja: LOOP
		FETCH c INTO tempMbr, tempDatum;
		IF done = TRUE THEN 
			LEAVE petlja;
		END IF;
        SET tempOcjena = ocjObrane(tempMbr, tempDatum);
        UPDATE diplom SET ukupOcjena = tempOcjena
        WHERE mbrStud = tempMbr AND datPrijava = tempDatum;
    END LOOP;
    CLOSE c;
    COMMIT WORK;
END/

DELIMITER ;

