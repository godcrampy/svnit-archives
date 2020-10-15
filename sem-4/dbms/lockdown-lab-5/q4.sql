declare
    cursor test_cursor
    is
        select count(*)
        from emp
        where sal < 50000;
    
    counter int := 1;
begin
    for itr in test_cursor
    loop
        counter := counter + 1;
    end loop;
    
    dbms_output.put_line(counter);
end;
/