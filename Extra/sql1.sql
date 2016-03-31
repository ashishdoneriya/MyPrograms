CREATE DATABASE head_first;
USE head_first;

CREATE TABLE my_contacts
(
fname VARCHAR(10),
lname VARCHAR(15),
phone CHAR(10),
email VARCHAR(20),
gender CHAR(1),
birthday DATE,
profession VARCHAR(10),
city VARCHAR(10),
state VARCHAR(15),
status VARCHAR(10),
interest VARCHAR(30)
);

INSERT INTO my_contacts VALUES ('Ashish','Doneriya','9301124836','ashishdoneriya@gmail.com','M','19911204','student','Morena','madhya pradesh','single','book reading');

INSERT INTO my_contacts VALUES ('Nikhil','Verma','','nicks_cooool@yahoo.co,','M','19920823','student','Morena','madhya pradesh','single','study');

INSERT INTO my_contacts VALUES ('Chandra','Prakash','9039647410','abhinavkumar2002@gmail.com','M','19891207','student','hamirpur','uttar pradesh','single','self realization');

CREATE TABLE profession
(
prof_id INT NOT NULL AUTO_INCREMENT,
profession VARCHAR(10),
PRIMARY KEY(prof_id)
);

INSERT INTO profession(profession)
SELECT profession FROM my_contacts
GROUP BY profession
ORDER BY profession;

CREATE TABLE zip_code
(
zip_code INT NOT NULL AUTO_INCREMENT,
city VARCHAR(10),
state VARCHAR(15),
PRIMARY KEY(zip_code)
);

INSERT INTO zip_code(city, state)
SELECT city, state FROM my_contacts
GROUP BY city
ORDER BY city;

CREATE TABLE interests
(
interest_id INT NOT NULL AUTO_INCREMENT,
interest VARCHAR(30),
PRIMARY KEY(interest_id)
);

INSERT INTO interests(interest)
SELECT interest FROM my_contacts
GROUP BY interest
ORDER BY interest;

CREATE TABLE status
(
status_id INT NOT NULL AUTO_INCREMENT,
status VARCHAR(10),
PRIMARY KEY (status_id)
);

INSERT INTO status(status)
SELECT status FROM my_contacts
GROUP BY status
ORDER BY status;

ALTER TABLE my_contacts
ADD COLUMN contact_id INT NOT NULL AUTO_INCREMENT FIRST,
ADD PRIMARY KEY(contact_id),
ADD COLUMN prof_id INT,
ADD COLUMN zip_code INT,
ADD COLUMN status_id INT,
ADD FOREIGN KEY(prof_id) REFERENCES profession(prof_id),
ADD FOREIGN KEY(zip_code) REFERENCES zip_code(zip_code),
ADD FOREIGN KEY(status_id) REFERENCES status(status_id);

CREATE TABLE contact_interest
(
contact_id INT,
interest_id INT,
FOREIGN KEY (contact_id) REFERENCES my_contacts(contact_id) ON DELETE CASCADE,
FOREIGN KEY (interest_id) REFERENCES interests(interest_id) ON DELETE CASCADE
);

INSERT INTO contact_interest(contact_id,interest_id)
SELECT mc.contact_id,i.interest_id
FROM my_contacts mc
JOIN interests i
ON mc.interest=i.interest
GROUP BY mc.contact_id
ORDER BY mc.contact_id;

UPDATE my_contacts mc
INNER JOIN profession p
ON mc.profession=p.profession
SET mc.prof_id=p.prof_id;

UPDATE my_contacts mc
INNER JOIN zip_code zc
ON mc.city=zc.city AND mc.state=zc.state
SET mc.zip_code=zc.zip_code;

UPDATE my_contacts mc
INNER JOIN status s
ON mc.status=s.status
SET mc.status_id=s.status_id;

ALTER TABLE my_contacts
DROP COLUMN profession;
ALTER TABLE my_contacts
DROP COLUMN city;
ALTER TABLE my_contacts
DROP COLUMN state;
ALTER TABLE my_contacts
DROP COLUMN interest;
ALTER TABLE my_contacts
DROP COLUMN status;

SELECT * FROM my_contacts;
SELECT mc.contact_id,mc.fname,mc.lname,p.profession FROM profession p,my_contacts mc WHERE mc.prof_id=p.prof_id;
SELECT mc.contact_id,mc.fname,mc.lname,zc.city,zc.state FROM zip_code zc,my_contacts mc WHERE zc.zip_code=mc.zip_code;
SELECT mc.contact_id,mc.fname,mc.lname,s.status FROM status s,my_contacts mc WHERE s.status_id=mc.status_id;
SELECT mc.contact_id,mc.fname,lname,i.interest FROM my_contacts mc,interests i,contact_interest ci WHERE mc.contact_id=ci.contact_id AND i.interest_id=ci.interest_id;


