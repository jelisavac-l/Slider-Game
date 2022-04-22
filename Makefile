all: compile link

compile:
	g++ -I src/include -c main.cpp Player.cpp
link:
	g++ Player.o -o Player main.o -o main -L src/lib -l sfml-graphics -l sfml-window -l sfml-system