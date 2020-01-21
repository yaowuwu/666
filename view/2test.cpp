void isGoodOrBad(const std::vector<int>& objects)
{
  const int size = 100;
  vector<int>tar;
  
  int pos = 0;
  if(pos == objects.size() - 1)
  {
    tar.push_back(objects(pos));
  //好  
    tar.insert(tar.end(), objects.begin(), objects.end() + pos);
    //将一个vector插入另一个vector 
    //for循环添加 , 不好, push_back自动判断 当前size 与 capacity 大小, 自动扩容,
    //写for循环可能会扩容多次, 
    //但如果用上面insert 初始给出要插入的 object大小,begin, end, 则只需要扩容一次
    //效率更nice
 
  //差  
    for(int i = 0; i < pos; i++)
    {
      tar.push_back(objects[i]);
    }
  }
}


void isGoodOrBad(std::vector<int>& objects)
{
  //objectj is very huge
  //we only need top ten
  std::sort(objects.begin(), objects.end());
  if(objects.size() > 10) objects.erase(objects.begin() + 10, objects.end());
  //将10后面的数字删除后, vector大小内存并没有降下来, 为什么
}
