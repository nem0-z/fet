USE stusluZR;


#Tema 2
DELIMITER //
CREATE PROCEDURE azurDiplom()
BEGIN
	DECLARE mbr INT;
    DECLARE datum DATE;
    DECLARE done BOOL DEFAULT FALSE;
	DECLARE c1 CURSOR FOR SELECT mbrStud, datPrijava FROM diplom;
    DECLARE CONTINUE HANDLER FOR SQLEXCEPTION SET done = TRUE;
    OPEN c1;
    petlja: LOOP
		IF done THEN
			LEAVE petlja;
        END IF;
		FETCH c1 INTO mbr, datum;
		UPDATE diplom SET ukupOcjena = ocjObrane(mbr, datum);
    END LOOP;
    CLOSE c1;
END//

DELIMITER ;
