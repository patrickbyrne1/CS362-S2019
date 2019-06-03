CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)


#########

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unitTestResults: unittest1.c unittest2.c unittest3.c unittest3.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.h dominion.c rngs.o

	echo "Result for running unit 1 test:" > unittestresults.out
	echo "unittest1.c: " >> unittestresults.out
	gcc -o unittest1 dominion.c unittest1.c rngs.o $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	
	echo "Result for running unit 2 test:" >> unittestresults.out
	echo "unittest2.c: " >> unittestresults.out
	gcc -o unittest2 dominion.c unittest2.c rngs.o $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out


	echo "Result for running unit 3 test:" >> unittestresults.out
	echo "unittest3.c: " >> unittestresults.out
	gcc -o unittest3 dominion.c unittest3.c rngs.o $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out


	echo "Result for running unit 4 test:" >> unittestresults.out
	echo "unittest4.c: " >> unittestresults.out
	gcc -o unittest4 dominion.c unittest4.c rngs.o $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out


	echo "Result for running card 1 test:" >> unittestresults.out
	echo "cardtest1.c: " >> unittestresults.out
	gcc -o cardtest1 dominion.c cardtest1.c rngs.o $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out

	
	echo "Result for running card 2 test:" >> unittestresults.out
	echo "cardtest2.c: " >> unittestresults.out
	gcc -o cardtest2 dominion.c cardtest2.c rngs.o $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	
	
	echo "Result for running card 3 test:" >> unittestresults.out
	echo "cardtest3.c: " >> unittestresults.out
	gcc -o cardtest3 dominion.c cardtest3.c rngs.o $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	
	
	echo "Result for running card 4 test:" >> unittestresults.out
	echo "cardtest4.c: " >> unittestresults.out
	gcc -o cardtest4 dominion.c cardtest4.c rngs.o $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	
	



randomtestresults: randomtestadventurer.c randomtestcard1.c randomtestcard2.c dominion.h dominion.c rngs.o

	echo "Result for running random adventurer card test:" > randomtestresults.out
	echo "randomtestadventurer.c: " >> randomtestresults.out
	gcc -o randomtestadventurer dominion.c randomtestadventurer.c  rngs.o $(CFLAGS)
	./randomtestadventurer >> randomtestresults.out
	gcov -f -b dominion.c >> randomtestresults.out
	
	echo "Result for running random village card test:" >> randomtestresults.out
	echo "randomtestcard1.c: " >> randomtestresults.out
	gcc -o randomtestcard1 dominion.c randomtestcard1.c  rngs.o $(CFLAGS)
	./randomtestcard1 >> randomtestresults.out
	gcov -f -b dominion.c >> randomtestresults.out
	
	echo "Result for running random embargo card test:" >> randomtestresults.out
	echo "randomtestcard2.c: " >> randomtestresults.out
	gcc -o randomtestcard2 dominion.c randomtestcard2.c  rngs.o $(CFLAGS)
	./randomtestcard2 >> randomtestresults.out
	gcov -f -b dominion.c >> randomtestresults.out





player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player unitTestResults randomtestresults

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittest1 unittest2 unittest3 unittest4 \
	randomtestadventurer randomtestcard1 randomtestcard2 cardtest1 cardtest2 cardtest3 cardtest4
