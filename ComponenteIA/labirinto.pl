
encontra_caminho(O,D,L):-encontra_caminho(O,D,[O],L).

encontra_caminho(D,D,LA,L):-reverse(LA,L).

encontra_caminho(O,D,LA,L):-liga(O,X),
	not(member(X,LA)),
	encontra_caminho(X,D,[X|LA],L).

cam_curto(O,D,P):-findall((Tam, L),
		(encontra_caminho(O, D, L), length(L,Tam)),
		LR),
	sort( LR, LROrd),
	LROrd = [(_,P)|_].






