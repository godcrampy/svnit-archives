student(u223, ram, address(shlimar_park, surat, 395001), [sub(t1,algebra),sub(t2,physics), sub(t3,english), sub(t5,hindi)]).
student(u226, lakshman, address(honey_park, delhi, 110002), [sub(t3,history), sub(t4,science), sub(t1,geometry), sub(t5, hindi)]).
student(u227, bharat, address(shally_tower, mumbai,400004 ),[sub(t1,geometry), sub(t2, chemistry), sub(t3,english_grammer)]).

list_length([], 0 ).
list_length([_|Xs], L) :- list_length(Xs, N) , L is N + 1.

q1:-
  student(_, N, _, S),
  write('Total subjects of '), write(N), write(': '),
  list_length(S, Length), write(Length), nl, fail.

q2:-
  student(_, X, address(_, _, Z), _), nl,
  write('Name: '), write(X), nl,
  write('Zipcode: '), write(Z), nl, fail.

q3:-
  Goal = (student(Roll, Name, address(_, C, _), _), C = delhi),
  findall(Roll/Name, Goal, L),
  maplist(write, L).

get_subjects(Z):-
  student(_,_,_, Subjects),
  member(Subject, Subjects),
  Subject = sub(t1, Z).


q4:-
  findall(Z, get_subjects(Z), L),
  sort(L, Y),
  write(Y).

q5:-
  student(R, _, _, Subjects),
  member(Subject, Subjects),
  Subject = sub(_, hindi),
  write(R),
  nl,
  fail.

q6:-
  student(_,_,address(B, C, _), _),
  write(B),write(', '), write(C),nl, fail.

q7 :- q7(u223).
q7(R):-
write('Teachers for: '), write(R), nl,
  student(R, _, _, Subjects),
  member(Subject, Subjects),
  Subject = sub(T, _),
  write(T),nl,
  fail.
  

get_all_subjects(Z):-
  student(_,_,_, Subjects),
  member(Subject, Subjects),
  Subject = sub(_, Z).

q8:-
  findall(Z, get_all_subjects(Z), L),
  aggregate(max(C,E),aggregate(count,member(E,L),C),max(Count, Name)),
  write(Name), write(': '), write(Count).


get_teachers(Teacher):-
  student(_,_,_,Subjects),
  member(Subject, Subjects),
  Subject = sub(Teacher, _).

get_subjects(Teacher, Sub):-
  student(_, _, _, Subjects),
  member(Subject, Subjects),
  Subject = sub(Teacher, Sub).

q9:-
  findall(Teacher, get_teachers(Teacher), Teachers),
  sort(Teachers, Unique_Teachers),
  member(T, Unique_Teachers),
  write(T),write(': '),
  findall(S, get_subjects(T, S), Subs),
  sort(Subs, Unique_Subs),
  write(Unique_Subs),nl,fail.