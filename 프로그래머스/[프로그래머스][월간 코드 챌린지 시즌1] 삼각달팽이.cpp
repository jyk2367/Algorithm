#include <string>
#include <iostream>
#include <vector>

using namespace std;
int matrix[500501];
int n_matrix[500501];
int left_sum=1,N,LEN;
int sp=1;
int number=1;

void left(int SIDE_CNT){
    int i,j;
    for(i=0,j=sp;i<SIDE_CNT;i++,j+=n_matrix[j]){
        matrix[j]=number++;
        if(i==SIDE_CNT-1){
            sp=j+1;
            break;
        }
    }
}

void bottom(int SIDE_CNT){
    int i,j;
    for(i=0,j=sp;i<SIDE_CNT;i++,j++){
        matrix[j]=number++;
        if(i==SIDE_CNT-1){
            sp=j-n_matrix[sp];
            break;
        }
    }
}

void right(int SIDE_CNT){
    int i,j;
    for(i=0,j=sp;i<SIDE_CNT;i++,j-=n_matrix[j]){
        matrix[j]=number++;
        if(i==SIDE_CNT-1){
            sp=j+n_matrix[j];
            break;
        }
    }
}


vector<int> solution(int n) {
    vector<int> answer;
    N=n;
    LEN=(N*(N+1))/2;
    
    int TRI_CNT,SIDE_CNT=N;
    
    if(N%3==0)
        TRI_CNT=N/3;
    else
        TRI_CNT=N/3+1;
    
    for(int i=1;i<=LEN;i++){
        for(int j=0;!(j*(j-1)/2<i&&i<=j*(j+1)/2);j++){
            n_matrix[i]=j+1;
        }
    }
    
    while(TRI_CNT-->0){
        left(SIDE_CNT--);
        if(SIDE_CNT==0)
            break;
        bottom(SIDE_CNT--);
        if(SIDE_CNT==0)
            break;
        right(SIDE_CNT--);
        if(SIDE_CNT==0)
            break;
    }
    for(int i=1;i<=LEN;i++){
        answer.push_back(matrix[i]);
    }

    
    return answer;
}