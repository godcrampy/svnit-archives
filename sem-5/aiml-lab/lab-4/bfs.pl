bfs(Ylist) :-
solve(Ylist,[1,2,3,4,5,6,7,8],
 [1,2,3,4,5,6,7,8],
 [-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7],
 [2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]).
solve([],[],[],Du,Dv).
solve([Y|Ylist],[X|Dx1],Dy,Du,Dv) :-
delete(Y,Dy,Dy1),
U is X-Y,
delete(U,Du,Du1),
V is X+Y,
delete(V,Dv,Dv1),
solve(Ylist,Dx1, Dy1,Du1,Dv1).
delete(Item,[Item|List],List).
delete(Item,[First|List],[First|List1]) :-
delete(Item,List,List1).
