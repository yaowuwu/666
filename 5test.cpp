//void valueTest(){
//    char a = 64;
//    char b = a << 1; //-128
//    char c = b >> 1; //-64
//    //what value of b c;
//}


//hard write foreach
template<typename Container, typename Func>
void foreach(Container& c, Func func){
    for(auto iter = c.begin(), iterEnd = c.end(); iter != iterEnd; ++iter){
        func(*iter);

    }




//更通用foreach
template<typename Container, typename Func>
void foreach(Container& c, Func func)
{
   std::foreach(std::begin(c), std::end(c), func);
}




