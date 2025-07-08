#include <iostream>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(){
    try{

       boost::asio::io_context io_context; 
       tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 23456));
       std::cout << "[Server] listening on port 23456"<<std::endl;

       tcp::socket socket(io_context);
       acceptor.accept(socket);
       std::cout<<"[Server] client connected"<<std::endl;

       char data[1024] = {0};
       size_t length = socket.read_some(boost::asio::buffer(data));
       std::cout << "[Server] Received: " <<std::string(data, length) << std::endl;
    



    } catch (std::exception& e){
        std::cerr <<"error: " <<e.what() <<"\n";

    }

    return 0;

}