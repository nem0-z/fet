all:
	bison -d -t hm.y
	flex hm.l
	g++ -o hm hm.tab.c lex.yy.c
	./hm
