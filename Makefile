std = --std=c++17

all : main

node.o : node.cc node.h
	g++ $(std) node.cc -c -o $@

node_print.o : node_print.cc node_print.h
	g++ $(std) node_print.cc -c -o $@

Board.o : Board.cc Board.h
	g++ $(std) Board.cc -c -o $@


print.o : print.cc print.h
	g++ $(std) print.cc -c -o $@

main.o : main.cc
	g++ $(std) main.cc -c -o $@

main : main.o print.o node.o node_print.o Board.o
	g++ $(std) $^ -o $@
