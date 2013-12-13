tabuleiro(L,Jogada):-
	joga_pc(L,Jogada).
joga_pc([A,x,x,D,E,F,G,H,I],1):- var(A).
joga_pc([A,B,C,x,E,F,x,H,I],1):- var(A).
joga_pc([A,B,C,D,x,F,G,H,x],1):- var(A).

joga_pc([x,B,x,D,E,F,G,H,I],2):- var(B).
joga_pc([A,B,C,D,x,F,G,x,I],2):- var(B).

joga_pc([x,x,C,D,E,F,G,H,I],3):- var(C).
joga_pc([_,B,C,D,x,F,x,H,I],3):- var(C).
joga_pc([_,B,C,D,E,x,G,H,x],3):- var(C).

joga_pc([x,B,C,D,E,F,x,H,I],4):- var(D).
joga_pc([A,B,C,D,x,x,G,H,I],4):- var(D).

joga_pc([x,B,C,D,E,F,G,H,x],5):- var(E).
joga_pc([A,B,x,D,E,F,x,H,I],5):- var(E).
joga_pc([A,x,C,D,E,F,G,x,I],5):- var(E).
joga_pc([A,B,C,x,E,x,G,H,I],5):- var(E).

joga_pc([A,B,x,D,E,F,G,H,x],6):- var(F).
joga_pc([A,B,C,x,x,F,G,H,I],6):- var(F).

joga_pc([A,B,C,D,E,F,G,x,x],7):- var(G).
joga_pc([x,B,C,x,E,F,G,H,I],7):- var(G).
joga_pc([A,B,x,D,x,F,G,H,I],7):- var(G).

joga_pc([A,B,C,D,E,F,x,H,x],8):- var(H).
joga_pc([A,x,C,D,x,F,G,H,I],8):- var(H).

joga_pc([A,B,C,D,E,F,x,x,I],9):- var(I).
joga_pc([x,B,C,D,x,F,G,H,I],9):- var(I).
joga_pc([A,B,x,D,E,x,G,H,I],9):- var(I).

joga_pc(L,J):-
	descobre_jogada(L,1,J).
descobre_jogada([],_,404).
descobre_jogada([H|T],I,I):-
	var(H).
descobre_jogada([H|T],I,J):-
	I1 is I+1,descobre_jogada(T,I1,J).










