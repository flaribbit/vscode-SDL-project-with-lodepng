CC=g++
INC=./include
CFLAGS=-I $(INC) -lmingw32 -s -O2 -DNDEBUG

a.exe: main.cpp
	$(CC) main.cpp SDL2.dll $(CFLAGS) -o a.exe
