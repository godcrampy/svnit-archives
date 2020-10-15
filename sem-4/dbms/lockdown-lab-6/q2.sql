create or replace procedure marks_to_grade(marks in int, grade out char)
is
begin
  if marks < 25 then
    grade := 'D';
  elsif marks < 50 then
    grade := 'C';
  elsif marks < 75 then
    grade := 'B';
  else
    grade := 'A';
  end if;
end;
/

declare
  m1 int := 45;
  g1 char;
  m2 int := 80;
  g2 char;
begin
  marks_to_grade(m1, g1);
  marks_to_grade(m2, g2);
  dbms_output.put_line(m1 || ' : ' || g1);
  dbms_output.put_line(m2 || ' : ' || g2);
end;
/
