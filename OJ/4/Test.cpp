#include "CallMyName.h"
#include <iostream>
using namespace std;
int funcMyAdd(int a, int b)
{
    return a + b;
}
int funcMySub(int a, int b)
{
    return a - b;
}
int funcMyHash(int a, int b)
{
    return a*b%120;
}
int funcMySum(int a, int b, int c)
{
    return a + b + c;
}
void *functions[4] = {(void *)funcMyAdd, (void *)funcMySub, (void *)funcMyHash, (void *)funcMySum};
int main()
{
    CallMyName call(functions);
    cout << call.call("funcMyAdd(1,2)") << endl;
    cout << call.call("funcMySub(1,2)") << endl;
    cout << call.call("funcMyHash(1,2)") << endl;
    cout << call.call("funcMySum(1,2,3)") << endl;
    return 0;
}