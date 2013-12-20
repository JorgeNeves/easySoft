%% Recebe uma string no formato compara("FORCA","A",L) e devolve o
%% codigo ASCII da palavra encontrada ou seja L=[65].
%% Outro exemplo: compara ("JOAO","O",L) retorna L=[79,79].

palavra(1,"OLX").
palavra(2,"INFORMATICA").
palavra(3,"ANGELO").
palavra(4,"PDF").
palavra(5,"FACEBOOK").
palavra(6,"GOOGLE").
palavra(7,"ALGAV").

gera_palavra(P):-
			random(1,8,Pos),
			palavra(Pos,P).

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


