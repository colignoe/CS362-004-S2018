CFLAGS = -Wall -fpic -coverage -lm

testme: testme.c
	gcc -o testme testme.c -g $(CFLAGS)
	./testme

clean:
	rm -rf testme *.gcda *.gcno *.dSYM
