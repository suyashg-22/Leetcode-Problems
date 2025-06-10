SELECT p.firstName AS firstName, p.lastName AS lastName, a.city AS city, a.state AS state
FROM person p
LEFT JOIN address a ON p.personId = a.personId;
