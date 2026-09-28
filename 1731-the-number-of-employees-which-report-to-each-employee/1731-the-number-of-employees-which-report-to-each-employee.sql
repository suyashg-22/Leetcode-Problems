# Write your MySQL query statement below
with a as(select reports_to, 
    count(reports_to) as cnt,
    round(avg(age),0) as avage 
from employees
where reports_to is not null
group by reports_to
)

select b.employee_id,b.name,a.cnt as reports_count,a.avage as average_age
from a
inner join
employees as b
on a.reports_to =b.employee_id
order by b.employee_id; 