# Write your MySQL query statement below
select t1.user_id,
    coalesce(round(sum(t2.action="confirmed")/count(t1.user_id),2),0) as confirmation_rate
from signups as t1
left join confirmations as t2
on t1.user_id=t2.user_id
group by t1.user_id;