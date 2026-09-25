# Write your MySQL query statement below
select t1.student_id,t1.student_name,t1.subject_name,coalesce(t2.cnt,0) as attended_exams
from (select tt1.student_id,tt1.student_name,tt2.subject_name
    from students as tt1
    cross join
    subjects as tt2)
    as t1
left join
    (select temp.student_id, temp.subject_name, count(temp.student_id) as cnt
    from examinations as temp
    group by  temp.student_id,temp.subject_name)
    as t2
on t1.student_id = t2.student_id and t1.subject_name=t2.subject_name
order by t1.student_id, t1.subject_name;