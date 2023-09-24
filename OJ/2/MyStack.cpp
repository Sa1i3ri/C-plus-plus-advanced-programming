// MyStack.cpp
#include "MyStack.h"

using namespace std;
   
// 构造函数
MyStack::MyStack() 
{
    this->amount=0;
    this->sentinel = new Node;
    sentinel->next = nullptr;
    this->top = this->sentinel;
}

// 析构函数，你需要在这里归还额外申请的资源
MyStack::~MyStack()
{
    while (this->top!=this->sentinel || this->top != nullptr)
    {
        Node* temp = this->top;
        this->top = this->top->next;
        delete temp;
    }
    
}

// 字符c入栈
void MyStack::push(char c)
{
    Node* newNode = new Node;
    newNode->content=c;
    newNode->next = this->top;
    this->top = newNode;
    this->amount++;
}

// 栈顶元素出栈，返回出栈元素（我们没有定义空栈pop操作，测试用例中不会涉及）
char MyStack::pop()
{
    char result = this->top->content;
    Node* temp = this->top;
    this->top = this->top->next;
    delete temp;
    this->amount--;
    
    return result;
}

// 返回栈的大小（栈内元素数量）
int MyStack::size()
{
    return this->amount;
}
