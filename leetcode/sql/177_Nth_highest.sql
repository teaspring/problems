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

Write an SQL query to report the nth highest salary from the Employee table. If there is no nth highest salary, the query should report null.
*/

/* "limit <count> offset <skip>" equivalent with "limit <skip>, <count>" */
/* offset = N-1 */
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  declare M int;
  set M = N-1;
  RETURN (
      select distinct Salary from Employee order by Salary desc limit M, 1
  );
END
