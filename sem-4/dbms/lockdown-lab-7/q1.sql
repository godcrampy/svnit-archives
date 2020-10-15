create or replace trigger age_listener
before insert on students
for each row
when (NEW.id > 0)
declare
  exp exception;
  pragma exception_init(exp, -2001);
begin
  if :NEW.age > 30
  then
    raise exp;
  end if;
end;
/
