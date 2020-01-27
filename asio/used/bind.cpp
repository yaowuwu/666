#include <iostream>
#include <boost/bind.hpp>
#include <memory>
#include <vector>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/asio.hpp>
#include <iostream>
//测试vscode chengggong

class printer 
{
public:
    printer(boost::asio::io_service &io )
        : timer_(io, boost::posix_time::seconds(1)), count_(0)
    {
    //  timer_.async_wait(boost::bind( &printer::print, this)); 
    // 用lambda不用bind的三个原因:
    //1 上面的bind 实际 等价于 
    //  bind  ==>  function<void(const boost::system::error_code)>
    //  也就是bind 里面一系列类型检查, 这也是下面lam 要const auto&的原因
    //  bind开销大,效率低, 返回的是一个function,而lam只返回 this指针， 
    //2  bind sizeof大 至少16个字节， lam只有8个字节 this指针的大小
    //3, lambda的返回this指针 生命周期长,在printer析构前不会失效
    //推荐用lam 1
       timer_.async_wait([this](const auto&){this->print();});
    }

    ~printer(){std::cout << "Final count is " << count_ << std::endl; }

    void print()//bind成员函数
    {
        if(count_ < 5)
        {
            std::cout << count_ << std::endl;
            ++count_;
        

        timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
       // timer_.async_wait(boost::bind(&printer::print, this));
        timer_.async_wait([this](const auto&){this->print();});
         }
    }


private:
    boost::asio::deadline_timer timer_;
    int count_;
};

int main()
{
    boost::asio::io_service io;
    printer p(io);
    io.run();
    return 0;
}

