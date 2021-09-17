#include <iostream>
#include <vector>
using namespace std;

int M, N;
vector<bool> matrix(1000002, true);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> M >> N;
    matrix[1] = false;
    for (int i = 2; i*i <= N; i++) {
        if (!matrix[i])
            continue;
        for (int j = i * i; j <= N; j += i) {
            matrix[j] = false;
        }
    }
    for (int i = M; i <= N; i++) {
        if(matrix[i])
            cout<<i<<"\n";
    }
}