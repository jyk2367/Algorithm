#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(')
            st.push(s[i]);
        else{
            if(!st.empty()){
                if(st.top()=='(')
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }
    }
    if(st.size()>0)
        return false;
    return true;
}