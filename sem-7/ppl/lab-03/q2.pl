greater(X,Y, Z) :- Z is max(X,Y).
lesser(X, Y, Z) :- Z is min(X, Y).
max_salary(X, Y, Z, MAX) :- greater(X, Y, TEMP), greater(TEMP, Z, MAX).
min_salary(X, Y, Z, MIN) :- lesser(X, Y, TEMP), lesser(TEMP, Z, MIN).
