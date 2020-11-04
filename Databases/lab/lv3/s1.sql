use stusluZR;
SELECT COUNT(distinct datRodStud) FROM stud;
SELECT SUM(datRodStud) FROM stud;

SELECT prezStud, CONCAT(SUBSTRING(imeStud,1,1),'.',SUBSTRING(prezStud,1,1)) as Inicijali
FROM stud WHERE prezStud RLIKE '^[K-N]' AND YEAR(datRodStud) = YEAR(CURRENT_DATE) - 20
AND WEEKDAY(CURRENT_DATE) = WEEKDAY(datRodSTud);

#1
SELECT DISTINCT sifZupanija FROM zupanija WHERE nazZupanija LIKE 'Z%';

#2
SELECT * FROM stud WHERE datRodStud BETWEEN '1982-5-1' AND '1982-9-1'
AND (prezStud LIKE 'R%' OR prezStud LIKE 'P%' OR prezStud LIKE 'S%' or prezStud LIKE 'V%');

#3
SELECT * FROM stud WHERE datRodStud BETWEEN '1982-5-1' AND '1982-9-1'
AND prezStud RLIKE '^[RPSV]';

#4 - msm ovo je samo glupo raditi sa LIKE operatorom 5^2 provjera ???
SELECT nazMjesto FROM mjesto 
WHERE nazMjesto RLIKE '^[AEIOU]' AND nazMjesto RLIKE '[aeiou]$'; 

#5 
SELECT nazMjesto FROM mjesto
WHERE nazMjesto RLIKE '^[^AEIOU]' AND nazMjesto RLIKE '[^aeiou]$';

#6 - ovako se trebao raditi 4 u startu osim ako ja nesto ne fulam :)
SELECT nazMjesto FROM mjesto 
WHERE nazMjesto RLIKE '^[AEIOU]' AND nazMjesto RLIKE '[aeiou]$'; 

#7 str_to_date
SELECT * FROM stud
WHERE STR_TO_DATE(CONCAT(SUBSTRING(jmbgStud,1,4),'1',SUBSTRING(jmbgStud,5,3)),'%d%m%Y') != datRodStud;

#8
SELECT AVG(koef) FROM nastavnik WHERE pbrStan = 10000;

#9
SELECT MIN(datIspit), MAX(datIspit) FROM ispit;

#10
SELECT COUNT(DISTINCT sifOrgjed) FROM nastavnik WHERE pbrStan=10000;

#11
SELECT DATEDIFF(MAX(datRodStud),MIN(datRodStud)) FROM stud;

#12
SELECT AVG(ocjena) FROM ispit WHERE YEAR(datIspit) = 1999 AND ocjena > 1;

#13
SELECT COUNT(ocjena), AVG(ocjena) FROM ispit WHERE sifPred = 146 AND ocjena > 1;

#14
SELECT AVG(DATEDIFF(CURRENT_DATE,datRodStud)) FROM stud WHERE pbrRod = 10000 
AND (imeStud RLIKE '^[AEIOU]' OR imeStud RLIKE '[aeiou]$');

#15
SELECT COUNT(DISTINCT sifPred) FROM rezervacija
WHERE oznDvorana LIKE 'B%' AND oznVrstaDan IN ('UT','SR');

#16
SELECT COUNT(mbrStud) AS BrojStudenata, AVG(ocjena) AS ProsjecnaOcjena FROM ispit
WHERE WEEKDAY(datIspit) = 4 AND MONTH(datIspit) = 7
AND YEAR(datIspit) + 5 <= YEAR(CURRENT_DATE);

#17
SELECT SUM(upisanoStud) FROM pred WHERE 
brojSatiTjedno > 3 AND nazPred LIKE '%elektron%';

#select jmbgstud, DATE_FORMAT(datrodstud,'%d%m%Y') from stud;
#SELECT STR_TO_DATE('09061983','%d%m%y');
#SELECT STR_TO_DATE(CONCAT(SUBSTRING(jmbgStud,1,4),'1',SUBSTRING(jmbgStud,5,3)),'%d%m%Y') from stud;