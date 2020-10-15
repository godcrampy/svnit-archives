create or replace procedure factorial(x in int, f out int)
is
  i int := 1;
begin
  f := 1;
  for i in 1..x
  loop
    f := f * i;
  end loop;
end;
/

declare
  f int;
begin
  factorial(5, f);
  dbms_output.put_line(f);
end;
/