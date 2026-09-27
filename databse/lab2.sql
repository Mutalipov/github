--4
create table students(id serial, firstname varchar(70), lastname varchar(70), isactive int, email varchar(70), age int);
--5 
alter table students add column gender int;
--6
alter table students alter column gender set default 0;
--7
alter table students alter column gender drop default;
--8
alter table students add primary key(id);
--9
alter table students alter column email set default 'abc@gmail.com';
--10
alter table students add column birthdate date;
--11
alter table students alter column firstname type varchar(100);
--12
alter table students rename column lastname to surname;
alter table students rename column surname to lastname;
--13
insert into students(firstname, lastname)
values('Sherkhan', 'Mutalip');
--14
insert into students(firstname,lastname,age)
values('Jhon', 'Jhonson', null);
--15
insert into students(firstname, age, isactive)
values ('abc',17,1), 
('bca', 19,0),
('cab',25,1);
--16
alter table students alter column age set default 20;
insert into students(firstname)
values ('Joe');
--17
update students set gender = 0 where gender is null;
update students set age = 20 where age is null;
--18
alter table students alter column isactive type boolean
using isactive::integer::boolean;
--19
create table teachers(like students including all);
--20
insert into teachers select * from students;
--21
update teachers set age = age+2
returning firstname, age as update_age;
--22
update students set
email = case when id = 2 then 'bca@mail.ru' else email end,
firstname = case when id =4 then 'newname' else firstname end,
isactive = case when id=4 then true else isactive end
where id in (2,4);
--23
update students
set birthdate = '2006-01-06'
where id = 4;
--24
delete from teachers
where id in (select id from students)
returning *;
--25
delete from students
where age<20;
--26
delete from students
returning *;