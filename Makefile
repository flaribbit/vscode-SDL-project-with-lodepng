CC=g++
INC=./include
CFLAGS=-I $(INC) -s -O2 -DNDEBUG -std=c++11

a.exe: main.cpp res.o lodepng.o sprite.o
	$(CC) main.cpp SDL2.dll res.o lodepng.o sprite.o $(CFLAGS) -o a.exe

res.o: res.rc manifest.xml
	windres res.rc -o res.o

lodepng.o: lodepng.cpp
	g++ -c lodepng.cpp $(CFLAGS)

sprite.o: sprite.cpp
	g++ -c sprite.cpp $(CFLAGS)
