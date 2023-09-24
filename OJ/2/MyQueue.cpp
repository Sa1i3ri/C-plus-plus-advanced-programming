// MyQueue.cpp
#include "MyQueue.h"
using namespace std;

MyQueue::MyQueue()
{
    return;
}

// 元素从队尾入队
void MyQueue::push(char c)
{
    
    while (s1.size()!=0)
    {
        s2.push(s1.pop());
    }
    s1.push(c);
    while (s2.size()!=0)
    {
        s1.push(s2.pop());
    }
    
    
    

}

// 队首元素出队，返回出队的元素（我们没有定义空队列pop操作，测试用例中不会涉及）
char MyQueue::pop()
{
    char result;
    result = s1.pop();
    return result;
}

// 返回队列的大小（队列内元素的个数）
int MyQueue::size()
{
    int result;
    result = s1.size();
    return result;
}

int main() {
    MyQueue q;
    q.push('N');
    q.push('J');
    q.push('U');
    cout << q.size() << endl; // 3
    cout << q.pop() << endl; // N
    cout << q.pop() << endl; // J
    cout << q.pop() << endl; // U
    cout << q.size() << endl; // 0
    return 0;
}