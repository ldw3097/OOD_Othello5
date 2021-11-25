std = --std=c++17

all : main

node.o : node.cc node.h
	g++ $(std) node.cc -c -o $@

print.o : print.cc print.h
	g++ $(std) print.cc -c -o $@

main.o : main.cc
	g++ $(std) main.cc -c -o $@

main : main.o print.o node.o
	g++ $(std) $^ -o $@