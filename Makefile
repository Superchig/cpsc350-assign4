CPPFLAGS=-g -Wall
CXX=g++

all: assignment4.exe

debug: CPPFLAGS+=-DDEBUG
debug: assignment4.exe

assignment4.exe: main.cpp Student.cpp Window.cpp
	$(CXX) $(CPPFLAGS) $^ -o $@

clean:
	[ -f assignment4.exe ] && rm assignment4.exe
