# Write your MySQL query statement below
with t as(
   (select
    requester_id as id
    from requestaccepted
    )
union all
    (select
    accepter_id as id
    from requestaccepted
    )
)

select t.id,count(t.id) as num
from t
group by t.id
order by count(t.id) desc
limit 1;
