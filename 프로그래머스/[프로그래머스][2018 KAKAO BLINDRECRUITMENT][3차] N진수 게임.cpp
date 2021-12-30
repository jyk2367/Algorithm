#include <string>
#include <vector>

using namespace std;

//진법에 맞는 각 수들 string으로 변환
void make_numtostr(int n,int t,int m,vector<string> &v){
    for(int i=0;i<=t*m;i++){
        int index=i;
        vector<int> vtmp;
        while(1){
            vtmp.push_back(index%n);
            index/=n;
            if(index==0)
                break;
        }
        for(int i=vtmp.size()-1;i>=0;i--){
            if(vtmp[i]>=10){
                string tmp(1,'A'+vtmp[i]-10);
                v.push_back(tmp);
            }
            else
                v.push_back(to_string(vtmp[i]));
        }
    }
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    vector<string> num;
    
    make_numtostr(n,t,m,num);
    
    for(int i=0;i<t*m;i++){//구해야 하는 숫자들
        if(i==p-1){
            answer+=num[i];
            p+=m;
        }
    }
    
    return answer;
}