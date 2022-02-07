MemberData: MemberData_main.o MemberData.o
	g++ -o MemberData MemberData_main.o MemberData.o
MemberData_main.o: MemberData_main.cpp MemberData.h
	g++ -c MemberData_main.cpp
MemberData.o: MemberData.cpp MemberData.h
	g++ -c MemberData.cpp
clean:
	rm *.o MemberData
