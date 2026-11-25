# Write your MySQL query statement below
select max(maxi) as num from (select num as maxi from MyNumbers group by num having count(num)<2) as n