create database chatServer;
use chatServer;

--------------------------------------------------------------
--  Create Table for User Authentication
--------------------------------------------------------------
create table user
(
id int auto_increment,
userName varchar(255) NOT NULL,
name varchar(255),
password varchar(255) NOT NULL,
PRIMARY KEY(id,userName)
)ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

--------------------------------------------------------------
--  Insert into user table
--------------------------------------------------------------
insert into user(userName,name,password)  values(?,?,?);
--------------------------------------------------------------
--  Fetch data from user table 
--------------------------------------------------------------
select id,userName,name,password from user;
select id,userName,name,password from user where id=?;
select id,userName,name,password from user where userName=?;

--------------------------------------------------------------
--  Create Table for User Authentication
--------------------------------------------------------------
create table message
(
id int auto_increment,
sentFrom int NOT NULL ,
sentTo int NOT NULL,
message text,
creationDateTime TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
PRIMARY KEY(id),
FOREIGN KEY (sentFrom) REFERENCES user(id) ON DELETE CASCADE,
FOREIGN KEY (sentTo) REFERENCES user(id) ON DELETE CASCADE
)ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

--------------------------------------------------------------
--  Insert into message
--------------------------------------------------------------
insert into message(sentFrom,sentTo,message) values(?,?,?);
--------------------------------------------------------------
--  Fetch data from message table
--------------------------------------------------------------
select id,sentFrom,sentTo,message,creationDateTime from message where id=?;
select id,sentFrom,sentTo,message,creationDateTime from message where sentFrom=?;
select id,sentFrom,sentTo,message,creationDateTime from message where sentTo=?;

