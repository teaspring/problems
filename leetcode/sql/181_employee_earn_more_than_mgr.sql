/*
Table: Employee

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| salary      | int     |
| managerId   | int     |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the ID of an employee, their name, salary, and the ID of their manager.
 

Write an SQL query to find the employees who earn more than their managers.

Return the result table in any order.
*/

select a.name as 'Employee' /* update output column name */
from Employee as a
where a.salary > (select salary from Employee as b where a.managerId = b.id)
;


/* solution2 with higher performance:
1. use inner join instead of subquery
2. put the table using primary key on left or right?
*/
select e2.name as 'Employee'
from Employee e1
inner join Employee e2 on e1.id = e2.managerId
where e1.salary < e2.salary
;