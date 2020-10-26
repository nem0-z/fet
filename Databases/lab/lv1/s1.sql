CREATE DATABASE test_baza;
USE test_baza;
INSERT INTO stud VALUES('1234','prezime','ime','1999-01-01',75000,'adresa',9.00);

SELECT * FROM stud;

INSERT INTO stud VALUES('1235','prezime','ime','1999-01-01',75000,'adresa',9.00);
INSERT INTO stud(mbrstud,prezstud,imestud,prosOcjena) VALUES('1237','prezime1','ime1',10.0); #Probaj ovo malo izokretat redoslijed

UPDATE stud SET prezstud = 'novo prezime'; #Svima promjena
UPDATE stud SET prezstud = 'novo prezime' WHERE prezstud = 'prezime';

SELECT * FROM stud INTO OUTFILE '/home/zlatan/fet/Databases/lab/lv1/lv1.unl'
FIELDS TERMINATED BY '#' LINES TERMINATED BY '\n';

DROP DATABASE test_baza;