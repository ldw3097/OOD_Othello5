std = --std=c++17

all : main

print.o : print.cc print.h
	g++ $(std) print.cc -c -o $@

main.o : main.cc
	g++ $(std) main.cc -c -o $@

main : main.o print.o
	g++ $(std) $^ -o $@