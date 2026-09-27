# Write your MySQL query statement below
select name
from employee 
where id in
    (select managerid 
    from(select managerid, count(managerid) as cnt
        from employee
        group by managerid
        ) as t
    where t.cnt>=5
    )
;
