# Write your MySQL query statement below
with first as(
    select player_id,min(event_date) as mini from activity group by player_id
)
select round(sum(case WHEN DATEDIFF(a.event_date, f.mini) = 1 THEN 1 ELSE 0 END)/ count(distinct a.player_id),2) as fraction 
from activity a left join first f on a.player_id=f.player_id
