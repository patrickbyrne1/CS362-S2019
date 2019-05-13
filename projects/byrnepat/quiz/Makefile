CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme.o: testme.c
	gcc -c testme.c -g  $(CFLAGS)


#########

testme: testme.c testme.o
	gcc -o testme -g  testme.c $(CFLAGS)


runtests: testme
	echo "Result for running random test:" &> randomtestresult.out
	-./testme #>> randomtestresult.out
	gcov -b testme.c >> randomtestresult.out
	cat testme.c.gcov >> randomtestresult.out
	

clean:
	rm -f *.o testme.exe  *.gcov *.gcda *.gcno *.so *.out 
