# Write your MySQL query statement below
select name from Customer where NOT referee_id=2 or referee_id is null;