#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int origin=n;
    int i=1,m;
    int n_cnt=0;
    
    while(n>0){
        if(n%2==1)
            n_cnt++;
        n/=2;
    }
    
    while(1){
        m=origin+i;
        int m_cnt=0;
        while(m>0){
            if(m%2==1)
                m_cnt++;
            m/=2;
        }

        if(n_cnt==m_cnt)
            break;
        i++;
    }
    
    return origin+i;
}

/*
#include <bitset>

using namespace std;

int solution(int n) {
    int num = bitset<20>(n).count();

    while (bitset<20>(++n).count() != num);
    return n;
}*/