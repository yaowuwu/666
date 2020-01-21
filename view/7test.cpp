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
            ObjA aa(a);
            ObjB bb(b);
            m_a.swap(aa);
            m_b.swap(bb);
        }
    };
}