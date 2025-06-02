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



# 🔹 This sets a variable CXX to the compiler name g++.
# 🔸 You can later use $(CXX) instead of hardcoding g++.

# # CXXFLAGS = -Wall -g
# 🔹 Sets compiler flags:

# -Wall: show all warnings

# -g: include debugging info (so you can debug with gdb)

# all: my_app
# 🔹 This is the default target.
# 🔸 When you type make, it runs the first rule, which tells make to build my_app.

# main.o: main.cpp helper.h
# 	$(CXX) $(CXXFLAGS) -c main.cpp
# 🔹 Builds main.o from main.cpp (and also depends on helper.h because it’s included in the code)

# -c: compile only, don’t link

# This creates an object file main.o

# helper.o: helper.cpp helper.h
# 	$(CXX) $(CXXFLAGS) -c helper.cpp
# 🔹 Compiles helper.cpp into helper.o, again using the header file helper.h.
