
select email as email from person group by email having count(email)>1;