CC=gcc
YACC=bison
LEX=flex

all: problem3

debug: DBGBISONFLAGS= -t -Wcounterexamples
debug: CFLAGS+= -DDBGBISON
debug: problem3


problem3: calc.o
	ln -nfs $< $@

%.o: %.lex.c %.tab.c %.tab.h
	$(CC) $(CFLAGS) -o $@ $^ -lfl

%.lex.c: %.l
	$(LEX) -o $(patsubst %.l,%.lex.c,$<) $<

%.tab.c %.tab.h: %.y
	$(YACC) -d $(DBGBISONFLAGS) $<

.PHONY: clean

clean:
	rm -f *.lex.c *.tab.c *.tab.h *.o problem3
