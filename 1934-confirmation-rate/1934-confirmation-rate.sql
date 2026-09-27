with t as (
    select a.user_id,b.action
    from signups as a
    left join confirmations as b
    on a.user_id = b.user_id
),
temp as (
select t.user_id,count(case when t.action="confirmed" then 1 end) as cntconf
from t
group by t.user_id
),
temp2 as (
    select t.user_id,count(action) as cnttotal
    from t
    group by t.user_id
)
select temp.user_id, coalesce(round(temp.cntconf/temp2.cnttotal,2),0) as confirmation_rate
from temp
inner join temp2
on temp.user_id=temp2.user_id;
