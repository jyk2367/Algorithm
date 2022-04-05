class Solution {
private:
    unordered_map<char,int> hm;
    stack<int> st;
    void Init(){
        hm['I']=1;
        hm['V']=5;
        hm['X']=10;
        hm['L']=50;
        hm['C']=100;
        hm['D']=500;
        hm['M']=1000;
    }
public:
    int romanToInt(string s) {
        int sum=0;
        Init();
        st.push(hm[s[0]]);
        for(int i=1;i<s.length();i++){
            if(hm[s[i]]>st.top()){
                int num1=st.top();
                st.pop();
                st.push(hm[s[i]]-num1);
            }
            else
                st.push(hm[s[i]]);
        }
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }   
};
​