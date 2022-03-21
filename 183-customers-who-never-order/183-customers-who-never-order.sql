# Write your MySQL query statement below
SELECT A.name AS Customers
FROM Customers AS A
WHERE A.id NOT IN (
  SELECT customerid FROM orders
);
