-- Lab 3 SQL Queries

-- Q3: 
SELECT first_name, last_name
FROM staff
WHERE active = TRUE 
  AND picture IS NULL;

-- Q4: 
SELECT title, length
FROM film
WHERE length > 50
ORDER BY length DESC;

-- Q5: 
SELECT title, length, rating
FROM film
WHERE length BETWEEN 100 AND 110 
  AND rating = 'G'
ORDER BY length ASC;

-- Q6: 
SELECT title, rating, length
FROM film
ORDER BY rating ASC, length DESC;

-- Q7: 
SELECT rental_id, return_date
FROM rental
ORDER BY return_date DESC NULLS LAST;

-- Q8: 
SELECT rating, MIN(length) AS min_length
FROM film
GROUP BY rating;

-- Q9: 
SELECT UPPER(title) AS title_upper, 
       length / 60.0 AS length_hours
FROM film;

-- Q10: 
SELECT DISTINCT ON (rating) title, rating, length
FROM film
ORDER BY rating, length DESC, title ASC;

-- Q11: 
SELECT special_features, SUM(rental_rate) AS total_rental_rate
FROM film
GROUP BY special_features;

-- Q12:
SELECT rating, COUNT(*) AS film_count
FROM film
GROUP BY rating
HAVING COUNT(*) > 200;

-- Q13: 
SELECT first_name, last_name FROM actor
UNION
SELECT first_name, last_name FROM staff;

-- Q14: 
SELECT first_name, last_name FROM actor
UNION ALL
SELECT first_name, last_name FROM staff;

-- Q15: 
SELECT first_name, last_name FROM actor
EXCEPT
SELECT first_name, last_name FROM staff;

-- Q16: 
SELECT title FROM film WHERE length > 100
INTERSECT
SELECT title FROM film WHERE replacement_cost < 25;

-- Q17: 
SELECT DISTINCT rating
FROM film;

-- Q18: 
SELECT title, length
FROM film
ORDER BY length DESC, title ASC
OFFSET 10
LIMIT 5;

-- Q19: 
SELECT rating, COUNT(*) AS film_count
FROM film
WHERE length > 100
GROUP BY rating
HAVING COUNT(*) > 110;