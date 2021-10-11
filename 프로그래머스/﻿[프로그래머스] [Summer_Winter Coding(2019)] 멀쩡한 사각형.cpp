#include <numeric>
using namespace std;
//최대공약수

long long solution(int w,int h) {
    long long answer = (long long)w*h;
    long long i=gcd(w,h);
    
    answer-=i*(w/i+h/i-1);
    
    return answer;
}