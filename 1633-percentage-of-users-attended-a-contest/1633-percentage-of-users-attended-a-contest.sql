# Write your MySQL query statement below
-- correct first try
-- with total as (
--     SELECT count(user_id) as totalUser from users
-- )
-- select contest_id,Round(count(r.user_id) *100/t.totalUser,2) as percentage
--     from (register r left join users u on r.user_id= u.user_id) join total t
--     Group by r.contest_id
--     order by percentage desc,r.contest_id asc

--  no need for joing user
with total as (
    SELECT count(user_id) as totalUser from users
)
select contest_id,Round(count(r.user_id) *100/t.totalUser,2) as percentage
    from register r join total t
    Group by r.contest_id
    order by percentage desc,r.contest_id asc