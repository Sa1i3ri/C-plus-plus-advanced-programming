class A
{

public:
    int x;
    int y;
    void f_A();
    void g_A(int i){
        this->x=i;
        f_A();
    }
};

int main(){
    A* a=new A;
    A* b = new A;
    a->f_A();
    a->g_A(1);
    b->f_A();
    b->g_A(2);
}
