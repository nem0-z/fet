use stusluZR;

delimiter ++++
create procedure p(value int)
begin
declare kod char(5) default '00000';
declare poruka, rez text;
declare redova int;

declare continue handler for sqlexception
begin
get diagnostics condition 1
kod = RETURNED_SQLSTATE, poruka = message_text;
end;


insert into t1(mbrstud)values(value);


if kod ='00000' then
get diagnostics redova = row_count;
set rez = concat('broj redova = ',redova);
else
set rez = concat('greska= ',kod);
end if;

select rez;
end++++

CREATE PROCEDURE p2(pval INT)
BEGIN
DECLARE specialty CONDITION FOR SQLSTATE '45000';
IF pval = 0 THEN

SIGNAL SQLSTATE '02000';

ELSEIF pval = 1 THEN

SIGNAL SQLSTATE '45000';
ELSEIF pval = 2 THEN

SIGNAL specialty SET MESSAGE_TEXT = 'An error occurred';

ELSE
resignal sqlstate '02000' set message_text='ajla';

END IF;
END;++++

DROP TABLE IF EXISTS t1;++++

CREATE PROCEDURE p2 ()
BEGIN
DECLARE EXIT HANDLER FOR SQLEXCEPTION

BEGIN

SET @error_count = @error_count + 1;
IF @a = 0 THEN RESIGNAL set MESSAGE_TEXT='ajlic'; END IF;

END;
DROP TABLE t1;
END++++

delimiter ;
SET @error_count = 0;
SET @a = 0;
CALL p2();

delimiter ;
call p(1122);
create temporary table t1 as
select * from stud;
drop procedure p2;
call p2();


