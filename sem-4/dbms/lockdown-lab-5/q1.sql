declare
    cursor test_cursor
    is
        select * 
        from emp
        where deptno = 10;
begin

    for itr in test_cursor
    loop
        dbms_output.put_line(itr.empno || ' ' || itr.ename || ' ' || itr.job);
    end loop;

end;
/