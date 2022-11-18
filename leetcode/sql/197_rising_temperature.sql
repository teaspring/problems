/*
Table: Weather

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+
id is the primary key for this table.
This table contains information about the temperature on a certain day.
 
Write an SQL query to find all dates' Id with higher temperatures compared to its previous dates (yesterday).
Return the result table in any order.

*
*/

/*
* solution on SQLite, making use of date() function with modifier
*/
select w1.id as id
from Weather w1
join Weather w2
on date(w1.recordDate) = date(w2.recordDate, '+1 day')
where w1.temperature > w2.temperature;


/* for MySQL
*/
select w1.id
from Weather w1
join Weather w2
on DATEDIFF(w1.recordDate , w2.recordDate) = 1
where w1.temperature > w2.temperature
;