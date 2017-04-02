all:
	mkdir bin -p
	g++ server.cpp -lboost_system -o ./bin/server #-O3 -std=c++11 
	g++ client.cpp -lboost_system -o ./bin/client #-O3 -std=c++11 