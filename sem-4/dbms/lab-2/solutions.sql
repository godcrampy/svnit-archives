-- 1
describe deposit;

-- 2
describe borrow;

-- 3
select *
from deposit;

-- 4
select *
from borrow;

-- 5
select *
from customers;

-- 6
select *
from branch;

-- 7
select actno, amount from deposit;

-- 8
select cname from deposit where amount > 4000;

-- 9
select cname from deposit where adate > '1996-01-12';

-- 10
select bname from branch where city = 'Delhi' or city = 'Nagpur';

-- 11
select count(*) from customers where city = 'Bombay';

-- 12
select sum(amount) from deposit;

-- 13
select sum(amount) from borrow;

-- 14
select cname from customers where city = 'Bombay' or city = 'Nagpur';

-- 15
select bname from branch where city = 'Bangalore' or city = 'Nagpur' or city = 'Delhi';

-- 16
select avg(amount) from deposit;

-- 17
select cname, amount from deposit order by amount desc limit 1;

-- 18
select cname, amount from deposit order by amount limit 1;

-- 19
NOW();

-- 20
select cname from deposit where amount > (select avg(amount) from deposit);
