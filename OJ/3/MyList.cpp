// MyList.cpp
#include "MyList.h"

using namespace std;
   
// 构造函数
MyList::MyList() 
{
    head = NULL;
}

// 析构函数
MyList::~MyList()
{ 
    while (head != NULL)
    { 
        Node *n = head;
        head = head->next;
        delete n;
    }  
}

// 添加新的节点
void MyList::add(char c)
{
    Node *n = new Node;
    if (n == NULL)
    {	
        cout << "Overflow\n";
        exit(-1);
    } 
    else {
        n->content = c;
        n->next = NULL;
        if (head == NULL) {
            head = n;
        }
        else {
            Node *tail = head;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = n;
        }
    }
}

/* TODO:
 * 移除所有content等于c的节点，没有则不移除
 * 确保 head 仍是新链表的头部，且未删除节点的顺序保持一致
 * 输出移除的节点数量(number)
 */
void MyList::removeNode(char c)
{
    int number = 0;

    if(this->head == NULL){
        cout << number << endl;
        return;
    }
    while (head!=NULL && this->head->content == c)
    {
        head = head->next;
        number ++;
    }
    
    if(head != NULL){
        Node* current = head->next;
        Node* prev_cur = head;
        while (current != NULL)
        {
        while (current!=NULL && current->content != c)
        {
            current = current->next;
            prev_cur = prev_cur->next;
        }
        if(current == NULL){
            break;
        }

        prev_cur->next = current->next;
        current = current->next;
        number++;
        }
    }


    


    

    cout << number << endl;
}

// 从表头开始按加入顺序打印元素
void MyList::printList()
{
    Node* n = head;
    while (n != NULL)
    { 
        cout << n->content << " ";
        n = n->next;
    }
    cout << endl;
}

int main(){
    MyList mylist;
    mylist.add('N');
    mylist.add('N');
    mylist.add('N');
    mylist.removeNode('N'); // 移除所有的节点
    mylist.printList(); // 从头部遍历打印mylist
    return 0;
}