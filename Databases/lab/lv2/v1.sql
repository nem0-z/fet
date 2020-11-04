use stusluZR;

#Odrediti minimalan broj tabela da se upit izvrsi 

#Treba nam sifra   nastavnika,     ocjena      i     sifra predmeta
#Nalaze se u     nastavnik,ispit,  ispit       i       pred,ispit

SELECT DISTINCT sifNastavnik FROM ispit
WHERE ocjena = 1 AND sifPred = 146;

SELECT mbrStud FROM ispit
WHERE ocjena > 1 AND sifPred = 262; 
#Ovde nesto kao distinct bi bilo redundantno
#Ne zato jer je mbrStud unique index (jest u tabeli stud ali ne i u ispit)
#Vec zato jer nema logike da je student vise puta polozio ispit
#Obrati paznju na ove stvari jer svi ti beskorisni "zahtjevi" usporavaju logyyy

#SUBSTRING(string,pocni odavde,idi ovoliko koraka)



