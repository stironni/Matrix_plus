CC=gcc -lstdc++
CFLAGS=-Wall -Wextra -Werror -std=c++17
LINUX=-lsubunit -lrt -lpthread -lm
LCOV=-lgtest
test=-lgtest -lgmock -pthread
OS=$(shell uname -s)

FILES=my_matrix_oop.cc

OBJ_LIB=my_matrix_oop.o

all: clean my_matrix_oop.a gcov_report

my_matrix_oop.a: my_matrix_oop.o
	ar rc libmy_matrix_oop.a my_matrix_oop.o
	ranlib libmy_matrix_oop.a

my_matrix_oop.o: my_matrix_oop.cc
	$(CC) my_matrix_oop.cc -c

test: my_matrix_oop.a
ifeq ($(OS), Darwin)
	$(CC)  -c test.cc
	$(CC) test.o -L. -lmy_matrix_oop $(test) $(LCOV) -o test
	./test
else
	$(CC) $(CFLAGS) test.cc -L. -lmy_matrix_oop -o test $(LINUX) $(LCOV)
	./test
endif
	rm -rf *.o

gcov_report:
	$(CC) $(CFLAGS) --coverage test.cc my_*.cc -o test $(LCOV)
	chmod +x *
	./test
	~/goinfre/homebrew/bin/lcov -t "test" -o test.info --no-external --ignore-errors mismatch,mismatch   -c -d .
	~/goinfre/homebrew/bin/genhtml -o report test.info
	make open

open:
	open report/index.html

check: clang leak

clang:
	cp ../materials/linters/.clang-format ./.clang-format
	clang-format -i *.cc
	clang-format -n *.cc
	rm -rf .clang-format

leak: test
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./test
else
	valgrind ./test --leak-check=full
endif
	rm -rf *.o


clean:
	rm -rf *.gc* *.o *.a *.out *.info test
	rm -rf report
