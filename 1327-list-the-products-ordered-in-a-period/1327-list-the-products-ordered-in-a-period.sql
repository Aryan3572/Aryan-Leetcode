# Write your MySQL query statement below
select Products.product_name, sum(unit) as unit
from Products
join Orders
on Products.product_id = Orders.product_id 
where month(order_date) = 2 and year(order_date) = 2020
group by product_name 
having sum(unit) >= 100