all: main.o stringset.o
		g++ -o pa1 main.o stringset.o

main.o: main.cpp
		g++ -c main.cpp

stringset.o: stringset.cpp
		g++ -c stringset.cpp

clean:
		rm -f *.o pa1
