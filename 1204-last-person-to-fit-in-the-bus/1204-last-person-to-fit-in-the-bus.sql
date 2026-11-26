# Write your MySQL query statement below
select p.person_name from Queue p
join Queue q on p.turn>=q.turn 
group by p.person_id
having sum(q.weight)<=1000
order by sum(q.weight) desc
limit 1;