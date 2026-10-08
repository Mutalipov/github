--1
CREATE TABLE users (
    user_id SERIAL PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    age INT NOT NULL CHECK (age > 16),
    email VARCHAR(100),
    country VARCHAR(70)
);
--2
INSERT INTO users (username, age, country) VALUES 
('john_doe', 22, 'Kazakhstan'),
('alice_smith', 25, 'USA'),
('bob_jones', 30, 'Canada');
--3
ALTER TABLE users 
ADD COLUMN phone_number VARCHAR(12) 
DEFAULT '+77001234567' 
CHECK (phone_number ~ '^\+[0-9]{11}$');
--4
ALTER TABLE users 
ADD COLUMN password VARCHAR(255) 
CHECK (
    LENGTH(password) >= 8 
    AND password ~ '[a-z]' 
    AND password ~ '[A-Z]' 
    AND password ~ '[0-9]' 
    AND password ~ '[!@#$%^&*]'
);
--5
ALTER TABLE users 
ALTER COLUMN username DROP NOT NULL;
--6
INSERT INTO users (username, age, country, password) VALUES 
(NULL, 19, 'Kazakhstan, Pass123!'),
(NULL, 24, 'Germany', 'SecureP@ss1');

INSERT INTO users (username, age, country, password) VALUES 
('charlie_brown', 21, NULL, 'TestCode#9'),
('diana_prince', 28, NULL, 'WonderWoman1$');
--7
ALTER TABLE users 
ADD CONSTRAINT check_username_lowercase 
CHECK (username = LOWER(username));
--8
ALTER TABLE users 
ADD CONSTRAINT check_contact_info 
CHECK (email IS NOT NULL OR phone_number IS NOT NULL);
--9
ALTER TABLE users 
DROP CONSTRAINT check_username_lowercase;
--10
ALTER TABLE users 
ADD CONSTRAINT unique_email UNIQUE (email);
--11
ALTER TABLE users 
ADD COLUMN created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP;

ALTER TABLE users 
ALTER COLUMN created_at SET NOT NULL;
--12
CREATE TABLE course_registrations (
    student_id INT NOT NULL,
    course_code VARCHAR(20) NOT NULL,
    registration_date DATE DEFAULT CURRENT_DATE,
    PRIMARY KEY (student_id, course_code)
);

INSERT INTO course_registrations (student_id, course_code) VALUES 
(1, 'CS101'),
(1, 'CS102'),
(2, 'CS101');
--13
CREATE TABLE departments (
    dept_id SERIAL PRIMARY KEY,
    dept_name VARCHAR(100) NOT NULL
);

CREATE TABLE managers (
    manager_id SERIAL PRIMARY KEY,
    manager_name VARCHAR(100) NOT NULL,
    dept_id INT REFERENCES departments(dept_id) ON DELETE RESTRICT
);

CREATE TABLE employees (
    emp_id SERIAL PRIMARY KEY,
    emp_name VARCHAR(100) NOT NULL,
    dept_id INT REFERENCES departments(dept_id) ON DELETE RESTRICT,
    manager_id INT REFERENCES managers(manager_id) ON DELETE SET NULL
);
--14
CREATE TABLE orders (
    order_id SERIAL PRIMARY KEY,
    order_date DATE DEFAULT CURRENT_DATE
);

CREATE TABLE order_items (
    order_id INT REFERENCES orders(order_id) ON DELETE CASCADE ON UPDATE CASCADE,
    item_id INT NOT NULL,
    quantity INT NOT NULL CHECK (quantity BETWEEN 1 AND 100),
    price NUMERIC(10, 2) NOT NULL,
    discount NUMERIC(5, 2) CHECK (discount IS NULL OR (discount <= 40 AND price > 100)),
    PRIMARY KEY (order_id, item_id)
);
--15
INSERT INTO orders DEFAULT VALUES; 
INSERT INTO orders DEFAULT VALUES; 

INSERT INTO order_items (order_id, item_id, quantity, price, discount) VALUES 
(1, 101, 5, 120.00, 10.00),
(2, 102, 2, 50.00, NULL);

UPDATE orders 
SET order_id = 100 
WHERE order_id = 1;

SELECT * FROM order_items;

DELETE FROM orders 
WHERE order_id = 100;

SELECT * FROM order_items;