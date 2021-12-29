CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
TESTS = -DTEST_NEWSHUFFLE -DTEST_SHUFFLE -DTEST_INTERLEAVE -DTEST_DIVIDE
GCC = gcc $(CFLAGS) $(TESTS)
EXEC = hw12
OBJS = hw12.o calc.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

all: $(OBJS)
	$(GCC) $(OBJS) -o hw12

hw12.o: hw12.c calc.c calc.h
	$(GCC) -c hw12.c

calc.o: hw12.c calc.c calc.h
	$(GCC) -c calc.c

test: all 
	./hw12 inputs/test1
	./hw12 inputs/test2
	./hw12 inputs/test3
	./hw12 inputs/test4
	./hw12 inputs/test5

memory: all test
	$(VALG) --log-file=log1.txt ./hw12 inputs/test1
	$(VALG) --log-file=log2.txt ./hw12 inputs/test2
	$(VALG) --log-file=log3.txt ./hw12 inputs/test3
	$(VALG) --log-file=log4.txt ./hw12 inputs/test4
	$(VALG) --log-file=log5.txt ./hw12 inputs/test5
clean:
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f hw12
