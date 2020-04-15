CPPFLAGS=-g -Wall
CXX=g++

all: assignment4.exe

assignment4.exe: main.cpp
	$(CXX) $(CPPFLAGS) $^ -o $@
