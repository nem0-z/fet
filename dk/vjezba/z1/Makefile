all:
	bison -d z1.y
	flex z1.l
	clang++ -o z1 z1.tab.c lex.yy.c
	./z1 < input
