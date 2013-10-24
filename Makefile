CC=g++
FLAGS=-Wall
TARGET=benchmark

all: main.o benchmark.o stopwatch.o
	$(CC) $(FLAGS) -o $(TARGET) main.o benchmark.o stopwatch.o

stopwatch.o: stopwatch.cpp stopwatch.hpp
	$(CC) $(FLAGS) -c  stopwatch.cpp

benchmark.o: benchmark.cpp benchmark.hpp stopwatch.hpp
	$(CC) $(FLAGS) -c benchmark.cpp

main.o: main.cpp stopwatch.hpp
	$(CC) $(FLAGS) -c main.cpp stopwatch.hpp
