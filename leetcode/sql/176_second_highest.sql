/* 
Table: Employee

+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
id is the primary key column for this table.
Each row of this table contains information about the salary of an employee.
 
Write an SQL query to report the second highest salary from the Employee table. If there is no second highest salary, the query should report null.
*/

/* solution 1, fast with less readability */
select min(a.salary) as "SecondHighestSalary"
from (
  select distinct salary
  from Employee
  where (
    select count(distinct salary)
    from Employee) > 1
  order by salary desc
  limit 2) as a
;

/* solution 2, better to read but slower */
select max(salary) from Employee
where salary < (select max(salary) from Employee);

/* solution 3, simple and fast */
select distinct salary from Employee
order by Salary desc
limit 1 offset 1;
/* limit <count> offset <skip> */