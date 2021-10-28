#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    int row=relation.size();//tuple 개수
    int col=relation[0].size();//attribute 개수
    bool candidate_key[9]={0,};
    vector<string> cd;
    
    for(int i=1;i<=col;i++){
        vector<int> v(col-i,0);
        v.insert(v.end(),i,1);
        vector<int> cand;
        
        do{
            string comb="";
            bool con=false;
            for(int j=0;j<col;j++){
                if(v[j])
                    comb+=to_string(j);
            }
            for(string s:cd){
                int cnt=s.length();
                for(char c:comb){
                    for(char a:s){
                        if(a==c){
                            cnt--;
                        }
                    }
                }
                
                if(cnt==0){
                    con=true;
                    break;
                }
            }
            if(con)
                continue;
            
            bool state=false;
            unordered_map<string,int> dup;//중복검사용
            for(int k=0;k<row;k++){
                string tmp="";
                for(int l=0;l<comb.length();l++){
                    tmp+=relation[k][comb[l]-'0'];
                }
                
                if(dup.count(tmp)==0){
                    dup[tmp]=true;
                }
                else{
                    state=true;
                    break;
                }
            }
            if(!state){
                cd.push_back(comb);
                answer++;
            }
        }while(next_permutation(v.begin(),v.end()));
    }
    
    
    return answer;
}