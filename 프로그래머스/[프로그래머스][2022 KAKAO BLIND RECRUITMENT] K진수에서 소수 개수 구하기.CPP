#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long num){
    if(num==0)
        return false;
    if(num==1)
        return false;
    for(long long i=2;i*i<=num;i++){
        if(num%i==0)
            return false;
    }
    return true;
}


int solution(int n, int k) {
    long long answer = 0;
    
    vector<int> v;
    while(n!=0){
        v.push_back(n%k);
        n/=k;
    }
    
    string tmp="";
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]!=0){
            tmp+=('0'+v[i]);
        }
        else if(tmp!=""){
            if(isPrime(stoll(tmp))){
                answer++;
            }
            tmp="";
        }
    }
    if(tmp!=""){
         if(isPrime(stoll(tmp)))
             answer++;
    }
    
    return answer;
}