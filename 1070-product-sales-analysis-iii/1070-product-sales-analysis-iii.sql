select Sales.product_id , Sales.year as first_year , Sales.quantity , Sales.price
from Sales
join (select product_id , min(year) as first_year
        from Sales 
        group by product_id) t
on Sales.product_id = t.product_id
and Sales.year = t.first_year