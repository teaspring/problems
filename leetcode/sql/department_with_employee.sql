/*
* Apr 2022, XXX interview, SQL question

* given employee table: columns name, id, dept_id, salary;
* department table: columns id, name, location.
* ask to list the department and its employee numbers, if the department has no employee return 0 as its employee number
*/

/*
NOTE: No need of wrapping up count(empl.id) via ifnull(). if there is no employee in that department, count(empl.id) will return 0.
*/
select dept.name as Department, count(empl.id) as Staffs
from Department dept
left join Employee empl
on dept.id = empl.dept_id
group by dept.id
