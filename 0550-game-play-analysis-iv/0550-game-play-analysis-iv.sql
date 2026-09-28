# Write your MySQL query statement below
with t1 as(
    select player_id,
    min(event_date) as mini
    from activity
    group by player_id
)
,t2 as(
    select t1.player_id,a.event_date as mini2
    from t1
    inner join
    activity a
        on t1.player_id = a.player_id
        and a.event_date= date_add(t1.mini,interval 1 day)
)
select 
    round(
        (select count(*)from t2)/
        (select count(*)from t1)
    ,2)as fraction;

