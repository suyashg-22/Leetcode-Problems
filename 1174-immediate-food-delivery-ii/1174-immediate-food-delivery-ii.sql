# Write your MySQL query statement below
select 
    round((sum(case when t1.order_date=t1.customer_pref_delivery_date then 1 else 0 end)*100/count(t1.customer_id)),2)as immediate_percentage
from delivery t1
    inner join
    (select customer_id,min(order_date) as mini
    from delivery
    group by customer_id
    ) t2
on t1.customer_id=t2.customer_id and t1.order_date=t2.mini;

