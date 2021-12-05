female(mary).
female(sandra).
female(juliet).
female(lisa).
male(peter).
male(paul).
male(dick).
male(bob).
male(harry).
parent(bob, lisa).
parent(bob, paul).
parent(bob, mary).
parent(juliet, lisa).
parent(juliet, paul).
parent(juliet, mary).
parent(peter, harry).
parent(lisa, harry).
parent(mary, dick).
parent(mary, sandra).

% father relation
father(X,Y) :- parent(X,Y), male(X).

% sister relation
sister(X,Y) :- parent(Z,X), parent(Z,Y), female(X), X \= Y.

% grandmother relation
grandmother(X, Y) :- parent(X, Z), parent(Z, Y), female(X).

% grandparent relation
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).

% cousin relation
cousin(X,Y) :- parent(X, Z), parent(Y, S), Z \= S, parent(Z, A), parent(S, A), X \= Y.
