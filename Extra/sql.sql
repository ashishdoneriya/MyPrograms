create table devotees(Devotee_Name VARCHAR(20) NOT NULL, Number_Of_Rounds INT NOT NULL DEFAULT 1, City VARCHAR(20));

INSERT INTO devotees(devotee_name, number_of_rounds) values ('ashish',6);

INSERT INTO devotees(devotee_name) values ('abhi');

INSERT INTO devotees values ('Sarvatma Pr.',16,'Bhind');

INSERT INTO devotees values ('Jai Kishna Pr.',16,'Morena');

SELECT * FROM devotees;

CREATE TABLE blogs(BLOG_ID INT NOT NULL, BLOG TEXT);

INSERT INTO blogs values (1,'Hare\rKrishna');

create table cse ( scholar_no INT NOT NULL,  name VARCHAR(30) NOT NULL, branch VARCHAR(10) NOT NULL DEFAULT 'cse', PRIMARY KEY (scholar_no) );

INSERT INTO cse(scholar_no, name) VALUES (101112017, 'Rakshendra Singh Chauhan');

ALTER TABLE cse ADD COLUMN residence VARCHAR(50);

UPDATE cse SET residence = 'HN 5' WHERE scholar_no <>101112011;

UPDATE cse SET residence = 'bace' WHERE NOT scholar_no <>101112011;

select name from cse where name like '% k%';

UPDATE cse SET branch = UPPER(branch);

ALTER TABLE cse1 CHANGE scholar_no sch_no INT NOT NULL, ADD PRIMARY KEY(sch_no);

ALTER TABLE cse1 ADD COLUMN address VARCHAR(10) AFTER name;

UPDATE cse1 SET address=residence;

ALTER TABLE cse1 DROP COLUMN residence;

ALTER TABLE cse1 ADD COLUMN Fname VARCHAR(15) AFTER sch_no, ADD COLUMN Lname VARCHAR(20) AFTER Fname;

ALTER TABLE cse1 DROP COLUMN Fname, DROP COLUMN Lname;

UPDATE cse1 SET Fname = SUBSTRING_INDEX(name,' ',1), Lname = SUBSTRING_INDEX(name,' ',-1);

ALTER TABLE cse1 drop name;

update cse1 set Lname=NULL where Lname='Ashish';

update cse1 set Lname='Doneriya' where Fname='Ashish';



CREATE TABLE interest
(
int_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
interest VARCHAR(50) NOT NULL,
scholar_no INT NOT NULL,
CONSTRAINT cse1_scholar_no_fk
FOREIGN KEY (scholar_no)
REFERENCES cse1 (scholar_no)
);


CREATE TABLE interest
(
int_id INT NOT NULL AUTO_INCREMENT,
interest VARCHAR(50) NOT NULL,
scholar_no INT NOT NULL,
FOREIGN KEY (scholar_no)
REFERENCES cse1(scholar_no),
PRIMARY KEY (int_id)
);

CREATE TABLE parent
(
	id INT NOT NULL,
	PRIMARY KEY (id)
) ENGINE=INNODB;

CREATE TABLE child
(
	id INT,
	parent_id INT,
	INDEX par_ind (parent_id),
	FOREIGN KEY (parent_id)
	REFERENCES parent(id)
	ON DELETE CASCADE
) ENGINE=INNODB;



CREATE TABLE interests
(
sch_no INT,
FOREIGN KEY (sch_no)
REFERENCES cse1(sch_no)
ON DELETE CASCADE
) AS
SELECT sch_no from cse1
ORDER BY sch_no;

ALTER TABLE interests
ADD COLUMN interest VARCHAR(60)
AFTER sch_no;

INSERT INTO interests VALUES
(101112011, 'pb, sb, programming, computer'),
(101112012, 'computer, programming, singing, dancing'),
(101112013, 'dancing, singing, hacking'),
(101112014, 'singing, hacking'),
(101112015, 'dancing, singing, hacking, painting'),
(101112017, 'dancing, singing, hacking, painting);


CREATE TABLE recidence AS
SELECT recidence FROM cse1
GROUP BY recidence
ORDER BY recidence;

ALTER TABLE recidence
ADD res_id INT NOT NULL AUTO_INCREMENT FIRST,
ADD PRIMARY KEY(res_id);

ALTER TABLE recidence ADD COLUMN location varchar(60);

UPDATE recidence SET location = recidence;

ALTER TABLE recidence DROP COLUMN recidence;

ALTER TABLE cse1
FOREIGN KEY(recidence)
REFERENCES recidence(location);
