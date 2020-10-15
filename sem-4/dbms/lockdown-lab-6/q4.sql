create or replace function highest_salary
return float
is
  i float;
begin
  select salary 
  into i
  from (select salary from emp order by salary desc)
  where rownum = 1;
  return i;
end;
/

declare
begin
  dbms_output.put_line(highest_salary());
end;
/
