select Users.user_id , CONCAT(upper(substr(Users.name, 1, 1)), lower(substr(Users.name, 2))) as name
from Users
order by Users.user_id asc