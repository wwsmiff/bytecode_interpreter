CC = clang++
CFLAGS = -g -c -O0 -std=c++17 -pedantic

main: main.o Parser.o CPU.o
	${CC} main.o Parser.o CPU.o -o main

Parser.o: Parser.hpp Parser.cpp Definitions.hpp
	${CC} ${CFLAGS} Parser.cpp

CPU.o: CPU.hpp CPU.cpp Definitions.hpp
	${CC} ${CFLAGS} CPU.cpp

main.o: main.cpp
	${CC} ${CFLAGS} main.cpp

.PHONY: clean
clean:
	rm -f *.o core.* main

.PHONY: run
run:
	./main
