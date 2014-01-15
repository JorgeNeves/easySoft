utilizador(jose,[lapr,isep]).
utilizador(rui,[lapr,isep]).
utilizador(manuel,[lapr,isep]).
utilizador(francisco,[lapr,isep]).
utilizador(pedro,[lapr,isep]).
utilizador(joao,[lapr,isep]).
utilizador(tomane,[lapr,lala]).
utilizador(asda,[lapr]).
amigos(jose, rui).
amigos(asda,rui).
amigos(ola,jose).

sublist( [], _ ).
sublist( [X|XS], [X|XSS] ) :- sublist( XS, XSS ).
sublist( [X|XS], [_|XSS] ) :- sublist( [X|XS], XSS ).

getUsers(Tags,L):-findall(X,procura(Tags,X),L1),elm(L1,L).
procura(TAGS,X):-amigos(X,_),utilizador(X,Lista),sublist(TAGS,Lista).
procura(TAGS,Y):-amigos(_,Y),utilizador(Y,Lista),sublist(TAGS,Lista).

elm([],[]).
elm([H|T],[H|T1]):-elm(T,T1),
	\+ member(H,T1),!.
elm([_|T],T1):-
	elm(T,T1).





