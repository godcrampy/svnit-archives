declare
    cursor test_cursor
    is
        select * 
        from emp
        where sal < 50000;
begin

    for itr in test_cursor
    loop
        dbms_output.put_line(itr.ename);
    end loop;

end;
/
