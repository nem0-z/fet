all: calc

calc.tab.c calc.tab.h:	calc.y
	bison -d calc.y

lex.yy.c: calc.l calc.tab.h
	flex calc.l

calc: lex.yy.c calc.tab.c calc.tab.h
	g++ -o calculator calc.tab.c lex.yy.c

clean:
	rm calculator calc.tab.c lex.yy.c calc.tab.h

test1: all
	./test/testme.sh ./calculator test/test1

test2: all
	./test/testme.sh ./calculator test/test2

test3: all
	./test/testme.sh ./calculator test/test3

test4: all
	./test/testme.sh ./calculator test/test4

test5: all
	./test/testme.sh ./calculator test/test5

test6: all
	./test/testme.sh ./calculator test/test6

test7: all
	./test/testme.sh ./calculator test/test7

test8: all
	./test/testme.sh ./calculator test/test8

test9: all
	./test/testme.sh ./calculator test/test9

test10: all
	./test/testme.sh ./calculator test/test10

test11: all
	./test/testme.sh ./calculator test/test11

test12: all
	./test/testme.sh ./calculator test/test12

test13: all
	./test/testme.sh ./calculator test/test13

grade: all
	(cd test; exec ./grade.sh ../calculator)

