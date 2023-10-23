#include <iostream>
#include <string>

using namespace std;

class Animals
{
private:
    string name;
    int age;
    string color;
public:
    virtual void makeSound()=0;
};

class Cat : Animals{

public:
void makeSound(){
    cout<< "mewo" << endl;
}


};

class Dog : Animals{

public:
void makeSound(){
    cout<< "wolf" << endl;
}


};
