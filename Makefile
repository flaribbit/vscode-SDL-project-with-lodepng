CC=g++
INC=./include
CFLAGS=-I $(INC) -lmingw32 -s -O2 -DNDEBUG

a.exe: main.cpp res.o
	$(CC) main.cpp SDL2.dll res.o $(CFLAGS) -o a.exe

res.o: res.rc manifest.xml
	windres res.rc -o res.o
