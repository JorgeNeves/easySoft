init:-
	use_module(library(http/thread_httpd)),
	use_module(library(http/http_dispatch)),
	use_module(library(http/http_parameters)).

server(Port):-
	http_server(http_dispatch,[port(Port)]).

init_palavra:-
	http_handler('/palavra',gera_palavra,[]).

init_compara:-
	http_handler('/compara',comparacont,[]).

%% Recebe uma string no formato compara("FORCA","A",L) e devolve o
%% codigo ASCII da palavra encontrada ou seja L=[65].
%% Outro exemplo: compara ("JOAO","O",L) retorna L=[79,79].

palavra(1,"INFORMATICA","HARDWARE").
palavra(2,"INFORMATICA","SOFTWARE").
palavra(3,"INFORMATICA","UNITY").
palavra(4,"GEOGRAFIA","PORTUGAL").
palavra(5,"GEOGRAFIA","ESPANHA").
palavra(6,"GEOGRAFIA","FRANÇA").
palavra(7,"DESPORTO","FUTEBOL").
palavra(8,"DESPORTO","ANDEBOL").
palavra(9,"DESPORTO","CICLISMO").
palavra(10,"DESPORTO","ATLETISMO").

gera_palavra(_Request):-
			random(1,10,Pos),
			palavra(Pos,C,P),
			format('Content-type: text/plain~n~n'),
			format(C),format(";"),
			format(P).

%% Identico ao anterior mas retorna a posição em que as palavras se
%% encontram.
%% Exemplo:comparacont("JOAO","O",L) retorna L=[2,4].
comparacont(Request):-
	format('Content-type: text/plain~n~n'),
	http_parameters(Request,[palavra(Palavra,[]),tentativa(Tentativa,[])]),
	string_to_list(Palavra,P1),
	char_code(Tentativa,T),
	compara2(P1,T,1,L),nl,
	format(L).

compara2([],_,_,[]).
compara2([H|T],H,I,[I|L]):-!,I1 is I+1,compara2(T,H,I1,L).
compara2([_|T],H,I,L):-!,I1 is I+1,compara2(T,H,I1,L).

