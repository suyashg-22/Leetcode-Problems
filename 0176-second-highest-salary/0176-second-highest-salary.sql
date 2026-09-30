select 
    coalesce(max(salary),null) as secondhighestsalary
from employee
where salary not in(select max(salary) from employee);