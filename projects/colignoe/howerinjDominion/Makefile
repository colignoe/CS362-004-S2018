CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

unittest1: dominion.o unittest1.c
	gcc -o unittest1 unittest1.c dominion.o rngs.o $(CFLAGS)

unittest2: dominion.o unittest2.c
	gcc -o unittest2 unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3: dominion.o unittest3.c
	gcc -o unittest3 unittest3.c dominion.o rngs.o $(CFLAGS)

unittest4: dominion.o unittest4.c
	gcc -o unittest4 unittest4.c dominion.o rngs.o $(CFLAGS)

cardtest1: dominion.o cardtest1.c
	gcc -o cardtest1 cardtest1.c dominion.o rngs.o $(CFLAGS)

cardtest2: dominion.o cardtest2.c
	gcc -o cardtest2 cardtest2.c dominion.o rngs.o $(CFLAGS)

cardtest3: dominion.o cardtest3.c
	gcc -o cardtest3 cardtest3.c dominion.o rngs.o $(CFLAGS)

cardtest4: dominion.o cardtest4.c
	gcc -o cardtest4 cardtest4.c dominion.o rngs.o $(CFLAGS)
	
randomtestcard1: dominion.o randomtestcard1.c
	gcc -o randomtestcard1 randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	
randomtestcard2: dominion.o randomtestcard2.c
	gcc -o randomtestcard2 randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	
randomtestadventurer: dominion.o randomtestadventurer.c
	gcc -o randomtestadventurer randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	
randomtestresults.out: randomtestcard1 randomtestcard2 randomtestadventurer
	echo "### Random Test Results ### " &> randomtestresults.out
	echo "randomtestcard1.c:" >> randomtestresults.out
	randomtestcard1 >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out
	echo "randomtestcard2.c:" >> randomtestresults.out
	randomtestcard2 >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out
	echo "randomtestadventurer.c:" >> randomtestresults.out
	randomtestadventurer >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out
	gcov -b dominion.c >> randomtestresults.out
	gcov -f dominion.c >> randomtestresults.out
	gcov -f -b dominion.c >> randomtestresults.out
	cat dominion.c.gcov >> randomtestresults.out

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	echo "### Unit Test Results ### " &> unittestresults.out
	echo "unittest1.c:" >> unittestresults.out
	unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo "unittest2.c:" >> unittestresults.out
	unittest2 >> unittestresults.out 
	gcov dominion.c >> unittestresults.out
	echo "unittest3.c:" >> unittestresults.out
	unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo "unittest4.c:" >> unittestresults.out
	unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo "### Card Test Results ### " >> unittestresults.out
	echo "cardtest1.c:" >> unittestresults.out
	cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo "cardtest2.c:" >> unittestresults.out
	cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo "cardtest3.c:" >> unittestresults.out
	cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo "cardtest4.c:" >> unittestresults.out
	cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	gcov -f dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard1 randomtestcard2 randomtestadventurer *.gcov *.gcda *.gcno *.so *.out badTestDrawCard testDrawCard testDrawCard.exe


