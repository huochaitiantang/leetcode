CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE num INT;
    SET num = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT IFNULL(
          (SELECT DISTINCT salary
            FROM Employee
            ORDER BY salary DESC
            LIMIT num, 1
          ),
          NULL
      ) AS getNthHighestSalary
  );
END