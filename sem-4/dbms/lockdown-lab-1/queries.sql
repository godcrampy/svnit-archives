-- Question 1
select t1.name, t2.name, track.distance
from track, station as t1, station as t2
where track.stcode1 = t1.stcode and track.stcode2 = t2.stcode;

-- Question 2
select stcode1, stcode2
from track
where distance < 20;

-- Question 3
select distinct id 
from station natural join trainhalts 
where name = 'GHATKOPAR';

-- Question 4
select train.name
from train natural join trainhalts join station
where station.stcode = trainhalts.stcode and station.name = 'MUMBAI' and seqno = 0;

-- Question 5
select station.name
from train natural join trainhalts join station
where station.stcode = trainhalts.stcode and train.name = 'CST-AMR_LOCAL' order by seqno;

-- Question 6
select train.name
from train natural join trainhalts join station
where station.stcode = trainhalts.stcode and station.name = 'THANE' and seqno < 6;

-- Question 7
select s1.name, s2.name
from track, station as s1, station as s2
where s1.stcode = stcode1 and s2.stcode = stcode2 order by distance desc limit 1;

-- Question 8
select id
from trainhalts
order by timeout desc limit 1, 1;
