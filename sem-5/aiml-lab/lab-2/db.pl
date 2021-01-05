palindrome([H|T]):-reverse([H|T],[H|T]).

remove_dups([X],[X]).
remove_dups([X,Y|Z],N):- X = Y, remove_dups([Y|Z],N).
remove_dups([X,Y|Z],[X|N]):- X \= Y, remove_dups([Y|Z],N).

replicate(X1,N,X2) :- replicate(X1,N,X2,N).
replicate([],_,[],_).
replicate([_|Z],N,Y,0) :- replicate(Z,N,Y,N).
replicate([X|Z],N,[X|Y],K) :- K > 0, K1 is K - 1, replicate([X|Z],N,Y,K1).

drop(X1,N,X2) :- drop(X1,N,X2,N).
drop([],_,[],_).
drop([_|Z],N,Y,1) :- drop(Z,N,Y,N).
drop([X|Z],N,[X|Y],K) :- K > 1, K1 is K - 1, drop(Z,N,Y,K1).

split(X1,0,[],X1).
split([X|Z],N,[X|Y],Z1) :- N > 0, N1 is N - 1, split(Z,N1,Y,Z1).
rotate([],_,[]) :- !.
rotate(X1,N,X2) :- length(X1,NX1), N1 is N mod NX1, split(X1,N1,Y1,Y2), append(Y2,Y1,X2).

remove_at(X,[X|X1],1,X1).
	remove_at(X,[Y|X1],N,[Y|Y1]) :- N > 1, 
	   N1 is N - 1, remove_at(X,X1,N1,Y1).
	rand_select(_,0,[]).
	rand_select(X1,N,[X|Z1]) :- N > 0,
	    length(X1,M),
	    I is random(M) + 1,
	    remove_at(X,X1,I,Y1),
	    N1 is N - 1,
	    rand_select(Y1,N1,Z1).

rand_perm(X,Y) :- length(X,N), rand_select(X,N,Y).
