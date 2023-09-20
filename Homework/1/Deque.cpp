
#include <iostream>
using namespace std;

class Deque
{
private:

    class Node
{
private:

public:
    Node* front;
    Node* next;
        int num;
    Node(int num, Node* front, Node* next){
        this->num=num;
        this->front = front;
        this->next = next;
    }
    Node(int num){
        this->num = num;
        this->front = nullptr;
        this->next = nullptr;
    }
};

    /*哨兵的frontNode是最后一个Node
        nextNode是第一个Node
    */
    Node* const sentinal = new Node(0,nullptr,nullptr);
    size_t amount;

public:
    Deque(){
        this->amount =0;
    }
    ~Deque(){
        Node* cur = this->sentinal->next;
        while (cur!=nullptr || cur!=this->sentinal)
        {
            Node* p = cur;
            cur = cur->next;
            delete p;
        }
        
    }

    void push_front(int x){
        Node* newNode = new Node(x,this->sentinal,this->sentinal->next);
        if(this->amount>=1){
            Node* firstNode = this->sentinal->next;
            firstNode->front =  newNode;
        }
        this->sentinal->next = newNode;
        if(this->amount==0){
            this->sentinal->front = newNode;
        }
        this->amount++;
    }

    void push_back(int x){
        Node* newNode = new Node(x,this->sentinal->front,this->sentinal);
        if(this->amount >=1){
            Node* lastNode = this->sentinal->front;
            lastNode->next = newNode;
        }
        this->sentinal->front = newNode;
        if(this->amount==0){
            this->sentinal->next = newNode;
        }
        this->amount++;
    }
    
    int pop_front(){
        if(this->amount <=0){
            return -1;
        }
        Node* secondNode = this->sentinal->next->next;
        int res = this->sentinal->next->num;
        if(this->amount>=2){
            //第二个节点的front变成sentinal
            secondNode->front = this->sentinal;
        }

        //删除第一个节点
        delete this->sentinal->next;
        this->sentinal->next = secondNode;
        this->amount--;
        return res;
    }

    int pop_back(){
        if(this->amount <=0){
            return -1;
        }
        Node* lastSecondNode = this->sentinal->front->front;
        int res = this->sentinal->front->num;
        if(this->amount>=2){
            //倒数第二个节点的next变成sentinal
            lastSecondNode->next = this->sentinal;
        }
        //删除倒数第一个节点
        delete this->sentinal->front;
        this->sentinal->front = lastSecondNode;
        this->amount--;
        return res;
    }

    size_t size(){
        return this->amount;
    }


};




