#include <string>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;
//3가지 연산문자(+,-,*)
//연산자의 우선순위를 자유롭게 재정의해서 가장 큰 숫자만들기
// + > - > *
// - > * > +
// 연산자 2개면 우선순위 조합은 2!
// 연산자 3개면 우선순위 조합은 3!
// 계산결과가 음수면 해당 숫자의 절댓값으로 변환해서 가장 큰 수 선정
// 우승자가 제출한 숫자를 우승상금으로 지급


long long solution(string expression) {
    long long answer = 0;
    int index=0;
    int E_SIZE=expression.length();
    vector<string> op;
    set<string> operand_set;
    
    for(int i=0;i<E_SIZE;i++){
        if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'){
            op.push_back(expression.substr(index,i-index));
            
            string tmp="";
            tmp+=expression[i];
            op.push_back(tmp);
            operand_set.insert(tmp);
            
            index=i+1;
        }
    }
    op.push_back(expression.substr(index));
    
    vector<string> operand_vec(operand_set.begin(),operand_set.end());
    
    do{
        vector<string> optr(op.begin(),op.end());
        index=0;
        long long total=0;
        
        while(index<operand_vec.size()){
            string tmp="";
            tmp+=operand_vec[index];
            while(1){
                vector<string>::iterator it=find(optr.begin(),optr.end(),tmp);
                if(it!=optr.end()){
                    long long result=0;
                    vector<string>::iterator f_num=--it;
                    it++;
                    vector<string>::iterator s_num=++it;
                    it--;

                    if(tmp=="*")
                        result+=stoll(*f_num)*stoll(*s_num);
                    else if(tmp=="+")
                        result+=stoll(*f_num)+stoll(*s_num);
                    else if(tmp=="-")
                        result+=stoll(*f_num)-stoll(*s_num);
                    
                    optr.erase(it,++s_num);
                    *f_num=to_string(result);
                    total=result;
                }
                else
                    break;
            }
            index++;
        }
        answer=max(answer,abs(total));
    }while(next_permutation(operand_vec.begin(),operand_vec.end()));
    
    
    
    return answer;
}