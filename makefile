all: server.exe
	
WIN_LIBS = -lwsock32 -lws2_32
#it with MinGW Distro nuwen
	
#dirbin:
#	mkdir bin -p

server.exe: server.cpp
	g++  server.cpp  $(WIN_LIBS) -lboost_system -o ./server

#./bin/client: client.cpp
#	g++ client.cpp -lboost_system -o ./client