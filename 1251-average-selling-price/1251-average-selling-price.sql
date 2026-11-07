# Write your MySQL query statement below
-- SELECT p.product_id,ROUND(AVG(u.units*p.price),2) as average_price
-- FROM Prices p left join UnitsSold u on p.product_id=u.product_id AND u.purchase_date >= p.start_date AND u.purchase_date <= p.end_date
-- Group by p.product_id

# average not work as we need in divide total units not number of rows so above is wrong
# also i do not handle null we do it by using ifnull

SELECT p.product_id,ifnull(ROUND(SUM(u.units*p.price)/SUM(u.units),2),0) as average_price
FROM Prices p left join UnitsSold u on p.product_id=u.product_id AND u.purchase_date >= p.start_date AND u.purchase_date <= p.end_date
Group by p.product_id