#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    int TSIZE=times.size();
    
    long long left=0;
    long long right=1000000000000000000;
    
    while(left<right){
        long long cnt=0;
        long long mid=(left+right)/2;
        for(int i=0;i<TSIZE;i++){
            cnt+=mid/times[i];
            if(cnt>n)
                break;
        }
        if(cnt<n){
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    answer=left;
    return answer;
}