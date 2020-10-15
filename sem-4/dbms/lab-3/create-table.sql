create table employee (
  empno int primary key,
  emp_name varchar(20),
  emp_join_date date,
  emp_status char
);

create table project (
  project_code varchar(4) primary key,
  project_description varchar(100),
  project_start_date date,
  project_end_date date
);

create table project_allocation (
  project_code varchar(4),
  empno int,
  emp_proj_allocation_date date,
  emp_proj_release_date date,
  foreign key (empno) references employee(empno),
  foreign key (project_code) references project(project_code)
);