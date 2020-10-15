declare
  l number := 1;
  r number := 10;

begin
  while l <= r loop
    if mod(l, 2) = 0
    then
      dbms_output.put_line(l);
    end if;
    l := l + 1;
  end loop;
end;
/