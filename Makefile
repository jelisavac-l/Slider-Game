all: compile link

compile:
	g++ -I src/include -c main.cpp Player.cpp Coin.cpp
link:
	g++ player.o coin.o main.o -o main -L src/lib -l sfml-graphics -l sfml-window -l sfml-system -l sfml-audio