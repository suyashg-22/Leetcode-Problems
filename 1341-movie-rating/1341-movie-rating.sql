# Write your MySQL query statement below
with t as(
    select m.*,mm.title,u.name
    from movierating m
    inner join users u
    on u.user_id = m.user_id
    inner join movies mm
    on mm.movie_id = m.movie_id 
)

(select t.name as results
from t
group by t.user_id
order by count(t.user_id) desc, t.name asc
limit 1)
union all
(select t.title as results
from t
where substr(created_at,1,7)="2020-02"
group by t.movie_id
order by avg(t.rating) desc, t.title asc
limit 1);