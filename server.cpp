#include <iostream>
#include <string>
#include <boost/asio.hpp>//libws2_32.a, libboost_system.a
// #include <windows.h>

using namespace std;
using namespace boost::asio;

int main (){
    cout<<"Server is running\n";
    
    try{
        io_service io;
        ip::tcp::acceptor acc(
            io,
            ip::tcp::endpoint(ip::tcp::v4(), 9090)
        );

        string s = "Hello from server!";

        while(true){
            ip::tcp::socket sock(io);
            acc.accept(sock);
            cout<<"Client has been accepted\n";
            write(sock, buffer(s));
        }
        
        acc.close();
    }
    catch(exception& e){
        // char buf[512];
        // CharToOem(e.what(), buf); // windows
        // cout << buf << endl;

        cout << "Exception has occurred: " << e.what() << endl; // Произошло исключение e
    }
    return 0;
}