

compara(Palavra,Tentativa,L):-compara1(Palavra,Tentativa,L).
compara1([],_,[]).
compara1([H|T],[H],[H|L]):-!,compara1(T,[H],L).
compara1([_|T],H,L):-!,compara1(T,H,L).

%% Identico ao anterior mas retorna a posição em que as palavras se
%% encontram.
%% Exemplo:comparacont("JOAO","O",L) retorna L=[2,4].
comparacont(Palavra,Tentativa,L):-compara2(Palavra,Tentativa,1,L).
compara2([],_,_,[]).
compara2([H|T],[H],I,[I|L]):-!,I1 is I+1,compara2(T,[H],I1,L).
compara2([_|T],H,I,L):-!,I1 is I+1,compara2(T,H,I1,L).


