//c struct
namespace CStruct{
    struct SList {
        SList* next;
        int value;
    };
    // has two state
    // SL -> SL -> SL -> nullptr;
    // or circle
//    inline bool isCircle(SList* header){
//        return false;
//    }


    inline bool isCircle(SList* header){
        if(!header) return false;//空指针

        auto next = header->next;//一个元素
        if(!next)
            return false;

        auto nextNext = next->next;
        while(next && nextNext)
        {
            if (next == next->next)//前后两指针相等时,证明是环
             return true;
            next = next->next; // 走一步
            nextNext = nextNext->next; //走一步
            if (nextNext)
                nextNext = nextNext->next;

        }
        return false;
    }

    void testSList(){
        SList* next = nullptr;
        SList* current = nullptr;
        SList* start = nullptr;
        for(int i = 0; i < 10; ++i) {
            current = new SList;
            current->next = next;
            next = current;
        }

        if (!start) start = current ;

        auto cir = isCircle(start);//cir should be false

        next = nullptr;
        current = nullptr;
        start = nullptr;
        SList* last = nullptr;

        for(int i = 0; i < 10; ++i){
            current = new SList;
            current->next = next;
            current->value = i;
            next = current ;
            if !start start = current ;
        }
        if(!start) start = current;
        if(last) last->next = start;

        cir = isCircle(start);//cir should be true
    }
}
