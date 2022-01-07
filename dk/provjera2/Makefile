lexer: scanner.l
	flex scanner.l
	clang++ lex.yy.c -o lexer

run: lexer
	./lexer < input.txt

clean:
	rm -f lexer lex.yy.c
