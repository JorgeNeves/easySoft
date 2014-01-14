:-dynamic(liga/2).

encontra_caminho((Xi,Yi),(Xf,Yf),L):-
	encontra_caminho((Xi,Yi), (Xf,Yf), [(Xi,Yi)],L).

encontra_caminho((Xf,Yf),(Xf,Yf),LA,L):-reverse(LA,L).

encontra_caminho((Xi,Yi),(Xf,Yf),LA,L):-(liga((Xi,Yi),(X,Y))),
	not(member((X,Y),LA)),
	encontra_caminho((X,Y),(Xf,Yf),[(X,Y)|LA],L).

cam_curto((Xi,Yi),(Xf,Yf),P):-findall((Tam, L),
		(encontra_caminho((Xi,Yi), (Xf,Yf), L), length(L,Tam)),
		LR),
	sort( LR, LROrd),
	LROrd = [(_,P)|_].






