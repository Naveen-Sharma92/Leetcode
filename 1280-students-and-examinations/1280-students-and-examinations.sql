# Write your MySQL query statement below
# wrong code as i unable to read every student even if he had not appear i need to output it.
-- SELECT st.student_id, st.student_name, s.subject_name, count(s.subject_name)
-- from (Examinations e left join Students st on e.student_id=st.student_id) left join Subjects s on e.subject_name=s.subject_name
-- Group BY st.student_id ORDER BY st.student_id asc,s.subject_name asc

-- correct code

SELECT st.student_id,st.student_name,s.subject_name,COUNT(e.subject_name) as attended_exams
#not COUNT(s.subject_name) as it will never be null e.subject_name can be null because e is left join in COUNT
from (Students st cross join Subjects s) left join Examinations e on e.subject_name=s.subject_name AND e.student_id=st.student_id
GROUP BY st.student_id,s.subject_name
Order BY st.student_id asc,s.subject_name 