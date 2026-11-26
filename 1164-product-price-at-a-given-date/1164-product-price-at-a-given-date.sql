# Write your MySQL query statement below
WITH all_products AS (
    SELECT DISTINCT product_id
    FROM Products
),
latest_price AS (                               
    SELECT product_id, new_price
    FROM Products
    WHERE (product_id, change_date) IN (
        SELECT product_id, MAX(change_date)
        FROM Products
        WHERE change_date <= '2019-08-16'
        GROUP BY product_id
    )
)
SELECT a.product_id,
       COALESCE(p.new_price, 10) AS price
FROM all_products a
LEFT JOIN latest_price p
       ON a.product_id = p.product_id;