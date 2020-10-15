declare
  num NUMBER := 12345;
  rev NUMBER := 0;

begin
  while num > 0 loop
    rev := (rev*10) + mod(num, 10);
    num := floor(num / 10);
  end loop;

  dbms_output.put_line(rev);
end;
/