#include <bits/stdc++.h>

using namespace std;
int v[20];
bool number[2000000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += v[j];
            }
        }
        number[sum] = true;
    }
    for (int i = 1; i <= 2000000; i++) {
        if (number[i] != true) {
            cout << i;
            break;
        }
    }
}