/*
Table: Employee
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| id           | int     |
| name         | varchar |
| salary       | int     |
| departmentId | int     |
+--------------+---------+
id is the primary key column for this table.
departmentId is a foreign key of the ID from the Department table.
Each row of this table indicates the ID, name, and salary of an employee. It also contains the ID of their department.
 
Table: Department
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the ID of a department and its name.
 
Write an SQL query to find employees who have the highest salary in each of the departments.
Return the result table in any order.

E.g output as below:
+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Jim      | 90000  |
| Sales      | Henry    | 80000  |
| IT         | Max      | 90000  |
+------------+----------+--------+
all the employees which shares the highest salary in one department should be returned
*/

/*
* NOTE: though the question does not require output of departmentId, we still need to use constraint of departmentId;
otherwise, there would be error like:
    expected:  HR|Jim|6000, IT|Max|6000;  output: HR|Jim|6000, IT|Max|6000, HR|Max|6000, IT|Jim|6000 ...
*/

/*
1. inner join instead of subquery
2. less nested query
*/
select dts.DeptName as Department,
       e.name as Employee,
       e.salary as Salary
from Employee e
inner join (
	select d.id as DeptId, d.name as DeptName, max(e2.salary) as MaxSalary
	from Department d
	left join Employee e2
	on e2.dept_id = d.id
	group by d.id
) as dts on e.salary = dts.MaxSalary and e.departmentId = dts.DeptId