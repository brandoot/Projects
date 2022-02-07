Number: Number_main.o Number.o
	g++ -o Number Number_main.o Number.o
Number_main.o: Number_main.cpp Number.h
	g++ -c Number_main.cpp
Number.o: Number.cpp Number.h
	g++ -c Number.cpp
clean:
	rm *.o Number
