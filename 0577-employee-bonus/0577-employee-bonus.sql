# Write your MySQL query statement below
select e.name, b.bonus from Employee as e LEFT JOIN bonus as b on e.empid = b.empid 
where b.bonus<1000 OR b.bonus IS NULL;