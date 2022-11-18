/*
Table: Person
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table contains an email. The emails will not contain uppercase letters.
 
Write an SQL query to delete all the duplicate emails, keeping only one unique email with the smallest id.
NOTE: that you are supposed to write a DELETE statement and not a SELECT one.

After running your script, the answer shown is the Person table. The driver will first compile and run your piece of code and then show the Person table. The final order of the Person table does not matter.
*/


/*
* NOTE potential "MySQL can't specify target table xxx for update in FROM clause"
* to resolve: nominate an alias for "from ()"
* 
* this solution has good performance in runtime
*/
delete from Person
where id not in (
    select min(p1.id)
    from (select * from Person) as p1
    group by p1.email
    order by p1.id
);

/*
* using Cartesian Join also called cross json, better to read but as slow as 4 times of above solution's runtime
* "from table_1, table_2" play role of " table_1 cross join table_2"
*/
delete p1 from person p1, person p2 
where p1.email = p2.email and p1.id > p2.id;
