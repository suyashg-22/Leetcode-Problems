# Write your MySQL query statement below
select distinct l1.num as consecutivenums
from
logs l1 cross join logs l2 cross join logs l3
on l1.id=l2.id-1 and l2.id=l3.id-1 and l1.num=l2.num and l2.num=l3.num;