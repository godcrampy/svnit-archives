create or replace trigger insert_listener
before update on students
for each row
when (NEW.id > 0)
declare
  diff number;
begin
  diff := :NEW.marks  - :OLD.marks; 
  dbms_output.put_line('Old Marks: ' || :OLD.marks); 
  dbms_output.put_line('New Marks: ' || :NEW.marks); 
  dbms_output.put_line('Marks Difference: ' || diff); 
end;
/
