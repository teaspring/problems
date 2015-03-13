-- database problem #176
--
-- query to get the second highest salary from the Employee table
-- +--- Employee --+
-- 0|Id|int
-- 1|Salary|int
-- Note: if there is no second highest salary, then return null

select max(Salary) from Employee where Salary < (select max(salary) from Employee);
