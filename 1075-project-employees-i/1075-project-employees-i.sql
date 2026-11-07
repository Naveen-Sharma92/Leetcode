# Write your MySQL query statement below

SELECT project_id,ROUND(ifnull(AVG(e.experience_years),0),2) as average_years
from Project p left join Employee e on p.employee_id=e.employee_id
Group by p.project_id
