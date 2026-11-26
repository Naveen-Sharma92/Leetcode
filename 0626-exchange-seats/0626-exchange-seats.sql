# Write your MySQL query statement below
SELECT CASE
           WHEN id % 2 = 1 AND id = (SELECT MAX(id) FROM Seat) THEN id   -- last odd seat stays
           WHEN id % 2 = 1 THEN id + 1                                    -- odd moves forward
           ELSE id - 1                                                    -- even moves back
       END AS id,
       student
FROM Seat
ORDER BY id;