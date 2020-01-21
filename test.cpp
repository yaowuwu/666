#include <string>
#include <iostream>
#include <memory>
#include <set>
#include <cstdlib>
#include <cstdlib>
//using namespace std;

//for class
namespace Test{
  class Object{
  public:
    using pointer = std::shared_ptr<Object>;
    virtual std::string debugName() const = 0;
  };

  class RealObject : public Object {
    public:
      std::string debugName() const {return "RealObject";}
  };

  void testObject(const Object& obj){
    std::cout << obj.debugName();
  }

  //你觉得以下有问题吗
  void testCase(){
    RealObject obj;
    testObject(obj);
    auto pObj = std::make_shared<RealObject>();
    testObject(*pObj);
    std::unique_ptr<Object>uObj = std::make_unique<RealObject>();
    testObject(*uObj);
  }
}


   void printIntGroup(int* group, size_t size){
   for(size_t s = 0; s < size ; s++) std::cout << group[s] << std::endl;
   }

//for memory 
void forC(){
int* intGroup = (int*)malloc(sizeof(int)*10);
printIntGroup(intGroup , 10);
free(intGroup);
}

void forNew(){
int* intGroup = new int[10];
printIntGroup(intGroup, 10);
delete intGroup ;
}


void remarkRoom(int* p , size_t size){
p = (int*)malloc(sizeof(int)*size);
}

void testRemarkRoom(){
const int size = 3;
int* p = (int*)malloc(sizeof(int) * size);
if(size < 10) remarkRoom(p, 10);
free(p);
}

const char* nameInfo()
{
  char info[] = "this is a test";
  return info;
}

void testInfo()
{
  std::string info;
  if(info.empty()) info = nameInfo();
  //shuchu
  std::cout << info << std::endl;
}



//iterator
void printRange(){
std::set<int>group;
for(int i = 0; i < 100; ++i) group.insert(rand()%100);
auto pos30 = group.find(30);
auto pos50 = group.find(50);
for( ; pos30 != pos50; pos30++) std::cout << "info " << *pos30 << std::endl;
}

//删除所有特征值
template<typename T>// T has ==
void removeAllSameValue(std::vector<T>& group, T value){
//如何实现

}

void testRemoveAllSameValue(){
std::vector<int>group;
for(int i = 0; i < 1000000; ++i) group.push_back(rand() % 10);
auto s = group.size();
removeAllSameValue(group, 0);
auto after = group.size();
std::cout << "total removed " << (s- after) << std::endl;
}

//c struct
namespace CStruct{
  struct SList {
    SList* next;
    int value;
  };
  // has two state
  // SL -> SL -> SL -> nullptr;
  // or circle
  inline bool isCircle(SList* header){
    return false;
  }

  void testSList(){
    SList* next = nullptr;
    SList* current = nullptr;
    SList* start = nullptr;
    for(int i = 0; i < 10; ++i){
      current = new SList;
      current->next = next;
      next = current ;
      if !start start = current ;
    }
    auto cir = isCircle(start);//cir should be falsei

    next = nullptr;
    current = nullptr;
    start = nullptr;

    for(int i = 0; i < 10; ++i){
      current = new SList;
      current->next = next;
      current->value = i;
      next = current ;
      if !start start = current ;
    }
    current->next = start;
    cir = isCircle(start);//cir should be true 
  }
}


void valueTest(){
  char a = 64;
  char b = a << 1;
  char c = b >> 1;
  //what value of b c;
}

//hard write foreach
template<typename Container, typename Func>
void foreach(Container& c, Func func){
  for(auto iter = c.begin(); iter < c.end(); iter++){
    func(*iter);

  }
  //have some not "right use"

  //algorithm
  int maxHuiwen(const char* buffer){
    return 0;
  }


  //exception
  namespace Exception{
    class ObjA{
      public:
        ObjA(int c) :m_value(new int c){
          if((c + rand()) % 5 == 0) throw "bad";
        }
        int value() const {return *m_value;}
        void swap(ObjA& rhs){std::swap m_value, rhs.m_value;}
      private:
        std::unique_ptr<int>m_value;
    };

    class ObjB{
      public:
        ObjB(int c) :m_value(new int c){
          if((c + rand()) % 5 == 0) throw "bad";
        }
        int value() const {return *m_value;}
        void swap(ObjB& rhs){std::swap m_value, rhs.m_value;}
      private:
        std::unique_ptr<int>m_value;
    };

    class Object{
      private:
        ObjA m_a;
        ObjB m_b;
      public:
        Object():ObjA(rand()), ObjB(rand()){}
        //reset ObjectA value to a, ObjectB value to b
        //need exception safe and data unchanged if throwi
        void resetAAndB(int a, int b){

        }
    };
  }






















