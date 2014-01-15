proxima_jogada(Tabuleiro,Jogada):-
	random(1,10,Jogada),
	posLivre(Tabuleiro,Jogada,1);proxima_jogada(Tabuleiro,Jogada).

posLivre([H|_],Jogada,Jogada):-
	var(H).
posLivre([_|T],Jogada,I):-
	I1 is I+1,
	posLivre(T,Jogada,I1).



