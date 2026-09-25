# Write your MySQL query statement below
select t3.student_id, t3.student_name,t3.subject_name, count(t4.student_id) as attended_exams
from (select t1.student_id,t1.student_name,t2.subject_name
    from students t1
    cross join
    subjects t2
    ) as t3
left join
examinations as t4
on t3.student_id = t4.student_id
and t3.subject_name=t4.subject_name
group by t3.student_id, t3.subject_name
order by t3.student_id, t3.subject_name;