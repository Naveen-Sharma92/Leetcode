# Write your MySQL query statement below
WITH daily AS (                                          -- step 1
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
),
moving AS (                                              -- step 2
    SELECT visited_on,
           SUM(amount) OVER (ORDER BY visited_on
                             ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS amount,
           ROW_NUMBER() OVER (ORDER BY visited_on) AS day_no
    FROM daily
)
SELECT visited_on,
       amount,
       ROUND(amount / 7, 2) AS average_amount
FROM moving
WHERE day_no >= 7                                        -- step 3
ORDER BY visited_on;