USE stusluZR;

SET @t1=1, @t2=2, @t3=3;
SELECT @t1, @t2, @t3;
SELECT @t1, @t2, @t3 := @t1+@t2+@t3;

SELECT * FROM stud WHERE mbrStud = 1120;
SELECT * FROM stud;
SET @mbr = "1120";
SET @s = CONCAT("SELECT", " * ", "FROM stud", " WHERE mbrStud = ", @mbr);
PREPARE stmt FROM @s;
EXECUTE stmt;
SELECT stmt;
SELECT @s;



