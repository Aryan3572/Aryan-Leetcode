select product_name , year, price
from Sales
inner join Product
on sales.product_id = Product.product_id;