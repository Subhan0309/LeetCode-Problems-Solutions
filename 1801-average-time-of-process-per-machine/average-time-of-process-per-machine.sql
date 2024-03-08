

select R.machine_id,ROUND(sum(R.time_taken)/count(*),3) processing_time from (

select a.machine_id ,a.process_id,

(select timestamp from activity b where lower(activity_type)='end' and b.machine_id=a.machine_id
 and b.process_id=a.process_id) -
  (select timestamp from activity c where lower(activity_type)='start' and c.machine_id=a.machine_id
 and  c.process_id=a.process_id) time_taken

from activity a
group by a.machine_id,a.process_id )  R group by R.machine_id order by R.machine_id