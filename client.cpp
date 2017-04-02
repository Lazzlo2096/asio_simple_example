#include <iostream>
#include <boost/asio.hpp>//libws2_32.a, libboost_system.a
// #include <windows.h>

int main(){
    std::cout<<"Client is running\n";
    try{
        boost::asio::io_service io;
        boost::asio::ip::tcp::socket sock(io);
        boost::asio::ip::tcp::endpoint endPoint(boost::asio::ip::address::from_string("127.0.0.1"), 9090);
        boost::system::error_code err;
        sock.connect(endPoint, err);
        if(err) throw boost::system::system_error(err);
        else std::cout<<"Connection established\n";
        boost::asio::streambuf sbuf;
        boost::asio::read_until(sock, sbuf, "!");
        std::cout<<&sbuf<<std::endl;
        sock.close();
    }
    catch(std::exception& e){
        char buf[512];
        // CharToOem(e.what(), buf);
        // std::cout << "Exception was occured: " << buf << std::endl;
        std::cout << "Exception was occured: " << e.what() << std::endl;
    }
    return 0;
}