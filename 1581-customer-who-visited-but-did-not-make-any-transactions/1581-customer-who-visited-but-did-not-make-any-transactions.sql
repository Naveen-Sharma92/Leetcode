# Write your MySQL query statement below
Select v.customer_id, count(v.customer_id) as count_no_trans 
from Visits as v left join transactions as t on v.visit_id = t.visit_id  
where transaction_id IS NULL Group by v.customer_id