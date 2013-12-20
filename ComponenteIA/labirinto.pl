liga((1,1),(1,2)).
liga((1,2),(1,3)).
liga((1,3),(1,4)).
liga((1,4),(2,4)).
liga((2,4),(3,4)).
liga((3,4),(3,3)).
liga((3,4),(3,5)).
liga((3,6),(3,5)).

encontra_caminho((Xi,Yi),(Xf,Yf),L):-
	encontra_caminho((Xi,Yi), (Xf,Yf), [(Xi,Yi)],L).

encontra_caminho((Xf,Yf),(Xf,Yf),LA,L):-reverse(LA,L).

encontra_caminho((Xi,Yi),(Xf,Yf),LA,L):-(liga((Xi,Yi),(X,Y));liga((X,Y),(Xi,Yi))),
	not(member((X,Y),LA)),
	encontra_caminho((X,Y),(Xf,Yf),[(X,Y)|LA],L).

cam_curto((Xi,Yi),(Xf,Yf),P):-findall((Tam, L),
		(encontra_caminho((Xi,Yi), (Xf,Yf), L), length(L,Tam)),
		LR),
	sort( LR, LROrd),
	LROrd = [(_,P)|_].






