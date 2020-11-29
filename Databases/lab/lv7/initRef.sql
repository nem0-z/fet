CREATE DATABASE stusluZR1 CHARACTER SET = 'utf8' COLLATE = 'utf8_croatian_ci';
USE stusluZR1;
CREATE TABLE zupanija
( sifZupanija SMALLINT NOT NULL PRIMARY KEY
, nazZupanija NCHAR(40) NOT NULL
);
CREATE TABLE mjesto
( pbr INTEGER NOT NULL PRIMARY KEY
, nazMjesto NCHAR(40) NOT NULL UNIQUE
, sifZupanija SMALLINT
, FOREIGN KEY (sifZupanija) REFERENCES zupanija(sifZupanija)
);
CREATE TABLE stud
( mbrStud INTEGER NOT NULL PRIMARY KEY
, imeStud NCHAR(25) NOT NULL
, prezStud NCHAR(25) NOT NULL
, pbrRod INTEGER
, pbrStan INTEGER NOT NULL
, datRodStud DATE
, jmbgStud CHAR(13)
, FOREIGN KEY (pbrStan) REFERENCES mjesto(pbr)
, FOREIGN KEY (pbrRod) REFERENCES mjesto(pbr)
);
CREATE TABLE orgjed
( sifOrgjed INTEGER NOT NULL PRIMARY KEY
, nazOrgjed NCHAR(60) NOT NULL
, sifNadorgjed INTEGER
);
CREATE TABLE nastavnik
( sifNastavnik INTEGER NOT NULL PRIMARY KEY
, imeNastavnik NCHAR(25) NOT NULL
, prezNastavnik NCHAR(25) NOT NULL
, pbrStan INTEGER NOT NULL
, sifOrgjed INTEGER NOT NULL
, koef DECIMAL(3,2) NOT NULL
, FOREIGN KEY (sifOrgjed) REFERENCES orgjed(sifOrgjed)
, FOREIGN KEY (pbrStan) REFERENCES mjesto(pbr)
);
CREATE TABLE pred
( sifPred INTEGER NOT NULL PRIMARY KEY
, kratPred CHAR(8)
, nazPred NCHAR(60) NOT NULL
, sifOrgjed INTEGER
, upisanoStud INTEGER
, brojSatiTjedno INTEGER
, FOREIGN KEY (sifOrgjed) REFERENCES orgjed(sifOrgjed)
);
CREATE TABLE ispit
( mbrStud INTEGER NOT NULL
, sifPred INTEGER NOT NULL
, sifNastavnik INTEGER NOT NULL
, datIspit DATE NOT NULL
, ocjena SMALLINT DEFAULT 1 NOT NULL
, PRIMARY KEY (mbrStud, sifPred, datIspit)
, FOREIGN KEY (sifNastavnik) REFERENCES nastavnik(sifNastavnik)
, FOREIGN KEY (sifPred) REFERENCES pred(sifPred)
, FOREIGN KEY (mbrStud) REFERENCES stud(mbrStud)
);
CREATE TABLE dvorana
( oznDvorana CHAR(5) NOT NULL PRIMARY KEY
, kapacitet INTEGER DEFAULT 40
);
CREATE TABLE rezervacija
( oznDvorana CHAR(5) NOT NULL
, oznVrstaDan CHAR(2) NOT NULL
, sat SMALLINT NOT NULL
, sifPred INTEGER NOT NULL
, PRIMARY KEY (oznDvorana, oznVrstaDan, sat)
, FOREIGN KEY (sifPred) REFERENCES pred(sifPred)
, FOREIGN KEY (oznDvorana) REFERENCES dvorana(oznDvorana)
);
LOAD DATA INFILE '/var/lib/mysql-files/tmp/zupanija.unl' INTO TABLE zupanija FIELDS TERMINATED BY
'#' LINES STARTING BY '\n' TERMINATED BY '#\r';
LOAD DATA INFILE '/var/lib/mysql-files/tmp/mjesto.unl' INTO TABLE mjesto FIELDS TERMINATED BY '#'
LINES STARTING BY '\n' TERMINATED BY '#\r';
LOAD DATA INFILE '/var/lib/mysql-files/tmp/stud.unl' INTO TABLE stud FIELDS TERMINATED BY '#' LINES
STARTING BY '\n' TERMINATED BY '\r';
LOAD DATA INFILE '/var/lib/mysql-files/tmp/orgjed.unl' INTO TABLE orgjed FIELDS TERMINATED BY '#'
LINES STARTING BY '\n' TERMINATED BY '#\r';
LOAD DATA INFILE '/var/lib/mysql-files/tmp/nastavnik.unl' INTO TABLE nastavnik FIELDS TERMINATED BY
'#' LINES STARTING BY '\n' TERMINATED BY '#\r';
LOAD DATA INFILE '/var/lib/mysql-files/tmp/pred.unl' INTO TABLE pred FIELDS TERMINATED BY '#' LINES
STARTING BY '\n' TERMINATED BY '#\r';
LOAD DATA INFILE '/var/lib/mysql-files/tmp/ispit.unl' INTO TABLE ispit FIELDS TERMINATED BY '#'
LINES STARTING BY '\n' TERMINATED BY '\r';
LOAD DATA INFILE '/var/lib/mysql-files/tmp/dvorana.unl' INTO TABLE dvorana FIELDS TERMINATED BY '#'
LINES STARTING BY '\n' TERMINATED BY '#\r';
LOAD DATA INFILE '/var/lib/mysql-files/tmp/rezervacija.unl' INTO TABLE rezervacija FIELDS TERMINATED
BY '#' LINES STARTING BY '\n' TERMINATED BY '#\r';
