# Write your MySQL query statement below
with side as(
    Select reports_to,count(employee_id) as reports_count,round(AVG(age),0) as average_age from Employees group by reports_to
)
select e.employee_id,
e.name,
s.reports_count,
s.average_age
from employees e left join side s on e.employee_id=s.reports_to
where s.reports_count >0
order by e.employee_id