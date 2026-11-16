-- select e1.employee_id
-- from Employees e1
-- left join Employees e2
-- on e1.manager_id = e2.employee_id
-- where e1.salary <= 30000 and e2.employee_id is null and e1.manager_id is not null
-- order by employee_id 

SELECT employee_id
FROM Employees
WHERE salary < 30000
AND manager_id NOT IN (
  SELECT employee_id FROM Employees
)
ORDER BY employee_id;