#include <iostream>
#include <string>

using namespace std;

// TODO: 补全TimeParser类并实现以下函数
class TimeParser {
private:
    bool isLegal;
    string time;
    int hour;
    int min;
    int sec;

public:
		TimeParser(string s);  // 有参构造函数
		int getHour(); // 返回时
		int getMin(); // 返回分
		int getSec(); // 返回秒
};

// 你可以使用下面的main函数自己测试输入用例
//
// int main() {
//   std::string s;
//   std::cin >> s;
//   TimeParser tp(s);
//
//   std::cout << tp.getHour() << ' ';
//   std::cout << tp.getMin() << ' ';
//   std::cout << tp.getSec() << endl;
//
//   return 0;
// }