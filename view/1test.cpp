#include <string>
#include <iostream>
#include <memory>
#include <set>
#include <cstdlib>
//for class
namespace Test{
  class Object{
  public:
    using pointer = std::shared_ptr<Object>;
    virtual std::string debugName() const = 0;
    //virtual ~Object(){} //必须加
    virtual ~Object(){} //必须加
    //对于基类来说,如果有虚函数,它必须带有虚析构函数,只有这样 析构时 才会正确调用派生类的析构函数,
    //否则它将会调用基类本身的析构函数, 而不会去调用派生类的析构函数,
    //意味着如果派生类带有成员变量, 则成员变量的析构函数不会被调用,
    //本质是内存泄漏
    //还有如果派生类析构函数多做了 一些事情,他也无法知道
  };
//没有成员变量 的类 sizeof 是1, 只要一个地址就行,
//但因为有虚函数,有一个隐藏指针指向虚函数地址,64位系统下一个指针大小 8个字节
//
  class RealObject : public Object {
    public:
      std::string debugName() const {return "RealObject";}
      ~RealObject(){std::cout << "bye" << std::endl;}
  };

//没有成员变量 的类 sizeof 是1
//从基类Object继承过来, 也有一个指向虚函数偏移地址的指针, 也是8个字节


  void testObject(const Object& obj){
    std::cout << obj.debugName() << std::endl ;
  }

  //你觉得以下有问题吗
  void testCase(){
    RealObject obj;
    //栈上构造的obj 析构时调用的自然是RealObject的析构函数
    testObject(obj);
    auto pObj = std::make_shared<RealObject>();
    //析构时调用的RealObject的析构函数
    testObject(*pObj);
    std::unique_ptr<Object>uObj = std::make_unique<RealObject>();
    //析构时 unique_ptr调用的是Object的析构函数
    
    testObject(*uObj);
  }
}

int main(){
  Test::testCase();
}
