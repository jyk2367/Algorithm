#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    
    for(long long num:numbers){
        if(num%2==0)
            answer.push_back(num+1);
        else{
            int index=0;
            for(int i=0;i<64;i++){
                if(((num>>i)&1LL)==0){
                    index=i;
                    break;
                }
            }
            answer.push_back(num+(1LL<<(index-1)));
        }
    }
    
    return answer;
}