% Program: family.pl
% Source: Prolog
%
% Purpose: This is the sample program for the Prolog Lab in AIML
% It is a simple Prolog program to demonstrate how prolog works.
%
% History: Original code by Barry Drake
% parent(Parent, Child)
%
parent(albert, jim).
parent(albert, peter).
parent(jim, brian).
parent(john, darren).
parent(peter, lee).
parent(peter, sandra).
parent(peter, james).
parent(peter, kate).
parent(peter, kyle).
parent(brian, jenny).
parent(irene, jim).
parent(irene, peter).
parent(pat, brian).
parent(pat, darren).
parent(amanda, jenny).
% female(Person)
%
female(irene).
female(pat).
female(lee).
female(sandra).
female(jenny).
female(amanda).
female(kate).
% male(Person)
%
male(albert).
male(jim).
male(peter).
male(brian).
male(john).
male(darren).
male(james).
male(kyle).
% yearOfBirth(Person, Year).
%
yearOfBirth(irene, 1923).
yearOfBirth(pat, 1954).
yearOfBirth(lee, 1970).
yearOfBirth(sandra, 1973).
yearOfBirth(jenny, 2004).
yearOfBirth(amanda, 1979).
yearOfBirth(albert, 1926).
yearOfBirth(jim, 1949).
yearOfBirth(peter, 1945).
yearOfBirth(brian, 1974).
yearOfBirth(john, 1955).
yearOfBirth(darren, 1976).
yearOfBirth(james, 1969).
yearOfBirth(kate, 1975).
yearOfBirth(kyle, 1976).
%
% grandparent(Gparent, Child).
grandparent(G, C):-
	parent(G, X),
	parent(X, C).
%
older(Person1, Person2):-
	yearOfBirth(Person1, Year1),
	yearOfBirth(Person2, Year2),
	Year2 > Year1.
%
sibling(X, Y) :-
	parent(Z, X),
	parent(Z, Y),
	X \= Y.
%
% olderbrother(Brother, Sister)
olderbrother(X, Y):-
	male(X),
	parent(Z,X),
	parent(Z,Y),
	X \= Y,
	older(X, Y).
%
predecessor(X,Y):-
	parent(X,Z),
	predecessor(Z,Y).
predecessor(X,Y):-
	parent(X,Y).
%
sister(X,Y):-
	female(X),
	parent(Z,X),
	parent(Z,Y),
	X\=Y.
%
person(X):-
	female(X).
person(Y):-
	male(Y).