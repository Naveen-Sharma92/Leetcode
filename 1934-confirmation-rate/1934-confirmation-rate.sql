# Write your MySQL query statement below
WITH confirmed AS (                      -- confirmed requests per user
    SELECT user_id, COUNT(*) AS confirmed_cnt
    FROM Confirmations
    WHERE action = 'confirmed'           -- row filter → WHERE, not HAVING
    GROUP BY user_id
),
total AS (                               -- all requests per user
    SELECT user_id, COUNT(*) AS total_cnt
    FROM Confirmations
    GROUP BY user_id
)
SELECT s.user_id,
       ROUND(COALESCE(cf.confirmed_cnt / t.total_cnt, 0), 2) AS confirmation_rate
FROM Signups s
LEFT JOIN total t      ON s.user_id = t.user_id
LEFT JOIN confirmed cf ON s.user_id = cf.user_id;


# best code basic join
-- SELECT s.user_id,
--        ROUND(AVG(CASE WHEN c.action = 'confirmed' THEN 1 ELSE 0 END), 2)
--            AS confirmation_rate
-- FROM Signups s
-- LEFT JOIN Confirmations c
--        ON s.user_id = c.user_id
-- GROUP BY s.user_id;