# Write your MySQL query statement below
select Sales.year,Sales.price , Product.product_name
from Sales , Product
where Sales.product_id=Product.product_id;