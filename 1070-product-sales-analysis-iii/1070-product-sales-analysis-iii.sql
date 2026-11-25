# Write your MySQL query statement below
with first as (
    select product_id,min(year) as first_year 
    from Sales group by product_id  
)
select s.product_id,f.first_year,s.quantity,s.price from Sales s left join first f on s.product_id=f.product_id where s.year=f.first_year