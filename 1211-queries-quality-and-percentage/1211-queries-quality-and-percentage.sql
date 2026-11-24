# Write your MySQL query statement below
With rating as(
    -- Select query_name,count(case when rating<3 then 1 else 0 end)/count(*) as poor_query_percentage from Queries group by query_name
    Select query_name,round(sum(case when rating<3 then 1 else 0 end)*100/count(*),2) as poor_query_percentage from Queries group by query_name
    -- count count all values except null so use sum i can also use avg
),
qualities as(
    Select query_name,round(AVG(rating/position),2) as quality from Queries group by query_name
)
Select q.query_name,qu.quality,r.poor_query_percentage from (Queries q left join rating r on r.query_name=q.query_name) left join qualities qu on q.query_name=qu.query_name group by query_name