# Write your MySQL query statement below
select t1.machine_id, Round(avg(t1.timestamp-t2.timestamp),3) as processing_time from Activity as t1,activity as t2 
where t1.machine_id = t2.machine_id AND t1.activity_type = 'end' AND t2.activity_type = 'start' AND t1.process_id = t2.process_id
Group by t1.machine_id