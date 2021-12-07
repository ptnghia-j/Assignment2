all: assign2

assign2: problemFuncsDef.o funcsImp.o main.o
		g++ problemFuncsDef.o funcsImp.o main.o -lrt -lpthread -o assign2 


problemFuncsDef.o : problemFuncsDef.cpp
			    g++ -c problemFuncsDef.cpp
					  
funcsImp.o: funcsImp.cpp
			g++ -c funcsImp.cpp
			
main.o: main.cpp
		g++ -c main.cpp
			 		 
clean: 	
		rm -rf *o assign2
