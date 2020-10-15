declare
  num number := 12345;
  s number := 0;
begin
  while num > 0 loop
    s := s + mod(num, 10);
    num := floor(num / 10);
  end loop;
  dbms_output.put_line(s);
end;
/