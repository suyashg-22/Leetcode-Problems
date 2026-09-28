with t as (
    select customer_id, min(order_date) as d1, min(customer_pref_delivery_date) as d2
    from delivery
    group by customer_id
)
select 
    round(
        sum(
            case
                when t.d1=t.d2 then 1 
                else 0
            end
        )*100
        /count(t.customer_id)
    ,2) as immediate_percentage
from t;