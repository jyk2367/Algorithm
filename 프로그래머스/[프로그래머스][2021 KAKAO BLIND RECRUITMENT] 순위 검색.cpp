#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;
string language[4]={"-","java","python","cpp"};
string group[3]={"-","backend","frontend"};
string career[3]={"-","junior","senior"};
string soulfood[3]={"-","chicken","pizza"};
vector<vector<int>> perm;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> information[4][3][3][3];
    unordered_map<string,int> lang_hm,group_hm,career_hm,soulfood_hm;
    vector<int> tmp={0,0,0,1};
    do{
        perm.push_back(tmp);
    }while(next_permutation(tmp.begin(),tmp.end()));
    tmp={0,0,1,1};
    do{
        perm.push_back(tmp);
    }while(next_permutation(tmp.begin(),tmp.end()));
    tmp={0,1,1,1};
    do{
        perm.push_back(tmp);
    }while(next_permutation(tmp.begin(),tmp.end()));
    int PMSIZE=perm.size();
    
    for(int i=0;i<4;i++){        lang_hm[language[i]]=i;    }
    for(int i=0;i<3;i++){        group_hm[group[i]]=i;    }
    for(int i=0;i<3;i++){        career_hm[career[i]]=i;    }
    for(int i=0;i<3;i++){        soulfood_hm[soulfood[i]]=i;    }
    
    for(string inf:info){
        istringstream ist(inf);
        string l,g,c,sf,score;
        ist>>l>>g>>c>>sf>>score;
        int sc=stoi(score);
        
        information[lang_hm[l]][group_hm[g]][career_hm[c]][soulfood_hm[sf]].push_back(sc);
        information[0][0][0][0].push_back(sc);
        
        for(int i=0;i<PMSIZE;i++){
            if(perm[i][0]!=0)
                perm[i][0]=lang_hm[l];
            if(perm[i][1]!=0)
                perm[i][1]=group_hm[g];
            if(perm[i][2]!=0)
                perm[i][2]=career_hm[c];
            if(perm[i][3]!=0)
                perm[i][3]=soulfood_hm[sf];
            information[perm[i][0]][perm[i][1]][perm[i][2]][perm[i][3]].push_back(sc);
        }
    }
    
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    sort(information[i][j][k][l].begin(),information[i][j][k][l].end());
                }
            }
        }
    }
    
    
    for(string qry:query){
        int count=0;
        istringstream ist(qry);
        string l,g,c,sf,score,tmp;
        ist>>l>>tmp>>g>>tmp>>c>>tmp>>sf>>score;
        
        count=information[lang_hm[l]][group_hm[g]][career_hm[c]][soulfood_hm[sf]].end()-lower_bound(information[lang_hm[l]][group_hm[g]][career_hm[c]][soulfood_hm[sf]].begin(),information[lang_hm[l]][group_hm[g]][career_hm[c]][soulfood_hm[sf]].end(),stoi(score));
        
        answer.push_back(count);
    }

    return answer;
}