# Write your MySQL query statement below
SELECT A.name AS Employee
FROM Employee A
INNER JOIN Employee B
ON A.ManagerId = B.Id AND A.salary > B.salary