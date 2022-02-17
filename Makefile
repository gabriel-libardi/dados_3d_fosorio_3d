
all: point_3d

run: point_3d
		./point_3d

main.o: ./src/main.cpp
		g++ -Wall -g -o main.o -c ./src/main.cpp

query.o: ./src/query.cpp
		g++ -Wall -g -o query.o -c ./src/query.cpp

point_3d: main.o query.o
		g++ -Wall -g -o point_3d main.o query.o
		