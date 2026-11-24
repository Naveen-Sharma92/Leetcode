# Write your MySQL query statement below
WITH first_orders AS (
    SELECT customer_id, MIN(order_date) AS first_date
    FROM Delivery
    GROUP BY customer_id
)
SELECT round(sum(case order_date=customer_pref_delivery_date when true then 1 else 0 end)*100/count(*),2) as immediate_percentage 
FROM Delivery d
JOIN first_orders f
  ON  d.customer_id = f.customer_id
  AND d.order_date  = f.first_date;