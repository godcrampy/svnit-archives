declare
  a number := 4;
  b number := 1;
  c number := 5;

begin
  if a > b then
    if a > c then
      dbms_output.put_line(a);
    else
      dbms_output.put_line(c);
    end if;
  else
    if b > c then
      dbms_output.put_line(b);
    else
      dbms_output.put_line(c);
    end if;
  end if;
end;
/