#include<cstring>
#include<iostream>
using namespace std;

// 补充solution函数，参数为题目输入的str1和str2，返回值为所求的小写字母
char solution(const char* str1, const char* str2)
{
    char answer;
    int value[strlen(str1)];
    for(int i = 0;i<strlen(str2);i++){
        int judge = 0;
        for(int j = 0;j<strlen(str1);j++){
            if(str2[i] == str1[j] && value[j]!=1){
                value[j] = 1;
                judge =1;
                break;
            }
        }
        if(judge == 0){
        answer = str2[i];
        break;
        }

    }
    

    return answer;
}

// 我们为你提供了main函数，处理了输入和输出，你只需要关注solution函数
int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;

    
    const char* str1 = s1.c_str();
    const char* str2 = s2.c_str();
    
    cout << solution(str1,str2);

    return 0;
}