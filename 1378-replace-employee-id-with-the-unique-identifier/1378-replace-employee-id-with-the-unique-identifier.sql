# Write your MySQL query statement below
select unique_id, name 
from employees as t1
left join
employeeuni as t2
on t1.id = t2.id;