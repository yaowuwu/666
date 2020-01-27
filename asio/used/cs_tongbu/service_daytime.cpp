// e /etc/services   chakan 
#include <ctime>
#include <cstring>
#include <iostream>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;


static 
std::string make_daytime_string(){
   using namespace std; //For time_t time and ctime;
  // time_t now  = time(0);
   auto  now  = time(nullptr);
   return ctime(&now); //const char*
}

//root linux <1024
int main(int argc, char *argv[])
{
    try{
        boost::asio::io_service io_service;

        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 13));
        std::cout << "start service " << std::endl;  

        for(;;){
            tcp::socket socket(io_service);
            acceptor.accept(socket);

            auto message = make_daytime_string();

            boost::system::error_code ignored_error;
            boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
        
        }
        std::cout << "bye" << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

