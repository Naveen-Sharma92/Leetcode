# Write your MySQL query statement below
with total as(
    select employee_id,count(employee_id) as count_e from Employee group by employee_id
)
Select e.employee_id,e.department_id from Employee e left join total t on e.employee_id=t.employee_id where t.count_e=1 or e.primary_flag='Y'