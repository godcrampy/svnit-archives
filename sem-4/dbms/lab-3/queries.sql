-- q1
select project_description, emp_name
from project, employee, project_allocation
where employee.empno = project_allocation.empno and project.project_code = project_allocation.project_code;

-- q2
select emp_name
from employee
where emp_status = 'C';

-- q3
select *
from employee
where MONTH(emp_join_date) = 11;

-- q4
select *
from project
where project_start_date > '2006-01-01';

-- q5
select *
from employee, project, project_allocation
where employee.empno = project_allocation.empno and project.project_code = project_allocation.project_code and project_description = 'Effects of IT';

-- q6
select * from project where project_end_date is null;

-- q7
select *
from employee, project, project_allocation
where employee.empno = project_allocation.empno and project.project_code = project_allocation.project_code and project_allocation.project_code = 'P002'  and emp_status = 'R';

-- q8
select datediff(project_end_date, project_start_date)
from project
where project_code = 'P002';

-- q9
select employee.emp_name, datediff(emp_proj_release_date, emp_proj_allocation_date)
from employee, project, project_allocation
where employee.empno = project_allocation.empno and project.project_code = project_allocation.project_code;

-- q10
alter table project
add manager_id int;

-- q11
update project
set manager_id=101
where project_code='P001';

update project
set manager_id=202
where project_code='P002';

update project
set manager_id=116
where project_code='P003';

-- q12
insert into project values('P004', 'Environment Pollution', '2007-03-01', null);

-- q13
delete from project_allocation
where project_code in (select project_code
  from project
  where project_description='Effects of IT');
delete from project
where project_description='Effects of IT';

-- q14
select * from project where timestampdiff(month,project_start_date, project_end_date) > 13;

-- q15
select count(empno), project_code 
from project_allocation 
where emp_proj_allocation_date < '2007-02-01' and (emp_proj_release_date > '2007-02-01' or emp_proj_release_date is null)
group by project_code;