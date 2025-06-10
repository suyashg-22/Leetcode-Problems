SELECT d.name AS department, e.name AS employee, e.salary
FROM employee e
JOIN department d ON e.departmentId = d.id
WHERE (e.departmentId, e.salary) IN (
    SELECT e2.departmentId, MAX(e2.salary)
    FROM employee e2
    GROUP BY e2.departmentId
);
