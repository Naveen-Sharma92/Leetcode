# Write your MySQL query statement below
with ranked as(
    select d.name AS Department,
    e.name as Employee
    ,e.salary as Salary,
    dense_rank() over (partition by e.departmentId order by e.salary desc) as rnk
    from employee e left join department d on e.departmentid = d.id
)
select Department, Employee, Salary FROM ranked WHERE rnk <= 3;