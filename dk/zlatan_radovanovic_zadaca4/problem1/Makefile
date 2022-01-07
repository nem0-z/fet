CC=gcc
YACC=bison
LEX=flex

all: problem1

debug: DBGBISONFLAGS= -t -Wcounterexamples
debug: CFLAGS+= -DDBGBISON
debug: problem1


problem1: request.o
	ln -nfs $< $@

%.o: %.lex.c %.tab.c %.tab.h
	$(CC) $(CFLAGS) -o $@ $^ -lfl

%.lex.c: %.l
	$(LEX) -o $(patsubst %.l,%.lex.c,$<) $<

%.tab.c %.tab.h: %.y
	$(YACC) -d $(DBGBISONFLAGS) $<

.PHONY: clean

clean:
	rm -f *.lex.c *.tab.c *.tab.h *.o problem1
