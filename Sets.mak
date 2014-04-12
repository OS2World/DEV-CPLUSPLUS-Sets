# Makefile for emx 0.8 with dmake
# Sets 1.15 (May 24, 1997)

GCC = gcc -Wall -O2

.SUFFIXES: .cpp .o

.cpp.o:
	$(GCC) -o $*.o -c $*.cpp

SetTest: SetTest.o Sets.o
	$(GCC) -o SetTest.exe SetTest.o Sets.o

SetTest.o: SetTest.cpp Sets.hpp

Sets.o : Sets.cpp Sets.hpp

# use InfoZip's zip program, and make it PK-zip compatible
zip: 
	zip -j -k Sets.zip SetTest.exe SetTest.cpp Sets.cpp Sets.hpp Sets.txt Sets.mak

