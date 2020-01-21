#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void callback(const boost::system::error_code&)
{
  std::cout << "hello amo " << std::endl;
}

int main()
{
  boost::asio::io_service io;
  boost::asio::deadline_timer t{io, boost::posix_time::seconds(5)};
  t.async_wait(callback);//相当于注册了一个回调函数 

  std::cout << "start run\n";
  io.run();//异步事件   真正在run里面执行的, 
  std::cout << "finish run\n";
}
