--2
select upper(first_name) as upper_fs, upper(last_name) as upper_ls from actor;
--3
select title, rental_rate, rental_rate * 1.10 as rental_rate_with_tax from film;
--4
select substring(title,1,4) as short_title from film;
--5
select customer_id, first_name, last_name from customer where customer_id between 100 and 200;
--6
select title, rating from film where rating in('PG','PG-13');
--7
select concat(first_name,' ', last_name) as full_name from actor;
--8
select concat(title,'(',release_year,')') as film_label from film;
--9
select customer_id, first_name, last_name, coalesce(email,'no email provided') as email from customer;
--10
select * from film where lower(title) like '%star%';
--11
select customer_id, first_name from customer where first_name like '_a%';
--12
select format('Customer %s: %s %s Email: %s', customer_id, first_name, last_name, coalesce(email,'no email provided')) as customer_details from customer;
--13
select title, length(title) as title_length from film where length(title)>20;
--14
select max(length) - min(length) as length_rate from film;
--15
select title, sqrt(replacement_cost) as sqrt_cost from film;
--16
select title, round(cast(rental_rate as numeric)/(rental_duration*24),2) as roundly_rental_rate from film;
--17
select rental_id, rental_date, current_date as report_date from rental;
--18
select rental_id, rental_date, extract(hour from rental_date) as rental_hour from rental;
--19
select rental_id, age(return_date,rental_date) as rental_duration from rental where return_date is not null;
--20
select title, length, 
	case 
		when length<60 then 'Short'
		when length between 60 and 120 then 'Medium'
		else 'long'
	end as length_category
from film;
		