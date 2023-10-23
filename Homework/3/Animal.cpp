#include <string.h>
#include <cstring>
using namespace std;

class Animal {
public:
Animal() = default;
Animal(const Animal&) = default;
Animal& operator=(const Animal&) = default;
virtual ~Animal() = default;

};
class Person : public Animal {
public:
    Person(char *name) : Animal() {
        _name = new char[strlen(name) + 1];
        std::strcpy(_name, name);
    }
    Person(const Person &person) {
        this->_name = new char[strlen(person._name)+1];
        strcpy(this->_name,person._name);
    }
    Person& operator=(const Person &person) {
        if(this != &person){
            this->_name = new char[strlen(person._name)+1];
            strcpy(this->_name,person._name);
        }
        return *this;
    }

    virtual ~Person() {
        delete [] _name;
    }


private:
    char *_name;
};