/* Write your PL/SQL query statement below */

select e.name,b.bonus from Employee e left outer join Bonus b  

on e.empId=b.empId where b.Bonus<1000 or b.bonus is null;