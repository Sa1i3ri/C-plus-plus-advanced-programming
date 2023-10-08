#include "TimeParser.h"

using namespace std;

TimeParser::TimeParser(string s)
{
    if(s[2]!=':' || s[5]!=':'){
        this->isLegal = false;
        return;
    }else{
        this->isLegal = true;
    }
    this->time = s;

    this->hour =stoi(s.substr(0,2),nullptr,10);
    this->min = stoi(s.substr(3,2),nullptr,10);
    this->sec = stoi(s.substr(6,2),nullptr,10);

    if(hour > 23 || hour <0 || min >59 || min<0 || sec >59 || sec <0){
        isLegal = false;
    }


}

int TimeParser::getHour()
{ 
    if(this->isLegal == false){
        return -1;
    }

    return hour;
}

int TimeParser::getMin()
{ 
    if(this->isLegal == false){
        return -1;
    }

    return min;
}

int TimeParser::getSec()
{ 
    if(this->isLegal == false){
        return -1;
    }

    return sec;
}

int main(){
        std::string s1 = "5:6:7";
    TimeParser tp(s1);
    std::cout << tp.getHour() << ' ';    // 返回 10
    std::cout << tp.getMin() << ' ';    // 返回 14
    std::cout << tp.getSec() << endl;    // 返回 1
    std::string s2 = "13:60:60"; // 违反了上述要求，输出-1
    TimeParser tp2(s2);
    std::cout << tp2.getHour() << ' '; // -1
    std::cout << tp2.getMin() << ' '; // -1
    std::cout << tp2.getSec() << endl; // -1
    return 0;
}