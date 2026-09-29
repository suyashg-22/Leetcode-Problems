WITH categories AS (
    SELECT 'Low Salary' AS category
    UNION ALL
    SELECT 'Average Salary'
    UNION ALL
    SELECT 'High Salary'
),
counts AS (
    SELECT
        CASE
            WHEN income < 20000 THEN 'Low Salary'
            WHEN income <= 50000 THEN 'Average Salary'
            ELSE 'High Salary'
        END AS category,
        COUNT(*) AS accounts_count
    FROM accounts
    GROUP BY category
)
SELECT
    c.category,
    COALESCE(x.accounts_count, 0) AS accounts_count
FROM categories c
LEFT JOIN counts x
    ON c.category = x.category;