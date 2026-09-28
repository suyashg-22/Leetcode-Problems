# Write your MySQL query statement below
select employee_id,department_id
from
    (select *,   
        count(department_id) over (partition by employee_id) as dcnt
    from employee
    ) as t
where t.primary_flag='Y' or t.dcnt=1;