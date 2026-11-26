# Write your MySQL query statement below
WITH counts AS (
    SELECT tiv_2016,
           COUNT(*) OVER (PARTITION BY tiv_2015) AS same_tiv,
           COUNT(*) OVER (PARTITION BY lat, lon) AS same_location
    FROM Insurance
)
SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM counts
WHERE same_tiv > 1
  AND same_location = 1;