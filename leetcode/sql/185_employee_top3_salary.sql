/*
* 185, Department Top Three Salaries
* level - HARD
*
* Table: Employee
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| id           | int     |
| name         | varchar |
| salary       | int     |
| departmentId | int     |
+--------------+---------+
id is the primary key (column with unique values) for this table.
departmentId is a foreign key (reference column) of the ID from the Department table.
Each row of this table indicates the ID, name, and salary of an employee. It also contains the ID of their department.
 
Table: Department
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the ID of a department and its name.
 
A company's executives are interested in seeing who earns the most money in each of the company's departments. A high earner in a department is an employee who has a salary in the top three unique salaries for that department.

Write a SQL to find the employees who are high earners in each of the departments.
Return the result table in any order.
*/

/*
* the necessary prerequisites:
* 1. WITH clause, using an ordinary Common Table Expression(CTE)
* 2. window function, dense_rank() to provide the dense ranks
*/
WITH RankedSalaries AS (
    SELECT 
        e.name AS Employee,
        e.salary AS Salary,
        d.name AS Department,
        dense_rank() OVER (PARTITION BY d.id ORDER BY e.salary DESC) AS salary_rank
    FROM 
        Employee e
    JOIN 
        Department d ON e.departmentId = d.id
)
SELECT 
    Department,
    Employee,
    Salary
FROM 
    RankedSalaries
WHERE 
    salary_rank <= 3
ORDER BY 
    Department, 
    salary_rank;