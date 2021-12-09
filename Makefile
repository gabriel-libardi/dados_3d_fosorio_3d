
all: point_3d

run: point_3d
		./point_3d

main.o: main.cpp
		g++ -Wall -g -o main.o -c main.cpp

query.o: query.cpp
		g++ -Wall -g -o query.o -c query.cpp

point_3d: main.o query.o
		g++ -Wall -g -o point_3d main.o query.o
		