std = --std=c++17

all : main

node.o : node.cc node.h
	g++ $(std) node.cc -c -o $@ -g

node_print.o : node_print.cc node_print.h
	g++ $(std) node_print.cc -c -o $@ -g

Board.o : Board.cc Board.h
	g++ $(std) Board.cc -c -o $@ -g


print.o : print.cc print.h
	g++ $(std) print.cc -c -o $@ -g

main.o : main.cc
	g++ $(std) main.cc -c -o $@ -g

main : main.o print.o node.o node_print.o Board.o
	g++ $(std) $^ -o $@ -g
