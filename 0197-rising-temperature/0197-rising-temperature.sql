# Write your MySQL query statement below
#select p.id from Weather as p cross join Weather as y where datediff(p.recorddate,y.recorddate)=1 AND p.temperature >y.temperature

#optimal way self join

#select p.id from weather p,weather y where datediff(p.recorddate,y.recorddate)=1 AND p.temperature >y.temperature


-- revise
select p.id 
from weather p left join weather y 
on datediff(p.recorddate,y.recorddate)=1
where p.temperature > y.temperature