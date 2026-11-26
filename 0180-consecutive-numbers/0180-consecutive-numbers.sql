# Write your MySQL query statement below
select distinct l1.num as ConsecutiveNums 
from (logs l1 left join logs l2 on l1.id-l2.id=1) left join logs l3 on l2.id-l3.id=1
where (l1.num=l2.num) and (l2.num=l3.num)

-- i had not use distinct in above so get duplicate entries also so rememeber to use distinct