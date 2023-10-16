#include "SmartPointer.h"
#include <iostream>
using namespace std;

SmartPointer::SmartPointer(const SmartPointer &sptr)
{
    this->pointer = sptr.pointer;
    this->ref_cnt = sptr.ref_cnt;
    if(sptr.ref_cnt != nullptr &&  sptr.pointer != nullptr){
        *this->ref_cnt +=1;
    }

}

void SmartPointer::assign(const SmartPointer &sptr)
{
    if(&sptr == this){
        return;
    }

    if(this->ref_cnt!=nullptr && this->pointer != nullptr){
        *this->ref_cnt -=1;
        if( *this->ref_cnt == 0){
            delete this->pointer;
            this->pointer = nullptr;
            delete this->ref_cnt;
            this->ref_cnt = nullptr;
        }
    }


    this->pointer = sptr.pointer;
    this->ref_cnt = sptr.ref_cnt;
    if(sptr.ref_cnt != nullptr &&  sptr.pointer != nullptr){
        *sptr.ref_cnt += 1;
    }
}

SmartPointer::~SmartPointer()
{
    if(this->pointer == nullptr || this->ref_cnt==nullptr){
        delete pointer;
        delete ref_cnt;
        return;
    }
    *this->ref_cnt -=1;

    if( *this->ref_cnt == 0){
        delete this->pointer;
        delete this->ref_cnt;

    }

    this->pointer = nullptr;
    this->ref_cnt = nullptr;

}

int main(){
    SmartPointer* sp1=new SmartPointer(new Node(11));
    SmartPointer* sp2=new SmartPointer(new Node(22));
    sp2->assign(*sp2);
    sp1->assign(*sp2);
    sp2->assign(*sp1);
    sp1->~SmartPointer();
    sp1->assign(*sp1);
    delete sp1;
    delete sp2;

}
