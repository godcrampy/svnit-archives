create table emp (
  empno number,
  ename varchar2(30),
  job varchar2(15),
  sal number(8, 2),
  deptno number(2),
  commission number(7, 2)
  primary key (empno)
);


insert into emp values (101, 'Lisa', 'Clerk', 20000.00, 10, 550.00);
insert into emp values (102, 'Jennifer', 'Analyst', 50000.00, 10, 500.00);
insert into emp values (103, 'Joseph', 'Senior Analyst', 70000.00, 10, 600.00);
insert into emp values (104, 'David', 'Scientist', 70000.00, 20, 550.00);
insert into emp values (105, 'Mathew', 'Clerk', 20000.00, 20, 550.00);
insert into emp values (106, 'Amit', 'Programmer', 55000.00, 30, 600.00);