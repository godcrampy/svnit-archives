female(mary).
female(sandra).
female(juliet).
female(lisa).
male(peter).
male(paul).
male(dick).
male(bob).
male(harry).
male(dan).

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
parent(dan, dick).
parent(dan, sandra).

husband(bob, juliet).
husband(peter, lisa).
husband(dan, mary).

child(X, Y) :- parent(Y, X).

mother(X, Y) :- parent(X, Y), female(X).

father(X, Y) :- parent(X, Y), male(X).

wife(X, Y) :- husband(Y, X).

son(X, Y) :- parent(Y, X), male(X).
daughter(X, Y) :- parent(Y, X), female(X).

sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.

brother(X, Y) :- sibling(X, Y), male(X).
sister(X, Y) :- sibling(X, Y), female(X).

uncle(X, Y) :- parent(Z, Y), sibling(X, Z), male(X).
aunt(X, Y) :- parent(Z, Y), sibling(X, Z), female(X).

nephew(X, Y) :- sibling(Y, Z), parent(Z, X), male(X).
niece(X, Y) :- sibling(Y, Z), parent(Z, X), female(X).
