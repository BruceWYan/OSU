-- Find the film_title of all films which feature both RALPH CRUZ and WILL WILSON
-- Order the results by film_title in ascending order.
--  Warning: this is a tricky one and while the syntax is all things you know, you have to think a bit oustide the box to figure out how to get a table that shows pairs of actors in movies.


-- Put your query for q5 here.

SELECT DISTINCT
    film.title AS film_title
FROM
    actor
JOIN
    film_actor ON actor.actor_id = film_actor.actor_id
JOIN
    film ON film_actor.film_id = film.film_id
WHERE
    (actor.first_name = 'RALPH' AND actor.last_name = 'CRUZ')
    AND film.film_id IN (
        SELECT film_id FROM film_actor
        JOIN actor ON film_actor.actor_id = actor.actor_id
        WHERE (actor.first_name = 'WILL' AND actor.last_name = 'WILSON')
    )
ORDER BY
    film.title ASC;
