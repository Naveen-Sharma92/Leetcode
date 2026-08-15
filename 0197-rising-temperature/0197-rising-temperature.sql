# Write your MySQL query statement below
select p.id from Weather as p cross join Weather as y
where datediff(p.recorddate,y.recorddate)=1 AND p.temperature >y.temperature