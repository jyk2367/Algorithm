#include <bits/stdc++.h>
using namespace std;

int oneCount;
int zeroCount;
int T;

int fibZero[42];
int fibOne[42];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    fibZero[0] = 1;
    fibOne[0] = 0;
    fibZero[1] = 0;
    fibOne[1] = 1;
    for (int i = 2; i <=40; i++) {
        fibZero[i] = fibZero[i - 2] + fibZero[i - 1];
        fibOne[i] = fibOne[i - 2] + fibOne[i - 1];
    }

    cin >> T;
    while (T--) {
        zeroCount = 0;
        oneCount = 0;
        int N;
        cin >> N;
        
        cout << fibZero[N] << " " << fibOne[N] << "\n";
    }
   

	return 0;
}