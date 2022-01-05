CXX = g++
EXEC = solarsystem
SOURCES = main.cpp stars.cpp solarsystem.cpp
OBJECTS = main.o stars.o solarsystem.o 
LDFLAGS = -lglut -lGL -lGLU 

.PHONY: all
all:
	$(CXX) $(SOURCES) $(LDFLAGS) -o $(EXEC)

.PHONY: clean
clean:
	rm -rf $(EXEC) *.gdb *.o *.out