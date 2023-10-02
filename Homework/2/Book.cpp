#include <iostream>
#include <cstring>
using namespace std;

class Book
{
    static int BookCnt;
    char *name;

public:
    Book(const char *_name);
    ~Book();
    char *get_name() const;
    void set_name(const char *_name);
};

int Book::BookCnt=0;

Book::Book(const char *_name)
{
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
    BookCnt++;
}
Book::~Book()
{
    delete[] name;
    name = nullptr;
    BookCnt--;
}
char *Book::get_name() const
{
    return name;
}
void Book::set_name(const char *_name) 
{
    delete[] name;
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}







int main()
{
    Book b1("Computer Science");
    Book b2(b1);
    return 0;
}
