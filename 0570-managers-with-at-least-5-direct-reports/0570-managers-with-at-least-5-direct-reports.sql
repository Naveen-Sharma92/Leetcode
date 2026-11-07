# Write your MySQL query statement below
WITH a AS (SELECT managerID 
from Employee 
Group by managerID HAVING count(managerID) >=5)
SELECT name from EMPLOYEE where id in ((SELECT managerID FROM a));