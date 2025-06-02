CXX =g++

CXXFLAGS = -Wall -g

all: my_app

my_app: main.o helper.o
	$(CXX) $(CXXFLAGS) -o my_app main.o helper.o

main.o: main.cpp helper.h
	$(CXX) $(CXXFLAGS) -c main.cpp

helper.o: helper.cpp helper.h
	$(CXX) $(CXXFLAGS) -c helper.cpp

clean:
	rm -f *.o my_app


