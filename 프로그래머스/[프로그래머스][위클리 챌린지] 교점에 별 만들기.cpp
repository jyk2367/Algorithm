#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    int SIZE=line.size();
    long long xleft=0x7fffffffffffffff,xright=0x8000000000000000;
    long long yup=0x8000000000000000,ydown=0x7fffffffffffffff;
    vector<pair<int,int>> points;
    
    for(int i=0;i<SIZE-1;i++){
        for(int j=i;j<SIZE;j++){
            long long AD_BC=line[i][0]*(long long)line[j][1]-line[i][1]*(long long)line[j][0];
            if(AD_BC==0)
                continue;
            long long BF_ED=line[i][1]*(long long)line[j][2]-line[i][2]*(long long)line[j][1];
            long long EC_AF=line[i][2]*(long long)line[j][0]-line[i][0]*(long long)line[j][2];
            if(BF_ED%AD_BC==0&&EC_AF%AD_BC==0){
                int nextx=BF_ED/AD_BC;
                int nexty=EC_AF/AD_BC;
                points.push_back({nextx,nexty});
                
                xleft=(nextx>xleft)?xleft:nextx;
                xright=(nextx>xright)?nextx:xright;

                yup=(nexty>yup)?nexty:yup;
                ydown=(nexty>ydown)?ydown:nexty;
            }
        }
    }
    
    
    for(int j=yup;j>=ydown;j--){
        string tmp;
        for(int i=xleft;i<=xright;i++){
                tmp+='.';
        }
        answer.push_back(tmp);
    }
    for(pair<int,int> p:points){
        answer[yup-p.second][p.first-xleft]='*';
    }
    
    return answer;
}