SELECT emp.name 
FROM employee AS emp 
JOIN employee AS manager ON emp.id = manager.managerId 
GROUP BY manager.managerId 
HAVING COUNT(manager.managerId) >= 5;
