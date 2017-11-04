all: trabalhocg

trabalhocg:circle.o tinyxml2.o player.o rectangle.o main.cpp
	g++ main.cpp circle.o tinyxml2.o player.o rectangle.o -o trabalhocg -std=c++11 -lGL -lglut -lGLU -std=c++1z

circle.o:circle.cpp
	g++ -c circle.cpp

tinyxml2.o:tinyxml2.cpp
	g++ -c tinyxml2.cpp

player.o:player.cpp
	g++ -c player.cpp

rectangle.o:rectangle.cpp
	g++ -c rectangle.cpp

clean:
	rm -r *.o
