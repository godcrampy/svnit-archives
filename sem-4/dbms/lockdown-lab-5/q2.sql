declare
begin
    update emp
    set sal = sal + 1000
    where deptno = 10;
    
    update emp
    set sal = sal + 500
    where deptno = 20;
    
    update emp
    set sal = sal + 800
    where deptno = 30;
end;
/