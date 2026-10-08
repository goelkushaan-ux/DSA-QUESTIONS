# Write your MySQL query statement below
select employee_id from Employees a
where a.salary <30000 and
      a.manager_id IS NOT NULL
    and not exists (
    select 1
    from Employees b
    where a.manager_id = b.employee_id
)
    order by a.employee_id;