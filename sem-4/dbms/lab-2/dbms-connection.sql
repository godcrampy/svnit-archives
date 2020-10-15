create table deposit(
  actno int primary key,
  cname varchar(15) not null,
  bname varchar(15) not null,
  amount double precision,
  adate date
);

insert into deposit values(100, 'Anil', 'Vrce', 1000.0, '1-mar-95');
insert into deposit values(101, 'Sunil', 'Ajni', 5000.0, '4-jan-96');
insert into deposit values(102, 'Mehul', 'Karolbagh', 3500.0, '17-nov-95');
insert into deposit values(104, 'Madhuri', 'Chandi', 1200.0, '17-dec-95');
insert into deposit values(105, 'Pramod', 'M.G.Road', 3000.0, '27-mar-96');
insert into deposit values(106, 'Sandip', 'Andheri', 2000.0, '31-mar-96');
insert into deposit values(107, 'Shivani', 'Virar', 1000.0, '5-sep-95');
insert into deposit values(108, 'Kranti', 'Nehru Palace', 5000.0, '2-jul-95');
insert into deposit values(109, 'Minu', 'Powai', 7000.0, '10-aug-95');

/*
-- MySQL
insert into deposit values(100, 'Anil', 'Vrce', 1000.0, '1995-03-01');
insert into deposit values(101, 'Sunil', 'Ajni', 5000.0, '1996-01-04');
insert into deposit values(102, 'Mehul', 'Karolbagh', 3500.0, '1995-11-17');
insert into deposit values(104, 'Madhuri', 'Chandi', 1200.0, '1995-12-17');
insert into deposit values(105, 'Pramod', 'M.G.Road', 3000.0, '1995-03-27');
insert into deposit values(106, 'Sandip', 'Andheri', 2000.0, '1996-03-31');
insert into deposit values(107, 'Shivani', 'Virar', 1000.0, '1995-09-05');
insert into deposit values(108, 'Kranti', 'Nehru Palace', 5000.0, '1995-07-02');
insert into deposit values(109, 'Minu', 'Powai', 7000.0, '1995-07-10');
*/

create table branch(
  bname varchar(15) primary key,
  city varchar(15)
);

insert into branch values('Vrce', 'Nagpur');
insert into branch values('Ajni', 'Nagpur');
insert into branch values('Karolbagh', 'Delhi');
insert into branch values('Chandi', 'Delhi');
insert into branch values('M.G.Road', 'Bangalore');
insert into branch values('Andheri', 'Bombay');
insert into branch values('Virar', 'Bombay');
insert into branch values('Nehru Palace', 'Delhi');
insert into branch values('Powai', 'Bombay');

create table customers(
  cname varchar(15) primary key,
  city varchar(15)
);

insert into customers values('Anil', 'Calcutta');
insert into customers values('Sunil', 'Delhi');
insert into customers values('Mehul', 'Baroda');
insert into customers values('Mandar', 'Patna');
insert into customers values('Madhuri', 'Nagpur');
insert into customers values('Pramod', 'Nagpur');
insert into customers values('Sandip', 'Surat');
insert into customers values('Shivani', 'Bombay');
insert into customers values('Kranti', 'Bombay');
insert into customers values('Naren', 'Bombay');

create table borrow(
  loanno int primary key,
  cname varchar(15), bname varchar(15), 
  amount double precision
);

insert into borrow values(201, 'Anil', 'Vrce', 1000.0);
insert into borrow values(206, 'Mehul', 'Ajni', 5000.0);
insert into borrow values(311, 'Sunil', 'Dharampeth', 3000.0);
insert into borrow values(321, 'Madhuri', 'Andheri', 2000.0);
insert into borrow values(375, 'Pramod', 'Virar', 8000.0);
insert into borrow values(481, 'Kranti', 'Nehru Palace', 3000.0);
