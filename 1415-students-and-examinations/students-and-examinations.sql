-- select stu.student_id , stu.student_name,sub.subject_name,count(*) from
-- students stu  full outer join examinations exa  on
-- stu.student_id=exa.student_id full outer join subjects sub on sub.subject_name = exa.subject_name
-- group by stu.student_id , stu.student_name,sub.subject_name;


select stu.student_id , stu.student_name,sub.subject_name ,
(select count(*) from examinations where student_id=stu.student_id 
and subject_name= sub.subject_name) attended_exams

from students stu , subjects sub
group by stu.student_id , stu.student_name,sub.subject_name 
order by  stu.student_id,sub.subject_name
