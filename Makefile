CPPFLAGS=-g -Wall
CXX=g++

all: assignment4.exe

assignment4.exe: main.cpp
	$(CXX) $(CPPFLAGS) $^ -o $@

test_list: test_list.cpp
	$(CXX) $(CPPFLAGS) $^ -o $@

clean:
	[ -f assignment4.exe ] && rm assignment4.exe
	[ -f test_list ] && rm test_list