SELECT teacher_id, count(distinct (subject_id)) AS cnt
FROM Teacher
GROUP BY teacher_id;