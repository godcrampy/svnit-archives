create or replace function emp_count
return number
is
  i number;
begin
  select count(*) into i from emp;
  return i;
end;
/

declare
begin
  dbms_output.put_line(emp_count());
end;
/
