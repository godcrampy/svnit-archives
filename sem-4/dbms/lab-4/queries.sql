--1 
select t1.name, t2.name, track.distance
from track, station as t1, station as t2
where (track.stcode1 = t1.stcode and track.stcode2 = t2.stcode);

--2
select t1.name, t2.name, track.distance
from track, station as t1, station as t2
where (track.stcode1 = t1.stcode and track.stcode2 = t2.stcode and track.distance < 20);

--3 
select distinct(id) from trainhalts where timeout is not null and stcode in (
select stcode from station where name="GHATKOPAR");

--4 
select name from train where id in (
select distinct(id) from trainhalts where timein is not null and stcode in (
select stcode from station where name="MUMBAI"))
order by name;

--5
select name from station where stcode in 
(select stcode from trainhalts where timein is not null and id in (
select id from train where name="CST-AMR_LOCAL")
order by timein);

--6
select name from station where stcode in 
(select stcode from trainhalts where id in 
(select id from train where name = "CST-AMR_LOCAL")
order by seqno);

--7 
select s1.name, s2.name from track, station as s1, station as s2
where (s1.stcode = track.stcode1 and s2.stcode = track.stcode2)
order by distance desc limit 1

--8
select stcode from trainhalts
where timeout is not null
order by seqno desc
limit 1, 1;
