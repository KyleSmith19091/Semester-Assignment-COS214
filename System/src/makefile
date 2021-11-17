output:	CarryType.o Cargo.o Collections.o VectorOfCargo.o Iterator.o CargoIterator.o main.o
	g++ CarryType.o Cargo.o Collections.o VectorOfCargo.o Iterator.o CargoIterator.o main.o -o output
main.o:	main.cpp
	g++ -c main.cpp
Cargo.o: Cargo.cpp
	g++ -c Cargo.cpp
CarryType.o: CarryType.cpp
	g++ -c CarryType.cpp
Iterator.o: Iterator.cpp
	g++ -c Iterator.cpp
Collections.o: Collections.cpp
	g++ -c Collections.cpp
VectorOfCargo.o: VectorOfCargo.cpp
	g++ -c VectorOfCargo.cpp
CargoIterator.o: CargoIterator.cpp
	g++ -c CargoIterator.cpp
clean:
	rm *.o output
run:
	./output