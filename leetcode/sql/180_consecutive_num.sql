/*
Table: Logs
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| num         | varchar |
+-------------+---------+
id is the primary key for this table.
id is an autoincrement column.

Write an SQL query to find all numbers that appear at least three times consecutively, return as ConsecutiveNums
Return the result table in any order.
*/

select distinct num as ConsecutiveNums
from Logs
where (id+1, num) in (select * from Logs)
    and (id+2, num) in (select * from Logs)
;


/*
* cross join/Cartersian join, in worse performance
*/
select distinct l1.num as ConsecutiveNums
from Logs l1, Logs l2, Logs l3
where l1.id = l2.id - 1 and l2.id = l3.id - 2
    and l1.num = l2.num and l2.num = l3.num
;
