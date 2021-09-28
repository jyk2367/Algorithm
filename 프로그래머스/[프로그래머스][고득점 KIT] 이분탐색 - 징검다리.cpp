#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int RSIZE=rocks.size();
    int left=1;
    int right=distance;
    
    sort(rocks.begin(),rocks.end());
    
    while(left<=right){
        int cnt=0;
        int lastRock=0;
        int mid=(left+right)/2;
        for(int i=0;i<RSIZE;i++){
            if(rocks[i]-lastRock<mid) //rocks[i] 제거
                cnt++;
            else
                lastRock=rocks[i];
        }
        
        if(distance-lastRock<mid)//마지막값 확인
            cnt++;
        
        if(cnt<=n){
            answer=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    
    return answer;
}