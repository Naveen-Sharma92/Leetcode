# Write your MySQL query statement below
-- select p.person_name from Queue p
-- join Queue q on p.turn>=q.turn 
-- group by p.person_id
-- having sum(q.weight)<=1000
-- order by sum(q.weight) desc
-- limit 1;

-- usin window function for running total
WITH boarding AS (
    SELECT person_name,
           turn,
           SUM(weight) OVER (ORDER BY turn) AS total_weight
    FROM Queue
)
SELECT person_name
FROM boarding
WHERE total_weight <= 1000
ORDER BY turn DESC
LIMIT 1;