default: $(TARGET)

q1:
	lex -o q-01/lex.yy.c q-01/main.l
	gcc q-01/main.c q-01/lex.yy.c

q2:
	lex -o q-02/lex.yy.c q-02/main.l
	gcc q-02/main.c q-02/lex.yy.c

q3:
	lex -o q-03/lex.yy.c q-03/main.l
	gcc q-03/main.c q-03/lex.yy.c

q4:
	lex -o q-04/lex.yy.c q-04/main.l
	gcc q-04/main.c q-04/lex.yy.c -lm


.PHONY: clean
clean:
	find . -name "*.out" -delete
	find . -name "*.yy.c" -delete
	find . -name "clean.c" -delete
	
