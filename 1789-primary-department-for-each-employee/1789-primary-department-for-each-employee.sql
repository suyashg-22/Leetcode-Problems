# Write your MySQL query statement below
with a as(
select employee_id, count(department_id) as cnt
from employee
group by employee_id
)

select a.employee_id,
    b.department_id
from a
inner join employee b
on a.employee_id = b.employee_id
where b.primary_flag='Y' or a.cnt=1;