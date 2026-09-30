# Write your MySQL query statement below
select t.department,t.name as employee,t.salary 
from (select e.name,e.salary,d.name as department,
        dense_rank() over (partition by e.departmentid order by e.salary desc ) as drnk
    from employee e
    inner join department d
    on e.departmentid=d.id
    ) as t
where drnk<=3;