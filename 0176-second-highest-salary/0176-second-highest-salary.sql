# Write your MySQL query statement below
WITH ranked AS (
    SELECT salary,
           DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
    FROM Employee
)
SELECT max(salary) AS SecondHighestSalary #max is used so that if there is no second highest it return null instead of empty response
FROM ranked
WHERE rnk = 2;