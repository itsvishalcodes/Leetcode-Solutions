# Write your MySQL query statement below
DELETE A FROM Person A, Person B
WHERE A.Email = B.Email AND A.Id > B.Id