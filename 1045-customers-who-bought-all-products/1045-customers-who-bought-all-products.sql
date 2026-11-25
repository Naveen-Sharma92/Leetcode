# Write your MySQL query statement below
# this is wrong see notes why it is wrong this is important
-- with total as(
--     Select count(distinct product_key) as totaln
--     from Product
-- )
-- Select c.customer_id from customer c join total t
-- group by c.customer_id having count(distinct product_key) =t.totaln

# correct one

SELECT customer_id
FROM Customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (SELECT COUNT(*) FROM Product);