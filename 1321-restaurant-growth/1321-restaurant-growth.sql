# Write your MySQL query statement below
with t as(
    select visited_on,
    sum(amount) as amount
    from customer 
    group by visited_on
)

select c1.visited_on
    ,sum(c2.amount) as amount
    ,round(sum(c2.amount)/7,2) as average_amount
from t c1
cross join t c2
where c1.visited_on>= c2.visited_on
and datediff(c1.visited_on,c2.visited_on)<=6
group by c1.visited_on
having c1.visited_on - interval 6 day in (select distinct visited_on from customer)
order by c1.visited_on; 
