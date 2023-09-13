#include "MonotonicStack.h"

int MonotonicStack::size(){
    return s.size();
}

void MonotonicStack::pop(){
    if(s.size()>0){
        s.pop();
    }
}

int MonotonicStack::top(){
    return s.top();
}

int MonotonicStack::push(int element){
    int result = 0;
    while (s.size()>0 && s.top()>element)
    {
       result += s.top() - element;
       s.pop();
    }
    s.push(element);
    return result;
    
}

int MonotonicStack::function(const int* arr,int n){
    int result = 0;
    for(int i = 0;i<n;i++){
        result += this->push(arr[i]);
    }
    while (size() != 0)
    {
        result += this->top();
        this->pop();
    }
    return result;

}

/*
int main() {
    MonotonicStack* ms = new MonotonicStack;
    ms->push(8);
    ms->push(4);
    ms->push(6);
    ms->push(2);
    ms->push(3);
    cout<<ms->top()<<endl;
    ms->pop();
    cout<<ms->top()<<endl;
    ms->pop();
    cout<<ms->size()<<endl;
    delete ms;
}
*/

int main()
{
    MonotonicStack *ms = new MonotonicStack;
    ms->push(10);
    ms->push(1);
    cout << ms->top() << endl;
    ms->push(1);
    cout << ms->size() << endl;
    ms->push(6);
    cout << ms->top() << endl;
    ms->pop();
    cout << ms->top() << endl;
    cout << ms->size() << endl;
    delete ms;
}
