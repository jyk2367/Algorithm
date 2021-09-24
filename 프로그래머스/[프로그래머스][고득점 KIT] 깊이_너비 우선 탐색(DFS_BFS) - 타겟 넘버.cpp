#include <string>
#include <vector>
#include <iostream>
using namespace std;
int N,t,cnt;
vector<int> v;

void dfs(int k,int sum){
    if(k==N){
        if(t==sum)
           cnt++; 
        return;
    }
    dfs(k+1,sum+v[k]);
    dfs(k+1,sum-v[k]);
}

int solution(vector<int> numbers, int target) {
    v=numbers;
    t=target;
    N=numbers.size();
    
    dfs(0,0);
    
    return cnt;
}