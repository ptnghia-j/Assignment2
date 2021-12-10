all: assign2

assign2: Allocation.o Translation.o main.o
		g++ Allocation.o Translation.o main.o -lpthread -o assign2 


Allocation.o : Allocation.cpp
			    g++ -c Allocation.cpp
Translation.o: Translation.cpp
			    g++ -c Translation.cpp

main.o: main.cpp
		g++ -c main.cpp
clean:
		rm -rf *o assign2
