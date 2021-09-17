#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    
    for(vector<int>::iterator it=lost.begin();it!=lost.end();){
        vector<int>::iterator current=find(reserve.begin(),reserve.end(),*it);
        if(current!=reserve.end()){
            reserve.erase(current);
            lost.erase(it);
        }
        else{
            it++;
        }
    }
    for(int i:lost){
        vector<int>::iterator forward=find(reserve.begin(),reserve.end(),i-1);
        vector<int>::iterator backward=find(reserve.begin(),reserve.end(),i+1);
        
        if(forward!=reserve.end()){
            reserve.erase(forward);
        }
        else if(backward!=reserve.end()){
            reserve.erase(backward);
        }
        else{
            n--;
        }
    }
    
    return n;
}