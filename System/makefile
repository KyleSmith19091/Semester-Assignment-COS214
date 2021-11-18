# Ignore main file when compiling gtest to prevent a double main error
SRC_FILES = $(filter-out ./src/Main.cpp, $(wildcard ./src/*.cpp))

run:
	g++ -std=c++11 ./src/*.cpp -I ./include -o ./build/main
	./build/main

clean:
	rm -f ./build/main
	rm -f ./build/test

gtest:
	g++ -std=c++11 ./test/Test.cpp $(SRC_FILES) -I ./include -o ./build/test -lgtest -lgtest_main
	./build/test
