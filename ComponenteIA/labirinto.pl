liga((1,1),(1,2)).
liga((1,2),(1,3)).
liga((1,3),(1,4)).
liga((1,4),(2,4)).
liga((2,4),(3,4)).
liga((3,4),(3,3)).
liga((3,4),(3,5)).
liga((3,6),(3,5)).

encontra_caminho(O,D,L):-
	encontra_caminho(O, D, [O],LA), !, reverse(LA,L).

encontra_caminho(D,D,LA,LA).

encontra_caminho(O,D,LA,L):-liga(O,S),
	not(member(S,LA)),
	encontra_caminho(S,D,[S|LA],L).
/*
cam_curto(O,D,P):-findall((Tam, L),
		(encontra_caminho(O, D, L), length(L,Tam)),
		LR),
	sort( LR, LROrd),
	LROrd = [(_,P)|_].
*/






