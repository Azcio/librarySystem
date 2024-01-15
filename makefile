output: librarySystem.o member.o Person.o
	g++ librarySystem.o member.o Person.o -o output

librarySystem.o: librarySystem.cpp librarian.h
	g++ -c librarySystem.cpp

member.o: member.cpp member.h
	g++ -c member.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp

clean:	
	rm *.o output