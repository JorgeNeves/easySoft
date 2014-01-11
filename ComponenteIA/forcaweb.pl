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

palavra(1,"OLX").
palavra(2,"INFORMATICA").
palavra(3,"ANGELO").
palavra(4,"PDF").
palavra(5,"FACEBOOK").
palavra(6,"GOOGLE").
palavra(7,"ALGAV").

gera_palavra(_Request):-
			random(1,8,Pos),
			palavra(Pos,P),
			format('Content-type: text/plain~n~n'),
			format(P).

%% Identico ao anterior mas retorna a posição em que as palavras se
%% encontram.
%% Exemplo:comparacont("JOAO","O",L) retorna L=[2,4].
comparacont(Request):-
	format('Content-type: xml/text~n~n'),
	http_parameters(Request,[palavra(Palavra,[]),tentativa(Tentativa,[])]),
	string_to_list(Palavra,P1),
	char_code(Tentativa,T),
%%	write(P1),nl,
%%	format(Tentativa),
	compara2(P1,T,1,L),nl,
	write(L).

compara2([],_,_,[]).
compara2([H|T],H,I,[I|L]):-!,I1 is I+1,compara2(T,H,I1,L).
compara2([_|T],H,I,L):-!,I1 is I+1,compara2(T,H,I1,L).

