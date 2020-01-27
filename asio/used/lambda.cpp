/*
   [capture list] (params list) mutable exception-> return type { function body } 

   capture list：捕获外部变量列表
   params list：形参列表
   mutable指示符：用来说用是否可以修改捕获的变量
   exception：异常设定
   return type：返回类型
   function body：函数体

   yum install centos-release-scl-rh
   yum -y install devtoolset-4-gcc devtoolset-4-gcc-c++
   scl enable devtoolset-4 bash
   echo "source /opt/rh/devtoolset-4/enable" >> ~/.bashrc




#include <iostream>
#include <boost/asio.hpp>
//#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void print(const boost::system::error_code&  ,
boost::asio::deadline_timer *t, int *count)
{
if(*count < 5)
{
std::cout << *count << std::endl;
++(*count);

t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
t->async_wait([t, count](const auto &error){print(error, t, count);});
}
}

void callback(const boost::system::error_code& e)
{
std::cout << "hello world" << std::endl;
}

int main()
{

boost::asio::io_service io;
int count = 0;
boost::asio::deadline_timer t(io, boost::posix_time::seconds(1));
t.async_wait([&t,&count](const auto &error) {print( error, &t, &count );});

io.run();

return 0;
}
*/

#include <memory.h>
#include <iostream>
#include <boost/asio.hpp>
//#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void testLambda()
{
    auto lambda = [](){}; // []{}   
    lambda();
    std::cout << "sizeof lambda: " << sizeof(lambda) << std::endl;

}


void print(const boost::system::error_code& /*e*/ ,
           std::shared_ptr<boost::asio::deadline_timer> t, int *count)
{
    if(*count < 5)
    {
        std::cout << *count << std::endl;
        ++(*count);

        t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
        t->async_wait([t, count](const auto &error){print(error, t, count);});
    }
}

void callback(const boost::system::error_code& e)
{
    std::cout << "hello world" << std::endl;
}

std::shared_ptr<boost::asio::deadline_timer>
     registerPrint(boost::asio::io_service &io, int *count)
{
    auto t = std::make_shared<boost::asio::deadline_timer>(
            io, boost::posix_time::seconds(1));

//    auto pt = t.get();
 //   t->async_wait([pt, count](const auto &error) {print(error, pt, count);});
    t->async_wait([t, count](const auto &error) {print(error, t, count);});
    return t;
}

int main()
{
    testLambda();
    boost::asio::io_service io;
   // int count = 0;
   // auto t = registerPrint(io, &count);
   // t.reset();
   //
    std::vector<int>v;
    for(auto i = 0; i < 5; ++i) v.push_back(i);
    for(auto i = 0; i < 5; ++i)
    {
        auto t = registerPrint(io, &v[i]);
        std::cout << "pointer adder is: " << t.get() << std::endl;
    }
    io.run();

    return 0;
}




