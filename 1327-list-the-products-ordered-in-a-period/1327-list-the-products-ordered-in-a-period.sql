# Write your MySQL query statement below
with t as(
    select p.product_name,o.order_date,o.unit
    from orders o
    inner join products p
    on o.product_id=p.product_id
    where left(o.order_date,7)="2020-02"
)
select t.product_name, sum(unit) as unit
from t
group by product_name
having sum(unit)>=100;