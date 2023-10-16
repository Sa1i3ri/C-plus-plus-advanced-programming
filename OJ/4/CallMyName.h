#include <string>
#include <list>
using namespace std;

class CallMyName
{
    void** all_functions;
public:
    CallMyName(void* af[4]){
        all_functions=af;
    }

    int call(const string &my_call)
    {
        // int (*first_function) (int,int) = reinterpret_cast<int (*)(int,int)> (all_functions[0]);
        
        // int (*second_function) (int,int)= reinterpret_cast<int (*)(int,int)> (all_functions[1]);

        // int (*third_function) (int,int)= reinterpret_cast<int (*)(int,int)> (all_functions[2]);

        // int (fourth_function) (int,int,int)= reinterpret_cast<int (*)(int,int,int)> (all_functions[3]);


        string functionName = getFunctionName(my_call);
        int* para = getPara(my_call);
        int (*func1) (int,int);     
        int (*func2) (int,int,int);   

        if(functionName == "funcMyAdd"){
            func1 = reinterpret_cast<int (*)(int,int)>(all_functions[0]);
            return func1(para[0],para[1]);
        }else if (functionName == "funcMySub")
        {
            func1 = reinterpret_cast<int (*)(int,int)>(all_functions[1]);
            return func1(para[0],para[1]);
        }else if(functionName == "funcMyHash"){
            func1 = reinterpret_cast<int (*)(int,int)>(all_functions[2]);
            return func1(para[0],para[1]);
        }else if (functionName == "funcMySum")
        {
            func2 = reinterpret_cast<int (*)(int,int,int)>(all_functions[3]);
            return func2(para[0],para[1],para[2]);
        }
        
        


    }

    string getFunctionName(const string &my_call){
        if(my_call.substr(0,9) == "funcMyHas"){
            return "funcMyHash";
        }else{
            return my_call.substr(0,9);
        }
    }

    int* getPara(const string &my_call){
        int len = my_call.length();
        int indexLeft = 0;
        
        list<int> dou;

        for(int i = 0;i<len;i++){
            if(my_call[i] == '('){
                indexLeft = i;
                for(int j = i;j<len;j++){
                    if(my_call[j]==',' ){
                        dou.push_back(j);
                    }else if(my_call[j]==')'){
                        dou.push_back(j);
                        goto endloop;
                    }
                    
                }
            }


        }

        endloop:

        if(dou.size()==2){
            int *result = (int*)malloc(2 * sizeof(int));
            int firstDou = dou.front();
            dou.pop_front();
            int indexRight = dou.front();
            
            result[0] = atoi(my_call.substr(indexLeft+1,firstDou-indexLeft-1).c_str());
            
            result[1] = atoi(my_call.substr(firstDou+1,indexRight-firstDou-1).c_str());

            return result;
        }else if (dou.size()==3)
        {
            int *result = (int*)malloc(3 * sizeof(int));
            int firstDou = dou.front();
            dou.pop_front();
            int secondDou = dou.front();
            dou.pop_front();
            int indexRight = dou.front();

            result[0] = atoi(my_call.substr(indexLeft+1,firstDou-indexLeft-1).c_str());

            result[1] = atoi(my_call.substr(firstDou+1,secondDou-firstDou-1).c_str());

            result[2] = atoi(my_call.substr(secondDou+1,indexRight-secondDou-1).c_str());

            return result;


        }
        
    }


};
