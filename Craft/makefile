CXXFLAGS = -Wall -std=c++11

CPP_SOURCE = src/main.cpp src/Recipe.cpp src/Item.cpp
CPP_HEADER = src/Recipe.h src/CraftEnvironment.h src/Item.h
OBJECTS    = $(CPP_SOURCE:.cpp=.o)

main: $(OBJECTS)
	g++ -o $@ $^

main.o: CPP_SOURCE CPP_HEADER
craftenvironment.o: CraftEnvironment.h
recipe.o: src/Recipe.cpp src/Recipe.h
item.o: src/Item.cpp src/Item.h