# Write your MySQL query statement below
with a as (select product_id, min(year) as mini
from sales
group by product_id
)
select b.product_id,b.year as first_year,b.quantity,b.price
from a
inner join
sales as b
on a.product_id = b.product_id and a.mini=b.year;