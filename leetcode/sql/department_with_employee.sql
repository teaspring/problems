/*
* Apr 2022, XXX interview, SQL question

* given employee table, with columns name, id, dept_id, salary;  department table, with columns id, name, location.
* ask to list the department and its employee numbers, including the department without employee
*/

/*
* NOTE:
1. among the output, if count(*), the department withtout actual staff will also output 1; so it must be count(empl.id)
2. difference between "group by dept.id" and "group by empl.dept_id" ? the output order may differ; if "group by dept.id", the output is in order of dept.id
*/
select dept.name as Department, count(empl.id) as Staffs
from Department dept
left join Employee empl
on dept.id = empl.dept_id
group by dept.id
