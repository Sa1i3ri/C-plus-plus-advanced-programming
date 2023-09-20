#include<cstring>
#include<iostream>
using namespace std;

void createNewArr(int arr[] ,int index,int newArr[],int n){
    int j = 0;
    for(int i = 0;i<n;i++){
        if(i==index || i==index+1){
            continue;
        }
        newArr[j] = arr[i];
        j++;
    }
}

string solution(int n,int arr[]){
    if(n==0){
        return "true";
    }
    if(n==1){
        return "false";
    }
    for(int i=0;i<n-1;i++){
        if(arr[i+1]-arr[i]==2){
            int newArr[n-2];
            createNewArr(arr,i,newArr,n);
            return solution(n-2,newArr);
        }
    }
    return "false"; 
}




int main()
{
    int n;
    cin >>n;
    int s[n];
    int i=0;
    for(int i = 0;i<n;i++){
        cin >> s[i];
    }
    // int n = 4;
    // int s[] = {1,2,4,3};

    cout << solution(n,s);

    return 0;
}