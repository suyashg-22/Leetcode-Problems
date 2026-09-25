# Write your MySQL query statement below
select t1.id
from weather as t1
cross join
weather as t2
where DATEDIFF(t1.recorddate,t2.recorddate)=1
and t1.temperature > t2.temperature;