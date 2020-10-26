use just;
create table tik (
ime varchar(20) not null,
konj bool not null);
select * from tik;
insert into tik values
('zlatan',true),('sinisa',false);
create UNIQUE index ime on tik(ime);
alter table tik add constraint ime unique key(ime);
delete from tik where ime='sinisa';
update tik set konj=true where konj=false;