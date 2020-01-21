
void printIntGroup(int* group, size_t size){
   assert(group); //良好习惯
  for(size_t s = 0; s < size ; s++) 
       std::cout << group[s] << std::endl;
}

//for memory 
void forC(){
  int* intGroup = (int*)malloc(sizeof(int)*10);
  //malloc后需要检查, 是否分配内存成功
  if(intGroup)
       printIntGroup(intGroup , 10);
  free(intGroup);
}mespace CStruct{
  struct SList {
        SList* next;
            int value;
              
  }; 

void forNew(){
  int* intGroup = new int[10]; //此处不需要检查, 因为new自带抛出异常
  printIntGroup(intGroup, 10);
  //delete intGroup ;
  delete[] intGroup ; //数组,所以需要delete[]
}


void remarkRoom(int* p , size_t size){//p 是指针, 相当于调用函数时是复制, 除非用引用 int& ,将分配的内存传出
  // 内存泄漏
  p = (int*)malloc(sizeof(int)*size);
}

void testRemarkRoom(){
  const int size = 3;
  int* p = (int*)malloc(sizeof(int) * size);
  if(size < 10) remarkRoom(p, 10); // remarkRoom分配的空间 没有传过来, 
    free(p);
}


const char* nameInfo()
{
  char info[] = "this is a test"; //局部资源, 出作用域会被析构, 
  return info;
}

void testInfo()
{
  std::string info;
  if(info.empty()) info = nameInfo();
  //shuchu
  std::cout << info << std::endl;
}




//set只会存放不重复元素, insert的时候可能没用30 , 此时find(30)会返回指向迭代器尾部end的指针,
//*pos30 解引用end指针会报错
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
  group.erase
  (
    std::remove(group.begin(), group.end(), value),//remove将所有等于value的值后移至group末尾,返回的是所有vlaue的
                                                  //的第一个位置指针, 此时再 group.end区间内就都是要删除的值了
    group.end();
   )
}

void testRemoveAllSameValue(){
std::vector<int>group;
for(int i = 0; i < 1000000; ++i) group.push_back(rand() % 10);
auto s = group.size();
removeAllSameValue(group, 0);
auto after = group.size();
std::cout << "total removed " << (s- after) << std::endl;
}




