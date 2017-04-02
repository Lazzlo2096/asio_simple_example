#include <iostream>
#include <string>
#include <boost/asio.hpp>//libws2_32.a, libboost_system.a
// #include <windows.h>

int main (){
    std::cout<<"Server is running\n";
    try{
        boost::asio::io_service io;
        boost::asio::ip::tcp::acceptor acc(io, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 9090));
        std::string s="Hello from server!";
        while(true){
            boost::asio::ip::tcp::socket sock(io);
            acc.accept(sock);
            std::cout<<"Client has been accepted\n";
            boost::asio::write(sock, boost::asio::buffer(s));
        }
        acc.close();
    }
    catch(std::exception& e){
        char buf[512];
        // CharToOem(e.what(), buf);
        // std::cout << buf << std::endl;
        std::cout << e.what() << std::endl;
    }
    return 0;
}