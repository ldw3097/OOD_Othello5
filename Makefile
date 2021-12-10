std = --std=c++17

all : main

node.o : node.cc node.h
	g++ $(std) node.cc -c -o $@ -g

node_print.o : node_print.cc node_print.h
	g++ $(std) node_print.cc -c -o $@ -g

board.o : board.cc board.h
	g++ $(std) board.cc -c -o $@ -g

main.o : main.cc
	g++ $(std) main.cc -c -o $@ -g

main : main.o node.o node_print.o board.o
	g++ $(std) $^ -o $@ -g

clean :
	rm -f *.o main

#gtest
GTEST_DIR = googletest/googletest

CPPFLAGS += -isystem $(GTEST_DIR)/include

CXXFLAGS += -pthread

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	g++ $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	g++ $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

othellotest.o : othellotest.cc $(GTEST_HEADERS)
	g++ $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c othellotest.cc -o $@

test :othellotest.o gtest_main.a node.o board.o
	g++ $(CPPFLAGS) $(CXXFLAGS) --std=c++17 $^ -o $@ 