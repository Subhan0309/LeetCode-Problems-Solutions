# Write your MySQL query statement below
# select case ( when unique_id = null then "null" else unique_id ) , name 

select unique_id , name from Employees left outer join EmployeeUNI on Employees.id=EmployeeUNI.id
