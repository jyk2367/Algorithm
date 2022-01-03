#include <string>
#include <vector>

using namespace std;

int gcd(int x,int y){
    int answer=1;
    int num=2;
    while(num<=x&&num<=y){
        if(x%num==0&&y%num==0){
            x/=num;
            y/=num;
            answer*=num;
        }
        else
            num++;
    }
    
    // 푼 뒤에 찾아본 유클리드 gcd공식
    // while(b!=0){
    //     c=a%b;
    //     a=b;
    //     b=c;
    // }
    
    return answer;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int i=1;i<arr.size();i++){
        answer=(arr[i]*answer)/gcd(arr[i],answer);
    }
    
    return answer;
}