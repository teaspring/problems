/*
Table: Customers
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the ID and name of a customer.
 
Table: Orders
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| customerId  | int  |
+-------------+------+
id is the primary key column for this table.
customerId is a foreign key of the ID from the Customers table.
Each row of this table indicates the ID of an order and the ID of the customer who ordered it.
 
Write an SQL query to report all customers who never order anything.
Return the result table in any order.
*/

select c.name from Customers c
left join Orders o
on c.id = o.customerId
group by c.id
having count(o.id) = 0
;

select c.name from Customers c
where c.id not in (
    select distinct customerId from Orders
);