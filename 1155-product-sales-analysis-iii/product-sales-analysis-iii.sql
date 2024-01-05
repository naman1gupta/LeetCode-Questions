WITH
  cte_first_year AS (
    SELECT
      product_id,
      year,
      quantity,
      price,
      RANK() OVER (PARTITION BY product_id ORDER BY year) AS year_number
    FROM
      Sales
  )

SELECT
  product_id,
  year AS first_year,
  quantity,
  price
FROM
  cte_first_year
WHERE
  year_number = 1