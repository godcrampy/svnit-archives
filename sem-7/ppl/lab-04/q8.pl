delete_elm(Element,[Element|Tail],Tail).

delete_elm(Element,[Head|Tail],[Head|Tail1]) :-
  delete_elm(Element,Tail,Tail1).
