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
select dts.department as Department,
        empl.name as Employee,
        dts.max_salary as Salary
from Employee empl, (
        select dept.name as department,
            dept.id as deptId,
            max(empl.salary) as max_salary
        from Department dept
        inner join Employee empl
        on dept.id = empl.departmentId
        group by dept.id
        order by empl.salary desc) dts
where empl.salary = dts.max_salary and empl.departmentId = dts.deptId
