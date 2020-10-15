declare
  a number;

begin
  for a in 1..5 loop
    dbms_output.put_line(a * 3.14 * 3.14);
  end loop;
end;
/