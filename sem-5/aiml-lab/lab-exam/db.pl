rotateRight(Arr, N, RotatedArr) :-
    length(Arr, N1), Index is N mod N1,
    length(Back, Index), 
    append(Front, Back, Arr),
    append(Back, Front, RotatedArr).