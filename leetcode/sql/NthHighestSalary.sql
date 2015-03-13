-- database problem #177
--
-- write a stored procedure(SP) to get the Nth highest salary from the Employee table
-- note: if there is no Nth highest salary, return null

create function getNthHighestSalary(N int) returns int
begin
    declare M int;
    set M=N-1;
    return{
        select distinct Salary from Employee order by Salary desc limit M,1
    };
end

