#include <iostream>
//#include <chrono>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
//太老, 
//#include <boost/date_time/posix_time/posix_time.hpp>
void callback(const boost::system::error_code&)
{
    std::cout << "Hellp wo" << std::endl;
}

void callback2(const boost::system::error_code&)
{
    std::cout << "second call but first run " << std::endl;
}


int main()
{
    boost::asio::io_service io;
    boost::asio::steady_timer st(io);
  //  st.expires_from_now(boost::chrono::seconds(5));
    st.expires_from_now(std::chrono::seconds(5));
    st.wait();
    std::cout << "hello world\n";
    std::cout << "Hello world" << std::endl;
    return 0;
}

