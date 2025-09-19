-- database problem #175
--
-- table Person:
-- +--- Person ---+
-- 0|PersonId|int
-- 1|FirstName|varchar
-- 2|LastName|varchar
-- +--------------+
--
-- table Address:
-- +--- Address --+
-- 0|AddressId|int
-- 1|PersonId|int
-- 2|City|varchar
-- 3|State|varchar
-- +--------------+
--
-- to query following columns for each person in the Person table,
-- regardless if there is an address for each of them
-- FirstName, LastName, City, State

select Person.FirstName, Person.LastName, Address.City, Address.State
from Person
left join Address
on Person.PersonId = Address.PersonId
