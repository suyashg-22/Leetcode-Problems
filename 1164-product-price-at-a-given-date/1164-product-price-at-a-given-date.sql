with t as (
    select distinct product_id,
        first_value(new_price) over(partition by product_id order by change_date desc) as nprice
    from products
    where change_date<="2019-08-16"
)
, t2 as (
    select distinct product_id
    from products
)

select t2.product_id
    ,(case
        when t.nprice is null then 10
        else t.nprice
    end) as price
from t2 left join t
on t2.product_id = t.product_id; 