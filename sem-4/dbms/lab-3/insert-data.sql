insert into employee values (101, 'Jhonny', '2005-07-01', 'C');
insert into employee values (116, 'Nayak', '2005-08-16', 'C');
insert into employee values (202, 'Meera', '2006-01-30', 'C');
insert into employee values (304, 'Hari', '2006-11-25', 'P');
insert into employee values (205, 'Ravi', '2006-02-11', 'C');
insert into employee values (307, 'Nancy', '2007-01-15', 'P');
insert into employee values (403, 'Nick', '2007-01-21', 'P');

insert into project values('P001', 'Environment Pollution', '2005-08-02', '2006-12-11');
insert into project values('P002', 'Learning Curve', '2006-02-01', '2006-03-15');
insert into project values('P003', 'Effects of IT', '2007-01-03', null);

insert into project_allocation values('P001', 101, '2005-08-01', '2006-12-11');
insert into project_allocation values('P001', 116, '2005-08-16', '2006-12-11');
insert into project_allocation values('P002', 202, '2006-02-01', '2007-01-14');
insert into project_allocation values('P002', 307, '2007-01-15', null);
insert into project_allocation values('P002', 205, '2007-02-11', null);
insert into project_allocation values('P003', 403, '2007-01-21', null);
insert into project_allocation values('P003', 304, '2007-01-03', null);
insert into project_allocation values('P003', 101, '2007-01-03', null);