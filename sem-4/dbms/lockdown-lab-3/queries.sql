-- 1
select name
from instructor 
where salary > any(
  select salary 
  from instructor 
  where department='Computer Science'
);

-- 2
select name
from instructor 
where salary > all(
  select salary 
  from instructor 
  where department='Electronics'
);

-- 3
select ROUND(SUM(salary), 2), department 
from instructor 
group by department;

-- 4
select ROUND(SUM(salary), 2)
from instructor
where department='Computer Science';

-- 5
select COUNT(name), department 
from instructor 
group by department;

-- 6
select name, department
from instructor 
order by department, name;

-- 7
update instructor
set salary = salary * 1.05
where department = 'Computer Science';

update instructor
set salary = salary * 1.07
where department = 'Electronics';

update instructor
set salary = salary * 1.09
where department = 'Computational Biology';