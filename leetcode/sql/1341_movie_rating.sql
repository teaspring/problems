/*
* 1341 - Movie Rating
* Level - medium

Table: Movies
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| movie_id      | int     |
| title         | varchar |
+---------------+---------+
movie_id is the primary key (column with unique values) for this table.
title is the name of the movie. 

Table: Users
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| name          | varchar |
+---------------+---------+
user_id is the primary key (column with unique values) for this table. The column 'name' has unique values.

Table: MovieRating
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| movie_id      | int     |
| user_id       | int     |
| rating        | int     |
| created_at    | date    |
+---------------+---------+
(movie_id, user_id) is the primary key (column with unique values) for this table.
This table contains the rating of a movie by a user in their review. created_at is the user's review date. 

Write a solution to:
Find the name of the user who has rated the greatest number of movies. In case of a tie, return the lexicographically smaller user name.
Find the movie name with the highest average rating in February 2020. In case of a tie, return the lexicographically smaller movie name.
the output result can be:
+--------------+
| results      |
+--------------+
| Daniel       |
| Frozen 2     |
+--------------+
*/

/*
* solution 1: use derived table, performance is medium, not bad
* NOTE: 'union all' is necessary as the user and movie may be same string.
*/
(select u.name as Results
from Users u
join
    (select user_id, count(movie_id) as sum_movie
    from MovieRating
    group by user_id) as u_sum
on u.user_id = u_sum.user_id
order by u_sum.sum_movie desc, u.name
limit 1)

union all

(select m.title as Results
from Movies m
join 
    (select r.movie_id, avg(r.rating) as avg_rating
    from MovieRating r
    where r.created_at > '2020-01-31' and r.created_at < '2020-03-01'
    group by r.movie_id) as m_avg 
on m.movie_id = m_avg.movie_id
order by m_avg.avg_rating desc, m.title
limit 1
)

/*
* solution 2: WITH- clause instead of devrived table, with a little bit better performance
*/
(with u_sum as 
    (select user_id, count(movie_id) as sum_movie
    from MovieRating
    group by user_id)
select u.name as Results
from Users u
join u_sum
on u.user_id = u_sum.user_id
order by u_sum.sum_movie desc, u.name
limit 1)

union all

(with m_avg as
    (select r.movie_id, avg(r.rating) as avg_rating
    from MovieRating r
    where r.created_at > '2020-01-31' and r.created_at < '2020-03-01'
    group by r.movie_id)
select m.title as Results
from Movies m
join m_avg 
on m.movie_id = m_avg.movie_id
order by m_avg.avg_rating desc, m.title
limit 1
)