SELECT s.user_id,
    Round((SELECT COUNT(*) 
     FROM confirmations 
     WHERE user_id = s.user_id AND LOWER(action) = 'confirmed') / count(*) ,2)AS confirmation_rate
FROM signups s 
LEFT JOIN confirmations c ON s.user_id = c.user_id group by s.user_id;
