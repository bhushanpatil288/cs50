-- Keep a log of any SQL queries you execute as you solve the mystery.



-- 1) INITIAL INVESTIGATION (GOAL GET THE ID OF CRIME)

-- okay so theft took place on 28 july, 2024 and on Humphrey Street

-- I will check first 10 columns in crime_scene_report to get idea of table first

-- okay okay let me add filters now
-- SELECT * FROM crime_scene_reports WHERE year = 2024 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

-- Okay so I got it its id is 295







-- AFTER INITIAL INVESTIGATION
-- CURRENT info I have

-- Date: 28-07-2024
-- place:  Humphrey Street
-- theft time: 10:15 am
-- Interviews were conducted with three witnesses who were present at that time each of their interview transcripts mentions the bakery.



-- 2) Check bakery_security_logs now

-- okay I checked first ten and I can apply days, month and year filter now
-- i don't know what to do now xD there are many columns.

-- okay so I just checked we also have Inverviews table let me check it out now.

-- so I got the following information;

-- 161 | Ruth
-- Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame
-- 162 | Eugene
-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- 163 | Raymond
-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.




-- AFTER INITIAL INVESTIGATION
-- CURRENT info I have

-- Date: 28-07-2024
-- place:  Humphrey Street
-- theft time: 10:15 am
-- Interviews were conducted with three witnesses who were present at that time each of their interview transcripts mentions the Emma's bakery.


-- AFTER SECOND INVESTIGATION

-- Ruth : Theif got into a car in the bakery parking lot and drove away, he said I should check for cars that left the parking lot in that time frame. (within 10 minutes of the theft means 10.15 to 10.25)
-- Eugene : he recognized his face but not name, before arriving at bakery he was walking by ATM ON leggett street and saw theif withdrawing some money.
-- Raymond : while leaving bakery he called someone and talked them for less than a minute in a call, theif said they were planning to take the "earliest" flight out of Fiftyville tomorrow (means 29-07-2024). he asked person on call to purchase the flight ticket.

-- CONCLUSION

-- I should check parking lot for time frame of 10.15 to 10.25;
-- At morning theif Withdrawed money from leggett street ATM.  (atm_transactions,  bank_accounts)
-- he talked to someone (less than 60s) so check (phone_calls) planning to take the earliest flight at 29-07-2024(flights , airports, passengers )


-- 3) check atm
-- it happend on Leggett street and he withdrawn the money
-- huh got 8 entries (SELECT * FROM atm_transactions WHERE atm_location='Leggett Street' AND transaction_type='withdraw' AND day=28 AND year=2024 AND month=7;) <- I will check it again

-- 4) check phone
-- for now lets check phone_calls
-- he talked less than 60s
-- got 9 entries (SELECT * FROM phone_calls WHERE duration<60 AND day=28 AND year=2024 AND month=7;)

-- 5) check flights
-- okay there is origin_airport_id and destination_airport id (lets check id Fiftyville which is going to be origin)
-- got id = 8;
-- lets check flights again now (SELECT * FROM flights WHERE origin_airport_id=8 AND  day=29 AND year=2024 AND month=7;)
-- now entries are 5;
-- he said earliest so it must be of id 36 (just a speculation for now)
-- so if its 36 then its going to id 4 which is NEW york city  (SELECT * FROM airports WHERE id=4;)



-- so after collecting everything info I have is
-- he too flight of 8:20 for NEW YORK CITY at 29-07-2024

-- 6) check passesngers
-- there are 6 entries for flight id 8 (SELECT * FROM passengers WHERE flight_id = 8;)

-- 7) check these peoples for phone number; (SELECT * FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 8))
-- okay got their numbers now lets check these numbers against those 9 entries I got

-- I kind of lost here
-- I thought I should do this (SELECT * FROM phone_calls WHERE duration<60 AND day=28 AND year=2024 AND month=7 AND caller IN (SELECT phone_number FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 8));)
-- but it is not giving result
-- okay fixed flight_id should 36 (SELECT * FROM phone_calls WHERE duration<60 AND day=28 AND year=2024 AND month=7 AND caller IN (SELECT phone_number FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36));)
-- from 9 to 7 now
-- let me now check thier names
--


-- okay lets check time frame first now
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- | id  | year | month | day | hour | minute | activity | license_plate |
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- | 260 | 2024 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
-- | 261 | 2024 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
-- | 262 | 2024 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
-- | 263 | 2024 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
-- | 264 | 2024 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
-- | 265 | 2024 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
-- | 266 | 2024 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
-- | 267 | 2024 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |

-- passengers of flight 36
-- | flight_id | passport_number | seat |
-- +-----------+-----------------+------+
-- | 36        | 7214083635      | 2A   |
-- | 36        | 1695452385      | 3B   |
-- | 36        | 5773159633      | 4A   |
-- | 36        | 1540955065      | 5C   |
-- | 36        | 8294398571      | 6C   |
-- | 36        | 1988161715      | 6D   |
-- | 36        | 9878712108      | 7A   |
-- | 36        | 8496433585      | 7B   |
-- +-----------+-----------------+------+

-- possible thieves
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | id  |     caller     |    receiver    | year | month | day | duration |
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | 221 | (130) 555-0289 | (996) 555-8899 | 2024 | 7     | 28  | 51       |
-- | 224 | (499) 555-9472 | (892) 555-8872 | 2024 | 7     | 28  | 36       |
-- | 233 | (367) 555-5533 | (375) 555-8161 | 2024 | 7     | 28  | 45       |
-- | 251 | (499) 555-9472 | (717) 555-1342 | 2024 | 7     | 28  | 50       |
-- | 254 | (286) 555-6063 | (676) 555-6554 | 2024 | 7     | 28  | 43       |
-- | 279 | (826) 555-1652 | (066) 555-9701 | 2024 | 7     | 28  | 55       |

-- compared licence plates with the help of people table
-- +--------+
-- |  name  |
-- +--------+
-- | Sofia  |
-- | Luca   |
-- | Kelsey |
-- | Bruce  |
-- +--------+



-- with 1 compare (people and phonecalls) it could be sofia or Bruce

-- OKAY its bruce

-- he called this number (375) 555-8161
-- SELECT * FROM People WHERE phone_number = '(375) 555-8161'
-- ITS ROBIN
