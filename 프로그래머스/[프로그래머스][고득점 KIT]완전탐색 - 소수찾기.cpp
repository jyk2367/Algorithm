#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int answer = 0;
vector<char> v;
vector<int> prime;
bool visited[9];
int N;

bool isprime(int num){
    if(num<2)
        return false;
    if(num==2)
        return true;
    for(int i=2;i*i<=num;i++){
        if(num%i==0)
            return false;
    }
    return true;
}


void func(int k,string s){
    if(k==N){
        if(s!=""&&isprime(stoi(s))&&(find(prime.begin(),prime.end(),stoi(s))==prime.end())){
            answer++;
            prime.push_back(stoi(s));
        }
        return;
    }
    for(int i=0;i<v.size();i++){
        if(!visited[i]){
            visited[i]=true;
            func(k+1,s);
            func(k+1,s+v[i]);
            visited[i]=false;
        }
    }
    
}

int solution(string numbers) {
    N=numbers.length();
    for(int i=0;i<N;i++){
        v.push_back(numbers[i]);
    }

    func(0,"");
    
    return answer;
}